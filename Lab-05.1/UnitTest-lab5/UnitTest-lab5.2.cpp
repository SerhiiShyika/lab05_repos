#include "pch.h"
#include "CppUnitTest.h"

#define main Lab052ProgramMain
#include "..\\Lab-05.2\\Lab-05.2.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab5
{
    TEST_CLASS(UnitTestlab52)
    {
    public:
        TEST_METHOD(TermCalculatesSuccessiveSeriesTerms)
        {
            double term = 0.5;

            Term(2.0, 1, term);
            Assert::AreEqual(1.0 / 24.0, term, 1e-12);

            Term(2.0, 2, term);
            Assert::AreEqual(1.0 / 160.0, term, 1e-12);
        }

        TEST_METHOD(SumResetsOutputsAndHonorsEpsilon)
        {
            int n = 99;
            double sum = 99.0;

            Sum(2.0, 0.01, n, sum);
            Assert::AreEqual(2, n);
            Assert::AreEqual(13.0 / 24.0, sum, 1e-12);

            n = 99;
            sum = 99.0;
            Sum(2.0, 1e-10, n, sum);
            Assert::AreEqual(0.5 * log(3.0), sum, 2e-10);
            Assert::IsTrue(n > 0);

            sum = 1.0;
            Sum(2.0, 0.6, n, sum);
            Assert::AreEqual(0, n);
            Assert::AreEqual(0.0, sum, 0.0);
        }

        TEST_METHOD(SumIsOddForNegativeInput)
        {
            int positiveN = 0;
            int negativeN = 0;
            double positiveSum = 0.0;
            double negativeSum = 0.0;

            Sum(2.0, 1e-8, positiveN, positiveSum);
            Sum(-2.0, 1e-8, negativeN, negativeSum);

            Assert::AreEqual(positiveN, negativeN);
            Assert::AreEqual(-positiveSum, negativeSum, 1e-12);
        }
    };
}
