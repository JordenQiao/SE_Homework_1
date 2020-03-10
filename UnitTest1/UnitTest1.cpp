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
			// ����ƽ��ֱ��
			Function function;
			int ret = function.Solve("input1.txt", "output.txt");
			Assert::AreEqual(ret, 2);
		}
		TEST_METHOD(TestMethod2) 
		{
			Function function;
			// ����ֱˮƽ��
			int ret = function.Solve("input2.txt", "output.txt");
			Assert::AreEqual(ret, 3);
		}

		TEST_METHOD(TestMethod3)
		{
			Function function;
			// ����һ��ֱ��
			int ret = function.Solve("input3.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethod4)
		{
			Function function;
			// ����ֱ�ߺ�Բ����
			int ret = function.Solve("input4.txt", "output.txt");
			Assert::AreEqual(ret, 1);
		}

		TEST_METHOD(TestMethod5)
		{
			Function function;
			// ����ֱ�ߺ�Բ����
			int ret = function.Solve("input5.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethod6)
		{
			Function function;
			// ����ֱ�ߺ�Բ�ཻ
			int ret = function.Solve("input6.txt", "output.txt");
			Assert::AreEqual(ret, 2);
		}

		TEST_METHOD(TestMethod7)
		{
			Function function;
			// ѹ������
			int ret = function.Solve("input7.txt", "output.txt");
			Assert::AreEqual(ret, 1998935);
		}

		TEST_METHOD(TestMethod8)
		{
			Function function;
			// ѹ������
			int ret = function.Solve("input8.txt", "output.txt");
			Assert::AreEqual(ret, 4);
		}

		TEST_METHOD(TestMethod9)
		{
			Function function;
			// ��Բ����
			int ret = function.Solve("input9.txt", "output.txt");
			Assert::AreEqual(ret, 1);
		}

		TEST_METHOD(TestMethod10)
		{
			Function function;
			// �ں�
			int ret = function.Solve("input10.txt", "output.txt");
			Assert::AreEqual(ret, 0);
		}
	};
}
