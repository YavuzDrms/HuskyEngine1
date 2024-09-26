#include "Application.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

namespace Husky
{
	Editor::Editor()
	{
		event_manager.subscribe(startProgramEvent, [this]() {StartProgram(); });
		event_manager.subscribe(endProgramEvent, [this]() {EndProgram(); });
		event_manager.subscribe(createWindowEvent, [this]() {HUSKY_CORE_INFO("Window Created"); });

		event_manager.publish(startProgramEvent);
	}
	Editor::~Editor()
	{
		event_manager.publish(endProgramEvent);
	}
	void Editor::StartProgram()
	{
		HUSKY_CORE_TRACE("Start");
	}
	void Editor::EndProgram()
	{
		HUSKY_CORE_TRACE("End");
	}
	void Editor::Init()
	{
		if (!glfwInit())
		{
			HUSKY_CORE_ERROR("Cant Init GLFW");
			glfwTerminate();
		}

		// Use OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Use modern OpenGL
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(getWidth(), getHeight(), getTitle(), NULL, NULL);
		event_manager.publish(createWindowEvent);

		if (window == NULL)
		{
			HUSKY_CORE_ERROR("Window is NULL");
			glfwTerminate();
		}

		// Introduce the window into the current context
		glfwMakeContextCurrent(window);

		// Load glad and OpenGL
		gladLoadGL();

		// Set the viewport
		// Render area
		glViewport(0, 0, getWidth(), getHeight());
	}
	void Editor::Run()
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(getWindow());
	}
	void Editor::Draw()
	{
		glfwPollEvents();
	}
	void Editor::Close()
	{
		glfwDestroyWindow(getWindow());
		glfwTerminate();
	}
	void Editor::getProperties()
	{
		HUSKY_CORE_INFO("Width: {}", getWidth());
		HUSKY_CORE_INFO("Height: {}",getHeight());
		HUSKY_CORE_INFO("Title: {}", getTitle());
	}
}
