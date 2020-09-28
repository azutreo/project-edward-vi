#pragma once

namespace Engine::Renderer {

	class OpenGlShader {

		uint32_t mRendererId = 0;

	public:

		OpenGlShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGlShader();

		void Bind();
		void Unbind();

	};

}