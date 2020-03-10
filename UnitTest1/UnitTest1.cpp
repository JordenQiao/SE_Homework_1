#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework_1/function.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// 测试平行直线
			Function function;
			int ret = function.Solve("input1.txt", "output.txt");
			Assert::AreEqual(ret, 2);
		}
		TEST_METHOD(TestMethod2) 
		{
			Function function;
			// 测竖直水平线
			int ret = function.Solve("input2.txt", "output.txt");
			Assert::AreEqual(ret, 3);
		}

		TEST_METHOD(TestMethod3)
		{
			Function function;
			// 测试一条直线
			int ret = function.Solve("input3.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethod4)
		{
			Function function;
			// 测试直线和圆相切
			int ret = function.Solve("input4.txt", "output.txt");
			Assert::AreEqual(ret, 1);
		}

		TEST_METHOD(TestMethod5)
		{
			Function function;
			// 测试直线和圆相离
			int ret = function.Solve("input5.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethod6)
		{
			Function function;
			// 测试直线和圆相交
			int ret = function.Solve("input6.txt", "output.txt");
			Assert::AreEqual(ret, 2);
		}

		TEST_METHOD(TestMethod7)
		{
			Function function;
			// 压力测试
			int ret = function.Solve("input7.txt", "output.txt");
			Assert::AreEqual(ret, 1998935);
		}

		TEST_METHOD(TestMethod8)
		{
			Function function;
			// 压力测试
			int ret = function.Solve("input8.txt", "output.txt");
			Assert::AreEqual(ret, 4);
		}

		TEST_METHOD(TestMethod9)
		{
			Function function;
			// 两圆相切
			int ret = function.Solve("input9.txt", "output.txt");
			Assert::AreEqual(ret, 1);
		}

		TEST_METHOD(TestMethod10)
		{
			Function function;
			// 内涵
			int ret = function.Solve("input10.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}
	};
}
