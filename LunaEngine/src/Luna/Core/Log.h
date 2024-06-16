#ifndef _LUNA_LOG_
#define _LUNA_LOG_

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace luna {
	class LUNA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_GameLogger;
	};

}

// Engine logger macros ---------------------------------------------------------
#define LUNA_ENGINE_TRACE(...)  ::luna::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LUNA_ENGINE_INFO(...)   ::luna::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LUNA_ENGINE_WARN(...)   ::luna::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LUNA_ENGINE_ERROR(...)  ::luna::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LUNA_ENGINE_FATAL(...)  ::luna::Log::GetEngineLogger()->fatal(__VA_ARGS__)


// Game logger macros -----------------------------------------------------------
#define LUNA_TRACE(...)         ::luna::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LUNA_INFO(...)          ::luna::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LUNA_WARN(...)          ::luna::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LUNA_ERROR(...)         ::luna::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LUNA_FATAL(...)         ::luna::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#endif // _LUNA_LOG_