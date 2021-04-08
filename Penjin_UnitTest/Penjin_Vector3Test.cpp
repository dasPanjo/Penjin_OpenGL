#include "pch.h"
#include "CppUnitTest.h"
#include <Vector3.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PenjinVectorTest
{
	TEST_CLASS(PenjinVector3Test)
	{
	public:
		TEST_METHOD(Zero) {
			Penjin::Vector3 vec = Penjin::Vector3::Zero;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
		}
		TEST_METHOD(Constructor0Arguments)
		{
			Penjin::Vector3 vec;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
		}
		TEST_METHOD(Constructor2Arguments)
		{
			Penjin::Vector3 vec(1.0f, 2.0f);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
		}
		TEST_METHOD(Constructor3Arguments)
		{
			Penjin::Vector3 vec(1.0f, 2.0f, 3.0);
			Assert::AreEqual(1.0f, vec.x);
			Assert::AreEqual(2.0f, vec.y);
			Assert::AreEqual(3.0f, vec.z);
		}

		TEST_METHOD(Normalize)
		{
			float x = 3;
			float y = 4;
			float z = 5;
			Penjin::Vector3 vec(x,y,z);
			float length = sqrt(x * x + y * y + z * z);
			x /= length;
			y /= length;
			z /= length;
			vec.Normalize();			
			Assert::AreEqual(x, vec.x);
			Assert::AreEqual(y, vec.y);
			Assert::AreEqual(z, vec.z);
			Assert::AreEqual(1.0f, vec.GetLength());
		}

		TEST_METHOD(Add)
		{
			Penjin::Vector3 vec1(1.0f, 2.0f, 3.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			vec1.Add(vec2);
			Assert::AreEqual(5.0f, vec1.x);
			Assert::AreEqual(7.0f, vec1.y);
			Assert::AreEqual(9.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
		}
		TEST_METHOD(OperatorAdd)
		{
			Penjin::Vector3 vec1(1.0f, 2.0f, 3.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			Penjin::Vector3 vec3 = vec1 + vec2;

			Assert::AreEqual(1.0f, vec1.x);
			Assert::AreEqual(2.0f, vec1.y);
			Assert::AreEqual(3.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);

			Assert::AreEqual(5.0f, vec3.x);
			Assert::AreEqual(7.0f, vec3.y);
			Assert::AreEqual(9.0f, vec3.z);
		}
		TEST_METHOD(OperatorAddEqual)
		{
			Penjin::Vector3 vec1(1.0f, 2.0f, 3.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			vec1 += vec2;
			Assert::AreEqual(5.0f, vec1.x);
			Assert::AreEqual(7.0f, vec1.y);
			Assert::AreEqual(9.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
		}

		TEST_METHOD(Subtract)
		{
			Penjin::Vector3 vec1(10.0f, 9.0f, 8.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			vec1.Subtract(vec2);
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);
			Assert::AreEqual(2.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
		}
		TEST_METHOD(OperatorSubtract)
		{
			Penjin::Vector3 vec1(10.0f, 9.0f, 8.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			Penjin::Vector3 vec3 = vec1 - vec2;

			Assert::AreEqual(10.0f, vec1.x);
			Assert::AreEqual(9.0f, vec1.y);
			Assert::AreEqual(8.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);

			Assert::AreEqual(6.0f, vec3.x);
			Assert::AreEqual(4.0f, vec3.y);
			Assert::AreEqual(2.0f, vec3.z);
		}
		TEST_METHOD(OperatorSubtractEqual)
		{
			Penjin::Vector3 vec1(10.0f, 9.0f, 8.0f);
			Penjin::Vector3 vec2(4.0f, 5.0f, 6.0f);
			vec1 -= vec2;
			Assert::AreEqual(6.0f, vec1.x);
			Assert::AreEqual(4.0f, vec1.y);
			Assert::AreEqual(2.0f, vec1.z);

			Assert::AreEqual(4.0f, vec2.x);
			Assert::AreEqual(5.0f, vec2.y);
			Assert::AreEqual(6.0f, vec2.z);
		}

	};
}
