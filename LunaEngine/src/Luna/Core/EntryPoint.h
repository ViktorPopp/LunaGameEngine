#ifndef _LUNA_ENTRY_POINT_
#define _LUNA_ENTRY_POINT_
#include <iostream>

#include "../../LunaEngine.h"

#ifdef LUNA_PLATFORM_WINDOWS

extern luna::Application* luna::CreateApplication();

int main(int argc, char** argv[])
{
	auto application = luna::CreateApplication();
	return application->Run();
}

#endif // LUNA_PLATFORM_WINDOWS

#endif // _LUNA_ENTRY_POINT_