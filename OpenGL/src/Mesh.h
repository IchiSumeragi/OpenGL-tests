#pragma once
#include "glm/glm.hpp"
#include "Texture.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include <vector>
#include <memory>

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	//Mesh(Mesh && other);
	//Mesh &operator=(Mesh &&other);
	//void Release();
	~Mesh();
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	VertexArray vao;
	VertexBuffer vbo;
	IndexBuffer ibo;
private:
};