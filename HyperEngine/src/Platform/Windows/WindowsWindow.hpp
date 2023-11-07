#pragma once

#include "HyperEngine/src/Core/Window.hpp"
#include <GLFW/glfw3.h>

namespace HyperEngine
{
    class WindowsWindow: public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        // void OnUpdate() override;

        uint32_t GetWidth()  const override;
        uint32_t GetHeight() const override;
    };
}