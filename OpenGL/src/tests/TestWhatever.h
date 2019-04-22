#pragma once

#include "Test.h"

namespace test
{
	class TestWhatever : public Test
	{
	public:
		TestWhatever();
		~TestWhatever();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
		std::string GetTestName() override;
	private:
		float m_ClearColor[4];
	};
}