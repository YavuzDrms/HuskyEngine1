#include "Husky.h"

#include <iostream>   

int main()
{
	Husky::Log::Init();

	std::shared_ptr<Husky::Editor> editor = std::make_shared<Husky::Editor>();

	editor->setWidth(600);
	editor->setHeight(600);
	editor->setTitle("Husky");

	editor->getProperties();

	editor->Init();

	while (!editor->getWindowShouldClose())
	{
		editor->Run();
		 
		// When press ESC, close program
		if (glfwGetKey(editor->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			editor->setWindowShouldClose(true);

		editor->Draw();
	}

	editor->Close();

	return 0;
}
