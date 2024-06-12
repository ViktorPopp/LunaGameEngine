#include "LunaEngine.h"
#include "Luna/Core/EntryPoint.h"

class Sandbox : public luna::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

luna::Application* luna::CreateApplication() {
	return new Sandbox();
}