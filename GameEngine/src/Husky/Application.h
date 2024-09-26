#ifndef APPLICATION_H
#define APPLICATION_H

#include "console/Log.h"
#include "events/EventSystem.h"

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace Husky
{
	class Editor
	{
	public:		
		Editor();
		virtual ~Editor();

		int getWidth() { return width; }
		int getHeight() { return height; }
		const char* getTitle() { return title; }
		GLFWwindow* getWindow() { return window; }
		EventManager getEventManager() { return event_manager; }

		bool getWindowShouldClose() { return glfwWindowShouldClose(getWindow()); }
		void setWindowShouldClose(bool shouldClose)
		{
			glfwSetWindowShouldClose(getWindow(), (int)shouldClose);
		}

		void setWidth(int w) { this->width = w; }
		void setHeight(int h) { this->height = h; }
		void setTitle(const char* t) { this->title = t; }

		void Init(); // Init opengl
		void Run(); // Start loop
		void Draw(); // End loop
		void Close(); // Close window

		// For Events
		void StartProgram();
		void EndProgram();

		// Get editor's settings
		void getProperties();

	private:
		int width, height;
		const char* title;
		GLFWwindow* window;

		EventManager event_manager;

		// Events

		// Window Events
		std::string createWindowEvent = "CreateWindowEvent";

		// Program Events
		std::string endProgramEvent = "EndProgramEvent";
		std::string startProgramEvent = "StartProgramEvent";
	 };
}

#endif // APPLICATION_H