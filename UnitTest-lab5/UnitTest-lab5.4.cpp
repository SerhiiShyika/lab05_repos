#include "pch.h"
#include "CppUnitTest.h"

#define main Lab054ProgramMain
#include "..\\Lab-5.4\\Lab-5.4.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab5
{
    TEST_CLASS(UnitTestlab54)
    {
    public:
        TEST_METHOD(FComputesExpectedValues)
        {
            Assert::AreEqual(1.0, F(1), 1e-12);
            Assert::AreEqual(0.399243240841469, F(2), 1e-12);
        }

        TEST_METHOD(S0MultipliesTermsAcrossRange)
        {
            const double expected = 0.040494731200532055;

            Assert::AreEqual(expected, S0(1, 3), 1e-12);
        }

        TEST_METHOD(RecursiveVariantsMatchIterativeProduct)
        {
            const double expected = 0.00028769459479053265;

            Assert::AreEqual(expected, S1(2, 5, 2), 1e-12);
            Assert::AreEqual(expected, S2(2, 5, 5), 1e-12);
            Assert::AreEqual(expected, S3(2, 5, 2, 1.0), 1e-12);
            Assert::AreEqual(expected, S4(2, 5, 5, 1.0), 1e-12);
        }
    };
}
