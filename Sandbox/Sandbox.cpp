#include "LunaEngine.h"

void SandboxFunc();

class Sandbox : public luna::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

luna::Application* luna::CreateApplication() {
	SandboxFunc();
	return new Sandbox();
}

void SandboxFunc() {
}