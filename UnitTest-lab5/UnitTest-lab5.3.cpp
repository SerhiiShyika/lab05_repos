#include "pch.h"
#include "CppUnitTest.h"

#define main Lab053ProgramMain
#include "..\\Lab-05.3\\Lab-05.3.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab5
{
    TEST_CLASS(UnitTestlab53)
    {
    public:
        TEST_METHOD(TermFollowedRecurrenceForHalfInput)
        {
            double a = 1.0;

            a = Term(0.5, 1, a);
            Assert::AreEqual(0.5, a, 1e-12);

            a = Term(0.5, 2, a);
            Assert::AreEqual(1.0 / 24.0, a, 1e-12);
        }

        TEST_METHOD(SumIsEvenAndMatchesKnownSeriesValue)
        {
            const double expected = 1.543080634815196;

            Assert::AreEqual(expected, Sum(0.5), 1e-12);
            Assert::AreEqual(expected, Sum(-0.5), 1e-12);
        }

        TEST_METHOD(JMatchesKnownValuesInsideAndOutsideUnitInterval)
        {
            const double expectedInside = 2.855957892565025;
            const double expectedOutside = 0.6117420237671963;

            Assert::AreEqual(expectedInside, j(0.5), 1e-12);
            Assert::AreEqual(expectedInside, j(-0.5), 1e-12);
            Assert::AreEqual(expectedOutside, j(1.0), 1e-12);
        }

        TEST_METHOD(CalculateResultEvaluatesCompositeExpression)
        {
            const double expectedZero = 2.2812118429307637;
            const double expectedHalf = 12.235937424203877;

            Assert::AreEqual(expectedZero, calculateResult(0.0), 1e-12);
            Assert::AreEqual(expectedHalf, calculateResult(0.5), 1e-12);
        }
    };
}
