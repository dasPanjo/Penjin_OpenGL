#include "pch.h"
#include "CppUnitTest.h"
#include <Vector4.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PenjinVectorTest
{
	TEST_CLASS(PenjinVector4Test)
	{
	public:
		TEST_METHOD(Zero) {
			Penjin::Vector4 vec = Penjin::Vector4::Zero;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
			Assert::AreEqual(0.0f, vec.w);
		}
		TEST_METHOD(Constructor0Arguments)
		{
			Penjin::Vector4 vec;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
			Assert::AreEqual(0.0f, vec.w);
		}
		TEST_METHOD(Constructor2Arguments)
		{
			Penjin::Vector4 vec(1.0f, 2.0f);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
			Assert::AreEqual(0.0f, vec.w);
		}
		TEST_METHOD(Constructor3Arguments)
		{
			Penjin::Vector4 vec(1.0f, 2.0f, 3.0);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
			Assert::AreEqual(3.0f, vec.z);
			Assert::AreEqual(0.0f, vec.w);
		}
		TEST_METHOD(Constructor4Arguments)
		{
			Penjin::Vector4 vec(1.0f, 2.0f, 3.0, 4.0f);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
			Assert::AreEqual(3.0f, vec.z);
			Assert::AreEqual(4.0f, vec.w);
		}
		TEST_METHOD(Add)
		{
			Penjin::Vector4 vec1(6.0f, 7.0f, 8.0f, 9.0f);
			Penjin::Vector4 vec2(11.0f, 12.0f, 13.0f, 14.0f);
			vec1.Add(vec2);
			Assert::AreEqual(17.0f, vec1.x);
			Assert::AreEqual(19.0f, vec1.y);
			Assert::AreEqual(21.0f, vec1.z);
			Assert::AreEqual(23.0f, vec1.w);

			Assert::AreEqual(11.0f, vec2.x);
			Assert::AreEqual(12.0f, vec2.y);
			Assert::AreEqual(13.0f, vec2.z);
			Assert::AreEqual(14.0f, vec2.w);
		}
		TEST_METHOD(OperatorAdd)
		{
			Penjin::Vector4 vec1(6.0f, 7.0f, 8.0f, 9.0f);
			Penjin::Vector4 vec2(11.0f, 12.0f, 13.0f, 14.0f);
			Penjin::Vector4 vec3 = vec1 + vec2;

			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(7.0f, vec1.y);
			Assert::AreEqual(8.0f, vec1.z);
			Assert::AreEqual(9.0f, vec1.w);

			Assert::AreEqual(11.0f, vec2.x);
			Assert::AreEqual(12.0f, vec2.y);
			Assert::AreEqual(13.0f, vec2.z);
			Assert::AreEqual(14.0f, vec2.w);

			Assert::AreEqual(17.0f, vec3.x);
			Assert::AreEqual(19.0f, vec3.y);
			Assert::AreEqual(21.0f, vec3.z);
			Assert::AreEqual(23.0f, vec3.w);
		}
		TEST_METHOD(OperatorAddEqual)
		{
			Penjin::Vector4 vec1(1.0f, 2.0f, 3.0f, 4.0f);
			Penjin::Vector4 vec2(4.0f, 5.0f, 6.0f, 7.0f);
			vec1 += vec2;
			Assert::AreEqual(5.0f, vec1.x);
			Assert::AreEqual(7.0f, vec1.y);
			Assert::AreEqual(9.0f, vec1.z);
			Assert::AreEqual(11.0f, vec1.w);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
			Assert::AreEqual(7.0f, vec2.w);
		}

		TEST_METHOD(Subtract)
		{
			Penjin::Vector4 vec1(10.0f, 9.0f, 8.0f, 7.0f);
			Penjin::Vector4 vec2(4.0f, 5.0f, 6.0f, 7.0f);
			vec1.Subtract(vec2);
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);
			Assert::AreEqual(2.0f, vec1.z);
			Assert::AreEqual(0.0f, vec1.w);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
			Assert::AreEqual(7.0f, vec2.w);
		}
		TEST_METHOD(OperatorSubtract)
		{
			Penjin::Vector4 vec1(10.0f, 9.0f, 8.0f, 7.0f);
			Penjin::Vector4 vec2(3.0f, 4.0f, 5.0f, 6.0f);
			Penjin::Vector4 vec3 = vec1 - vec2;

			Assert::AreEqual(10.0f, vec1.x);
			Assert::AreEqual(9.0f, vec1.y);
			Assert::AreEqual(8.0f, vec1.z);
			Assert::AreEqual(7.0f, vec1.w);

			Assert::AreEqual(3.0f, vec2.x);
			Assert::AreEqual(4.0f, vec2.y);
			Assert::AreEqual(5.0f, vec2.z);
			Assert::AreEqual(6.0f, vec2.w);

			Assert::AreEqual(7.0f, vec3.x);
			Assert::AreEqual(5.0f, vec3.y);
			Assert::AreEqual(3.0f, vec3.z);
			Assert::AreEqual(1.0f, vec3.w);
		}
		TEST_METHOD(OperatorSubtractEqual)
		{
			Penjin::Vector4 vec1(10.0f, 9.0f, 8.0f, 7.0f);
			Penjin::Vector4 vec2(4.0f, 5.0f, 6.0f, 7.0f);
			vec1 -= vec2;
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);
			Assert::AreEqual(2.0f, vec1.z);
			Assert::AreEqual(0.0f, vec1.w);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
			Assert::AreEqual(7.0f, vec2.w);
		}

	};
}
