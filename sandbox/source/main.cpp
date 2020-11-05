#include "precompiled/precompiled.hpp"

#include "client.hpp"

int main(int argc, char** argv) {
	Engine::Client client;

	/*client.GetWindow()->windowUpdatedEvent.Connect([](double detaTime) {
		std::cout << "Updated" << std::endl;

		return false;
	});*/

	client.Run();

	return 0;
}