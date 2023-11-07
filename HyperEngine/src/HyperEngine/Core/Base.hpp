#pragma once

#include "HyperEngine/src/hepch.hpp"
#include "PlatformDetection.hpp"
#include "Log.hpp"



#define BIT(x) (1 << x)

#define HE_DEBUG

#ifdef HE_DEBUG
    #define HE_ENABLE_ASSERTS
    #ifdef HE_PLATFORM_MACOS
        #define HE_DEBUGBREAK() ::std::raise(SIGTRAP)
    #elifdef HE_PLATFORM_WINDOWS
        #define HE_DEBUGBREAK() __debugbreak()
    #elifdef HE_PLATFORM_LINUX
        #define HE_DEBUGBREAK() ::std::raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
#else
    #define HE_DEBUGBREAK()
#endif

#define HE_EXPAND_MACRO(x) x
#define HE_STRINGIFY_MACRO(x) #x

#define HE_BIND_EVENT_FN(fn) [this](auto&& ... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>args...); }

namespace HyperEngine
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}