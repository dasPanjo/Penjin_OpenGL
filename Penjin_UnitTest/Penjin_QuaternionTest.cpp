#include "pch.h"
#include "CppUnitTest.h"
#include <Quaternion.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PenjinVectorTest
{
	TEST_CLASS(PenjinQuaternionTest)
	{
	public:
		TEST_METHOD(Creation) {
			Penjin::Quaternion quat = Penjin::Quaternion::Euler(10.0f, 20.0f, 30.0f);
			Penjin::Vector3 rotEuler = quat.GetEuler();
			Assert::AreEqual(10.0f, rotEuler.x);
			Assert::AreEqual(20.0f, rotEuler.y);
			Assert::AreEqual(30.0f, rotEuler.z);
		}
		TEST_METHOD(Rotation) {
			Penjin::Quaternion quat = Penjin::Quaternion::Euler(0, 0, 0);
			quat.Rotate(0, 90, 0);
			Penjin::Vector3 rotEuler = quat.GetEuler();
			Assert::AreEqual(90.0f, rotEuler.y);
		}
	};
}
