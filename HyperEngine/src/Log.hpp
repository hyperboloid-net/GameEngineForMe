#pragma once

#include <memory>
#include "Core.hpp"
#include "spdlog/spdlog.h"

// core log macros
#define HE_CORE_TRACE(...)      ::HyperEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HE_CORE_INFO(...)       ::HyperEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_WARN(...)       ::HyperEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_ERROR(...)      ::HyperEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_FATAL(...)      ::HyperEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// client log macros
#define HE_TRACE(...)           ::HyperEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HE_INFO(...)            ::HyperEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HE_WARN(...)            ::HyperEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HE_ERROR(...)           ::HyperEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HE_FATAL(...)           ::HyperEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


namespace HyperEngine
{
    class Log
    {
    public:
        Log();
        ~Log();

        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; } 
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; } 
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}
