#pragma once
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
	Model(std::string path)
	{
		loadModel(path);
	}

	std::vector<Mesh*> meshes;
private:
	std::string directory;

	void loadModel(std::string& path);
	void processNode(aiNode *node, const aiScene *scene);
	void processMesh(aiMesh * mesh, const aiScene * scene, std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, std::vector<Texture>& textures);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};