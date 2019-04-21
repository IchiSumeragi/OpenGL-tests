#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

float x = 0.0f;
float y = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void go_left();
void go_right();
void go_up();
void go_down();

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
		//float positions[] =
		//{
		//	-50.0f, -50.0f, 0.0f, 0.0f,
		//	 50.0f, -50.0f, 1.0f, 0.0f,
		//	 50.0f,  50.0f, 1.0f, 1.0f,
		//	-50.0f,  50.0f, 0.0f, 1.0f
		//};

		//unsigned int indices[] =
		//{
		//	0, 1, 2,
		//	2, 3, 0
		//};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//VertexArray va;
		//VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		//VertexBufferLayout layout;

		//layout.Push<float>(2);
		//layout.Push<float>(2);
		//va.AddBuffer(vb, layout);

		//GLCall(glEnableVertexAttribArray(0));

		//index 0, taille 2 (éléments), type float, pas de normalisation, stride (écart entre deux éléments) TAILLE DU VERTEX COMPLET, 
		//pointeur vers l'attribut (en bytes) -> byte de départ de l'attribut en question
		//à définir pour chaque élément du buffer
		//GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

		/*IndexBuffer ib(indices, 6);

		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0.0f));

		glm::mat4 mvp = proj * view * model;

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", mvp);

		Texture texture("res/textures/logo.png");
		texture.Bind();*/

		//shader.SetUniform1i("u_Texture", 0);

		//va.Unbind();
		//vb.Unbind();
		//ib.Unbind();
		//shader.Unbind();

		//float r = 0.0f;
		//float increment = 0.005f;

		Renderer renderer;

		//glfwSetKeyCallback(window, key_callback);

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		test::TestClearColor test;

		//glm::vec3 translationA(200, 200, 0.0f);
		//glm::vec3 translationB(400, 200, 0.0f);

		while (!glfwWindowShouldClose(window))
		{
			//view = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
			//model = glm::translate(glm::mat4(1.0f), translationA);
			//mvp = proj * view * model;

			renderer.Clear();

			test.OnUpdate(0.0f);
			test.OnRender();

			ImGui_ImplGlfwGL3_NewFrame();
			test.OnImGuiRender();

			//{
			//	model = glm::translate(glm::mat4(1.0f), translationA);
			//	mvp = proj * view * model;
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_MVP", mvp);

			//	renderer.Draw(va, ib, shader);
			//}

			//{
			//	model = glm::translate(glm::mat4(1.0f), translationB);
			//	mvp = proj * view * model;
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_MVP", mvp);

			//	renderer.Draw(va, ib, shader);
			//}

			//if (r > 1.0f)
			//	increment = -0.005f;
			//else if (r < 0.0f)
			//	increment = 0.005f;

			//r += increment;

			//{
			//	ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);
			//	ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);

			//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			//}

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);

			glfwPollEvents();
		}
	}

	glfwTerminate();

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_A && action == GLFW_REPEAT)
	{
		go_left();
	}

	if (key == GLFW_KEY_D && action == GLFW_REPEAT)
	{
		go_right();
	}

	if (key == GLFW_KEY_W && action == GLFW_REPEAT)
	{
		go_up();
	}

	if (key == GLFW_KEY_S && action == GLFW_REPEAT)
	{
		go_down();
	}
}

void go_left()
{
	std::cout << "Going left" << std::endl;
	x += 10.0f;
}

void go_right()
{
	x -= 10.0f;
}

void go_up()
{
	y -= 10.0f;
}

void go_down()
{
	y += 10.0f;
}