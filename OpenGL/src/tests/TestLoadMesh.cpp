#include "TestLoadMesh.h"
#include "Renderer.h"
#include "imGui/imgui.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

test::TestLoadMesh::TestLoadMesh() :
	shader("res/shaders/Basic.shader"), nanosuit("res/meshes/nanosuit/nanosuit.obj"), renderer()
{
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);

	for (unsigned int i = 0; i < nanosuit.meshes.size(); i++)
	{
		nanosuit.meshes[i]->vao.AddBuffer(nanosuit.meshes[i]->vbo, layout);
		//nanosuit.meshes[i]->ibo = IndexBuffer(nanosuit.meshes[i]->indices.data(), nanosuit.meshes[i]->indices.size());
	}

	shader.Bind();
}

test::TestLoadMesh::~TestLoadMesh()
{
}

void test::TestLoadMesh::OnUpdate(float deltaTime)
{
	glEnable(GL_DEPTH_TEST);

	//glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1000.0f, 1000.0f);
	glm::mat4 proj = glm::perspective(90.0f, 960.0f/540.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.75f, -1.0f));

	model = glm::scale(model, glm::vec3(scale, scale, scale));
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 mvp = proj * view * model;

	shader.SetUniformMat4f("u_MVP", mvp);
	renderer.Draw(nanosuit, shader);
}

void test::TestLoadMesh::OnRender()
{
}

void test::TestLoadMesh::OnImGuiRender()
{
	ImGui::SliderFloat("Rotation : ", &rotation, -10.0f, 10.0f);
	ImGui::SliderFloat("Scale : ", &scale, 0.0f, 1.0f);
}