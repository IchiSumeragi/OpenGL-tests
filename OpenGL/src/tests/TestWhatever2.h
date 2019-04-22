#pragma once

#include "Test.h"

namespace test
{
	class TestWhatever2 : public Test
	{
	public:
		TestWhatever2();
		~TestWhatever2();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
		std::string GetTestName() override;
	private:
		float m_ClearColor[4];
	};
}