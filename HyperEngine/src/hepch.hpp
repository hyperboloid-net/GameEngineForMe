#pragma once

#include "HyperEngine/Core/PlatformDetection.hpp"

#ifdef HE_PLATFORM_MACOS
    #include <_types/_uint32_t.h>
    #include <sys/signal.h>
#endif

#ifdef HE_PLATFORM_WINDOWS
    #include <Windows.h>
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
#endif

#ifdef HE_PLATFORM_LINUX
    #include <signal.h>
#endif

#include <iostream>
#include <sstream>
#include <csignal>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "HyperEngine/Core/Base.hpp"
#include "HyperEngine/Core/Log.hpp"
