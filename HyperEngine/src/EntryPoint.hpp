#pragma once

#include "Application.hpp"
#include "src/Log.hpp"

extern HyperEngine::Application* HyperEngine::CreateApplication();


int main(int argc, char ** argv)
{
    HyperEngine::Log::Init();
    HE_CORE_INFO("Core Log has been started !");
    int a = 66;
    HE_WARN("Client Log has been started ! {}", a);

    auto app = HyperEngine::CreateApplication();
    app -> Run();
    delete app;
    return 0;
}