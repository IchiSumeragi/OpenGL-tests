#include "TestWhatever.h"
#include "Renderer.h"
#include "imGui/imgui.h"

test::TestWhatever::TestWhatever()
	: m_ClearColor{ 0.2f, 0.3f, 0.8f, 1.0f }
{
}

test::TestWhatever::~TestWhatever()
{
}

void test::TestWhatever::OnUpdate(float deltaTime)
{
}

void test::TestWhatever::OnRender()
{
	GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void test::TestWhatever::OnImGuiRender()
{
	ImGui::ColorEdit4("Clear color", m_ClearColor);
}

std::string test::TestWhatever::GetTestName()
{
	std::string s = "TestWhatever";
	return s;
}