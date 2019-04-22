#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <typeinfo>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw_gl3.h"

#include "tests/TestClearColor.h"
#include "tests/TestWhatever.h"
#include "tests/TestWhatever2.h"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(960, 540, "OpenGL", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error initializing GLEW !" << std::endl;

	std::cout << "OPENGL VERSION : " << glGetString(GL_VERSION) << std::endl;

	{
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		Renderer renderer;

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		test::Test* currentTest = new test::Test();
		test::TestClearColor* testClearColor = new test::TestClearColor();

		test::TestWhatever* testClearColor2 = new test::TestWhatever();
		test::TestWhatever2* testClearColor3 = new test::TestWhatever2();

		std::vector<test::Test*> allTests;
		allTests.push_back(testClearColor);
		allTests.push_back(testClearColor2);
		allTests.push_back(testClearColor3);

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			currentTest->OnUpdate(0.0f);
			currentTest->OnRender();

			ImGui_ImplGlfwGL3_NewFrame();

			ImGui::TextColored(ImVec4(0, 1, 1, 1), "Tests");
			ImGui::BeginChild("Scrolling", ImVec2(0, allTests.size() * 25));
			for (test::Test *t : allTests)
				if (ImGui::Button(t->GetTestName().c_str()))
					currentTest = t;
			ImGui::EndChild();

			currentTest->OnImGuiRender();

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);

			glfwPollEvents();
		}
	}

	glfwTerminate();

	return 0;

}