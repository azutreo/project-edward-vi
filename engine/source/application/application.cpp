#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "application/application.hpp"

#include "windows/window_opengl.hpp"
#include "events/event_application_updated.hpp"

namespace Engine {

	Application::Application() {
		mWindow = new Engine::Windows::OpenGlWindow();

		mWindow->SetWindowClosedCallback([&]() {
			mRunning = false;
		});
		mWindow->SetWindowResizedCallback([&](int width, int height) {

		});
		mWindow->SetKeyPressedCallback([&](int key) {

		});
		mWindow->SetKeyReleasedCallback([&](int key) {

		});
		mWindow->SetKeyRepeatedCallback([&](int key) {

		});
		mWindow->SetMouseButtonPressedCallback([&](int button) {

		});
		mWindow->SetMouseButtonReleasedCallback([&](int button) {

		});
		mWindow->SetMouseMovedCallback([&](double x, double y) {

		});
		mWindow->SetMouseScrolledCallback([&](double x, double y) {

		});
	}

	Application::~Application() {
		delete mWindow;
	}

	void Application::Run() {
		while(mRunning) {
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - mRunningTime);
			double deltaTime = duration.count() * 1e-6;

			mWindow->Update();
			Updated.Fire(deltaTime);

			mRunningTime = end;
		}
	}

};