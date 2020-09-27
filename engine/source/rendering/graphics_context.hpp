#pragma once

namespace Engine::Renderer {

	class GraphicsContext {

		void* mWindow;

	public:

		GraphicsContext() = default;
		virtual ~GraphicsContext() = default;

		virtual void SwapBuffers() = 0;

	};

}