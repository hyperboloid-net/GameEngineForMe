#include "Window.hpp"
#include "Assert.hpp"
#include "Base.hpp"

#ifdef HE_PLATFORM_MACOS
    #include "Platform/MacOS/MacOSWindow.hpp"
#elifdef HE_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.hpp"
#elifdef HE_PLATFORM_LINUX
    #include "Platform/Windows/LinuxWindow.hpp"
#endif
namespace HyperEngine
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        #ifdef HE_PLATFORM_MACOS
            HE_CORE_ASSERT(false, "Create Window success! suppurted MacOS platform !")
            return CreateScope<MacOSWindow>(props);
        #else
            std::cout << "hello other platform" << std::endl;
            HE_CORE_ASSERT(false, "Create Window fail, not suppurted platform !")
            return nullptr;
        #endif
    }
}