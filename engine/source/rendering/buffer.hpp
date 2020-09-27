#pragma once

namespace Engine::Renderer {

	struct Buffer {

		virtual ~Buffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

	};

}