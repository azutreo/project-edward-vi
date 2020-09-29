#pragma once

namespace Engine::Rendering {

	class GraphicsContext {
		void* mWindow = nullptr;

	public:
		virtual ~GraphicsContext() = default;

		virtual void SwapBuffers() = 0;
	};

}