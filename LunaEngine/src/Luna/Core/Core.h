#ifndef _LUNA_CORE_
#define _LUNA_CORE_

#ifdef LUNA_PLATFORM_WINDOWS

	#ifdef LUNA_BUILD_DLL
		#define LUNA_API _declspec(dllexport)
	#else
		#define LUNA_API _declspec(dllimport)
	#endif // LUNA_BUILD_DLL
#else
	#error The Luna Game Engine only supports windows
#endif // LUNA_PLATFORM_WINDOWS

#endif // _LUNA_CORE_