#pragma once
#include "Entropy/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Entropy
{
	class WinWindow : public Window
	{
	public:
		WinWindow(const WindowProps& props);
		virtual ~WinWindow();

		virtual void OnUpdate() override;

		inline virtual unsigned int GetWidth() const override;
		inline virtual unsigned int GetHeight() const override;
		
		virtual void SetEventCallback(const EventCallbackFn& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData _data;
	};
}