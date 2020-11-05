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

	std::bind<bool>(&Class::OnEvent, this, std::placeholders::_1)
	std::bind<bool>(OnEvent, std::placeholders::_1)
*/

namespace Engine {

	class Event {
		std::string mName;
		using Function = std::function<bool()>; // If there are arguments, put them in the ()
		std::vector<Function> mConnections;

	public:
		Event(std::string name = "Event");
		virtual ~Event() = default;

		inline const std::string& GetName() const { return mName; };

		void Fire(); // If there are arguments, put them in the ()

		void Connect(const Function& function);
		void Disconnect(const Function& function);

		friend std::ostream& operator<<(std::ostream& ostream, const Event& event);
	};

}