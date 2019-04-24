#include "Renderer.h"
#include <iostream>
#include "VertexBufferLayout.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "OpenGL error " << gluErrorString(error) << " in function " << function << " (file : " << file << ")" << std::endl;
		return false;
	}

	return true;
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer & ib, const Shader & shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(Mesh & m, Shader& shader) const
{
	shader.Bind();
	m.vao.Bind();
	m.ibo.Bind();

	unsigned int diffuse = 1;
	unsigned int specular = 1;

	for (unsigned int i = 0; i < m.textures.size(); i++)
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + i));

		std::string number;
		std::string name = m.textures[i].GetType();

		if (name == "texture_diffuse")
			number = std::to_string(diffuse++);
		else if (name == "texture_specular")
			number = std::to_string(specular++);

		shader.SetUniform1i((name + number).c_str(), i);
		GLCall(glBindTexture(GL_TEXTURE_2D, m.textures[i].GetID()));
	}

	GLCall(glDrawElements(GL_TRIANGLES, m.indices.size(), GL_UNSIGNED_INT, 0));
	
	GLCall(glActiveTexture(GL_TEXTURE0));
	m.vao.Unbind();
}

void Renderer::Draw(Model& m, Shader& shader) const
{
	for (unsigned int i = 0; i < m.meshes.size(); i++)
		Draw(m.meshes[i], shader);
}