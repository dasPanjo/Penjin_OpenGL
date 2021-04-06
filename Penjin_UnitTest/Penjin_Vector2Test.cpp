#include "pch.h"
#include "CppUnitTest.h"
#include <Vector2.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PenjinVectorTest
{
	TEST_CLASS(PenjinVector2Test)
	{
	public:
		TEST_METHOD(Zero) {
			Penjin::Vector2 vec = Penjin::Vector2::Zero;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
		}
		TEST_METHOD(Constructor0Arguments)
		{
			Penjin::Vector2 vec;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
		}
		TEST_METHOD(Constructor2Arguments)
		{
			Penjin::Vector2 vec(1.0f, 2.0f);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
		}
		TEST_METHOD(Add)
		{
			Penjin::Vector2 vec1(1.0f, 2.0f);
			Penjin::Vector2 vec2(3.0f, 4.0f);
			vec1.Add(vec2);
			Assert::AreEqual(4.0f, vec1.x);
			Assert::AreEqual(6.0f, vec1.y);

			Assert::AreEqual(3.0f, vec2.x);
			Assert::AreEqual(4.0f, vec2.y);
		}
		TEST_METHOD(OperatorAdd)
		{
			Penjin::Vector2 vec1(1.0f, 2.0f);
			Penjin::Vector2 vec2(3.0f, 4.0f);
			Penjin::Vector2 vec3 = vec1 + vec2;
			Assert::AreEqual(1.0f, vec1.x);
			Assert::AreEqual(2.0f, vec1.y);

			Assert::AreEqual(3.0f, vec2.x);
			Assert::AreEqual(4.0f, vec2.y);

			Assert::AreEqual(4.0f, vec3.x);
			Assert::AreEqual(6.0f, vec3.y);
		}
		TEST_METHOD(OperatorAddEqual)
		{
			Penjin::Vector2 vec1(1.0f, 2.0f);
			Penjin::Vector2 vec2(3.0f, 4.0f);
			vec1 += vec2;
			Assert::AreEqual(4.0f, vec1.x);
			Assert::AreEqual(6.0f, vec1.y);

			Assert::AreEqual(3.0f, vec2.x);
			Assert::AreEqual(4.0f, vec2.y);
		}

		TEST_METHOD(Subtract)
		{
			Penjin::Vector2 vec1(10.0f, 9.0f);
			Penjin::Vector2 vec2(4.0f, 5.0f);
			vec1.Subtract(vec2);
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
		}
		TEST_METHOD(OperatorSubtract)
		{
			Penjin::Vector2 vec1(10.0f, 9.0f);
			Penjin::Vector2 vec2(4.0f, 5.0f);
			Penjin::Vector2 vec3 = vec1 - vec2;

			Assert::AreEqual(10.0f, vec1.x);
			Assert::AreEqual(9.0f, vec1.y);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);

			Assert::AreEqual(6.0f, vec3.x);
			Assert::AreEqual(4.0f, vec3.y);
		}
		TEST_METHOD(OperatorSubtractEqual)
		{
			Penjin::Vector2 vec1(10.0f, 9.0f);
			Penjin::Vector2 vec2(4.0f, 5.0f);
			vec1 -= vec2;
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
		}

	};
}
