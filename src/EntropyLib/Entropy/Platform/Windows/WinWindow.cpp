#include "EPCH.h"
#include "WinWindow.h"

#include "Entropy/Tools/Log.h"
#include "Entropy/Events/ApplicationEvents.h"
#include "Entropy/Events/KeyEvent.h"
#include "Entropy/Events/MouseEvent.h"

static bool GLFWInitalized = false;

static void GLFWErrorCallback(int error, const char* description)
{
    Entropy::LOG::Error("GLFW", error, description);
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
    return _data.Width;
}

unsigned int Entropy::WinWindow::GetHeight() const
{
    return _data.Height;
}

void Entropy::WinWindow::SetEventCallback(const EventCallbackFn& callback)
{
    _data.EventCallback = callback;
}

void Entropy::WinWindow::SetVSync(bool enabled)
{
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
    _data.VSync = enabled;
}

bool Entropy::WinWindow::IsVSync() const
{
    return _data.VSync;
}

void Entropy::WinWindow::Init(const WindowProps& props)
{
    _data.Title = props.Title;
    _data.Width = props.Width;
    _data.Height = props.Height;

    //Initalize GLFW
    Entropy::LOG::Message("WINDOW", "Inializing GLFW!");
    if (!GLFWInitalized)
    {
        if (!glfwInit())
            Entropy::LOG::Error("WINDOW", "Could not initalize GLFW!");
        glfwSetErrorCallback(GLFWErrorCallback);
        GLFWInitalized = true;
    }

    //Create Window
    Entropy::LOG::Message("WINDOW", std::string("Createing Window: " + props.Title + " (" + std::to_string(props.Width) + "," + std::to_string(props.Height) + ")").c_str());
    window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
    if (window == NULL)
        Entropy::LOG::Error("WINDOW", "Failed to create GLFW Window");
    glfwMakeContextCurrent(window);

    // Inialize GLAD
    Entropy::LOG::Message("WINDOW", "Inializing GLAD!");
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        Entropy::LOG::Error("WINDOW", "Failed to initalize GLAD!");

    // Set Window Data Pointer
    Entropy::LOG::Message("WINDOW", "Set Window Data Pointer!");
    glfwSetWindowUserPointer(window, &_data);
    SetVSync(true);

    // Set GLFW Callbacks
    Entropy::LOG::Message("WINDOW", "Set Window Resize Callback!");
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

    Entropy::LOG::Message("WINDOW", "Set Window Close Callback!");
    glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data.EventCallback(event);
        });

    Entropy::LOG::Message("WINDOW", "Set Window Key Callback!");
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

    Entropy::LOG::Message("WINDOW", "Set Window Mouse Button Callback!");
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

    Entropy::LOG::Message("WINDOW", "Set Window Scroll Callback!");
    glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset,(float)yOffset);
            data.EventCallback(event);
        });

    Entropy::LOG::Message("WINDOW", "Set Window Cursor Position Callback!");
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
