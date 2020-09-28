#pragma once

/*
	=============
	EXAMPLE USAGE
	=============

	ProjectGE::Event testEvent("Nicholas Died");

	testEvent.Connect([&]() {
		// Do stuff here.
	});

	testEvent.Fire();

	=============
	EXAMPLE USAGE
	=============
*/

namespace Engine::Events {

	class Event {

		std::string mName;
		using Function = std::function<bool()>; // If there are arguments, put them in the ()
		std::vector<Function> mConnections;

	public:

		Event(std::string name = "Event");
		virtual ~Event() = default;

		inline std::string GetName() const { return mName; };

		virtual void Fire(); // If there are arguments, put them in the ()

		virtual void Connect(const Function& function);
		virtual void Disconnect(const Function& function);

		friend std::ostream& operator<<(std::ostream& ostream, const Event& event);
	};

}