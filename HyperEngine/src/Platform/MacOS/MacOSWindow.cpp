#include "MacOSWindow.hpp"
#include "HyperEngine/Core/Assert.hpp"


namespace HyperEngine
{
    MacOSWindow::MacOSWindow(const WindowProps& props): m_Data(props)
    {
        Init();
    };

    MacOSWindow::~MacOSWindow()
    {
        ShutDown();
    };

    void MacOSWindow::Init()
    {
        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
        if (!m_Window)
        {
            HE_CORE_ASSERT(false, "Window has been create !!!");
            HE_CORE_INFO("Window {} has been created", "0x123123");
        }
    };

    void MacOSWindow::ShutDown()
    {
        glfwDestroyWindow(m_Window);
        HE_CORE_INFO("Window has been corrent destory");
    };
}