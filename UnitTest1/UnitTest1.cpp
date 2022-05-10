#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/Huffman.h"
#include "../lab2/list.h"
#include "../lab2/string.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(test_1)
		{
			String text = "Pop";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "10110";
			Assert::AreEqual(expected, temp)
		}
		TEST_METHOD(test_2)
		{
			String text = "adfqweed";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "11000111100101010100";
			Assert::AreEqual(expected, temp)
		}
		TEST_METHOD(test_3)
		{
			String text = "qwerty";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "0001110111100101";
			Assert::AreEqual(expected, temp)
		}
		TEST_METHOD(test_4)
		{
			String text = "234q";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "10110001";
			Assert::AreEqual(expected, temp)
		}
		TEST_METHOD(test_5)
		{
			String text = "good man";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "0000101001110111100101";
			Assert::AreEqual(expected, temp)
		}
		TEST_METHOD(test_6)
		{
			String text = "das asd";
			ListOfNum<node_tree*>* example = table(text);
			String temp = encode(example, text);
			String expected = "01101100101101";
			Assert::AreEqual(expected, temp)
		}
	};
}
