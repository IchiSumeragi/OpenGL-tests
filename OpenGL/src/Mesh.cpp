#include "Mesh.h"
#include "VertexBufferLayout.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
	: vertices(std::move(vertices)), indices(std::move(indices)), textures(std::move(textures)), vao(),
	vbo(Mesh::vertices.data(), Mesh::vertices.size() * sizeof(Vertex)), ibo(Mesh::indices.data(), Mesh::indices.size())
{
}

//Mesh::Mesh(Mesh &&other)
//{
//	vertices = other.vertices;
//	indices = other.indices;
//	textures = other.textures;
//
//	vao = other.vao;
//	vbo = other.vbo;
//	ibo = other.ibo;
//}
//
//Mesh & Mesh::operator=(Mesh && other)
//{
//	if (this != &other)
//	{
//		Release();
//
//		vertices = other.vertices;
//		other.vertices.erase(vertices.begin(), vertices.end());
//
//		indices = other.indices;
//		other.indices.erase(indices.begin(), indices.end());
//
//		textures = other.textures;
//		other.textures.erase(textures.begin(), textures.end());
//	}
//
//	return *this;
//}
//
//void Mesh::Release()
//{
//	vertices.erase(vertices.begin(), vertices.end());
//	vertices.shrink_to_fit();
//
//	vertices.erase(vertices.begin(), vertices.end());
//	vertices.shrink_to_fit();
//
//	vertices.erase(vertices.begin(), vertices.end());
//	vertices.shrink_to_fit();
//}

Mesh::~Mesh()
{
}