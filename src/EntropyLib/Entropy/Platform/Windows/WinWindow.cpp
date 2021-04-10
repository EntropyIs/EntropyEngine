#include "ecpch.h"
#include "WinWindow.h"

#include "Entropy/Tools/Log.h"

static bool GLFWInitalized = false;

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
        GLFWInitalized = true;
    }

    window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, &data);
    SetVSync(true);
}

void Entropy::WinWindow::Shutdown()
{
    glfwDestroyWindow(window);
}
