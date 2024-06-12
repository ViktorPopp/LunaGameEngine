#ifndef _LUNA_APPLICATION_
#define _LUNA_APPLICATION_

#include "Core.h"

namespace luna {
	class LUNA_API Application
	{
	public:
		Application() {}

		int Run();
	};

	// To be defined by client
	luna::Application* CreateApplication();

}

#endif // _LUNA_APPLICATION_