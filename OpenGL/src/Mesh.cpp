#include "Mesh.h"
#include "VertexBufferLayout.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
	: vertices(std::move(vertices)), indices(std::move(indices)), textures(std::move(textures)), vao(),
	vbo(&vertices, vertices.size() * sizeof(Vertex)), ibo(indices.data(), indices.size() * sizeof(unsigned int))
{
}

Mesh::~Mesh()
{
}