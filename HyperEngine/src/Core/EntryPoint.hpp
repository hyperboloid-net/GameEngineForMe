#pragma once

#include "Application.hpp"
#include "HyperEngine.hpp"
#include "src/Core/Log.hpp"
#include "src/Events/ApplicationEvent.hpp"
#include "src/Events/KeyEvent.hpp"
#include "src/Events/MouseEvent.hpp"

extern HyperEngine::Application* HyperEngine::CreateApplication();


int main(int argc, char ** argv)
{
    HyperEngine::Log::Init();
    HE_CORE_INFO("Core Log has been started !");
    int a = 66;
    HE_WARN("Client Log has been started ! {}", a);
    auto const appEvent = HyperEngine::WindowResizeEvent(1024, 968);
    HE_INFO(appEvent);
    auto const mouseEvent = HyperEngine::MouseMovedEvent(1.13, 1.22);
    HE_CORE_ERROR(mouseEvent);
    auto const keyEvent = HyperEngine::KeyTypedEvent(32);
    HE_INFO(keyEvent);

    auto app = HyperEngine::CreateApplication();
    app -> Run();
    delete app;
    return 0;
}