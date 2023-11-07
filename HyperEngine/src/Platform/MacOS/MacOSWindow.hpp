#pragma once

#include "HyperEngine/src/hepch.hpp"
#include "HyperEngine/Core/Window.hpp"
#include "HyperEngine/Core/Base.hpp"
#include "HyperEngine/Events/Event.hpp"

#include <GLFW/glfw3.h>

namespace HyperEngine
{
    class MacOSWindow: public Window
    {
    public:
        MacOSWindow(const WindowProps& props);
        virtual ~MacOSWindow();

        // void OnUpdate() override;
        // virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        // virtual void SetVSync(bool enabled) = 0;
        // virtual bool IsVSync() const  = 0;

        // virtual void* GetNativeWindow() const = 0;

        uint32_t GetWidth()  const override { return m_Data.Width; };
        uint32_t GetHeight() const override { return m_Data.Height; };
    private:
        void Init();
        void ShutDown();

        WindowProps m_Data;
        GLFWwindow* m_Window = nullptr;
    };
}