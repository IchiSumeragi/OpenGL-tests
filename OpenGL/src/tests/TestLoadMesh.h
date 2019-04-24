#pragma once

#include "Test.h"
#include "Shader.h"
#include "Model.h"
#include "Renderer.h"

namespace test
{
	class TestLoadMesh : public Test
	{
	public:
		TestLoadMesh();
		~TestLoadMesh();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		Shader shader;
		Model nanosuit;
		Renderer renderer;
	};
}