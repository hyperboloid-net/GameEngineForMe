#include "HyperEngine.hpp"
// #include <HyperEngine>

class SandBox : public HyperEngine::Application
{
public:
    SandBox()
    {

    }

    ~SandBox()
    {

    }
}; 

HyperEngine::Application* HyperEngine::CreateApplication()
{
    return new SandBox();
}
