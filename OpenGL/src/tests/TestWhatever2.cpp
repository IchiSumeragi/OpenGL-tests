#include "TestWhatever2.h"
#include "Renderer.h"
#include "imGui/imgui.h"

test::TestWhatever2::TestWhatever2()
	: m_ClearColor{ 0.2f, 0.3f, 0.8f, 1.0f }
{
}

test::TestWhatever2::~TestWhatever2()
{
}

void test::TestWhatever2::OnUpdate(float deltaTime)
{
}

void test::TestWhatever2::OnRender()
{
	GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void test::TestWhatever2::OnImGuiRender()
{
	ImGui::ColorEdit4("Clear color", m_ClearColor);
}

std::string test::TestWhatever2::GetTestName()
{
	std::string s = "TestWhatever2";
	return s;
}