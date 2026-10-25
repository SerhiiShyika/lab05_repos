#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Lab-05.1\\Lab-05.1.cpp"
#include <optional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab5
{
    TEST_CLASS(UnitTestlab5)
    {
    public:
        TEST_METHOD(CalculateResultForInput_1)
        {
            const double expected = 996788.6861171847;

            const std::optional<double> actual = calculateResult(1.0);

            Assert::AreEqual(expected, actual.value(), 0.000001);
        }

        TEST_METHOD(CalculateResultRejectsInvalidRadicand)
        {
            const std::optional<double> actual = calculateResult(1.9);

            Assert::IsFalse(actual.has_value());
        }
    };
}
