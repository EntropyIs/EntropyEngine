#include "ecpch.h"
#include "WinWindow.h"

#include "Entropy/Tools/Log.h"
#include "Entropy/Events/ApplicationEvents.h"
#include "Entropy/Events/KeyEvent.h"
#include "Entropy/Events/MouseEvent.h"

static bool GLFWInitalized = false;

static void GLFWErrorCallback(int error, const char* description)
{
    Entropy::log::error("GLFW", error, description);
}

Entropy::Window* Entropy::Window::Create(const WindowProps& props)
{
    return new WinWindow(props);
}

Entropy::WinWindow::WinWindow(const WindowProps& props)
{
    Init(props);
}

Entropy::WinWindow::~WinWindow()
{
    Shutdown();
}

void Entropy::WinWindow::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

inline unsigned int Entropy::WinWindow::GetWidth() const
{
    return data.Width;
}

unsigned int Entropy::WinWindow::GetHeight() const
{
    return data.Height;
}

void Entropy::WinWindow::SetEventCallback(const EventCallbackFn& callback)
{
    data.EventCallback = callback;
}

void Entropy::WinWindow::SetVSync(bool enabled)
{
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
    data.VSync = enabled;
}

bool Entropy::WinWindow::IsVSync() const
{
    return data.VSync;
}

void Entropy::WinWindow::Init(const WindowProps& props)
{
    Entropy::log::message(std::string("Createing window " + props.Title + " (" + std::to_string(props.Width) + "," + std::to_string(props.Height) + ")").c_str());

    data.Title = props.Title;
    data.Width = props.Width;
    data.Height = props.Height;

    if (!GLFWInitalized)
    {
        if (!glfwInit())
            Entropy::log::error("Could not initalize GLFW!");
        glfwSetErrorCallback(GLFWErrorCallback);
        GLFWInitalized = true;
    }

    window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, &data);
    SetVSync(true);

    // Set GLFW Callbacks
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

    glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data.EventCallback(event);
        });

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

    glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset,(float)yOffset);
            data.EventCallback(event);
        });

    glfwSetCursorPosCallback(window, [](GLFWwindow * window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
}

void Entropy::WinWindow::Shutdown()
{
    glfwDestroyWindow(window);
}
