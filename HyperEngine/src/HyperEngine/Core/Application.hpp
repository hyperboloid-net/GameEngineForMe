#pragma once

namespace HyperEngine
{
    class Application
    {
    public:
        Application();
        virtual  ~Application();
        void Run();
    };

    Application* CreateApplication();
}