#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab06_4/Lab06_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6
{
	TEST_CLASS(UnitTest6)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double array[] = {1.2,4,5};
			double t;
			t = P(array, 13, 0, 0, 0);
			Assert::AreEqual(t, 1.2);
		}
	};
}
