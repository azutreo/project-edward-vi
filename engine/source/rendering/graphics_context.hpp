#pragma once

namespace Engine {

	class GraphicsContext {
		void* mWindow = nullptr;

	public:
		virtual ~GraphicsContext() = default;

		virtual void SwapBuffers() = 0;
	};

}