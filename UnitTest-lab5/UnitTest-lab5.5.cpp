#include "pch.h"
#include "CppUnitTest.h"

#define main Lab055ProgramMain
#include "..\\Lab-05.5\\Lab-05.5.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab5
{
    TEST_CLASS(UnitTestlab55)
    {
    public:
        TEST_METHOD(ConvertReturnsZeroForZeroInput)
        {
            Assert::AreEqual(string("0"), Convert(0U, 2));
            Assert::AreEqual(string("0"), Convert(0U, 36));
        }

        TEST_METHOD(ConvertFormatsBinaryAndOctalDigits)
        {
            Assert::AreEqual(string("1101"), Convert(13U, 2));
            Assert::AreEqual(string("377"), Convert(255U, 8));
        }

        TEST_METHOD(ConvertSupportsUppercaseDigitsAndCarryAcrossPositions)
        {
            Assert::AreEqual(string("Z"), Convert(35U, 36));
            Assert::AreEqual(string("10"), Convert(36U, 36));
            Assert::AreEqual(string("ZZ"), Convert(1295U, 36));
            Assert::AreEqual(string("100"), Convert(1296U, 36));
        }

        TEST_METHOD(ConvertHandlesMaximumUnsignedInteger)
        {
            Assert::AreEqual(
                string("11111111111111111111111111111111"),
                Convert(4294967295U, 2));
            Assert::AreEqual(string("FFFFFFFF"), Convert(4294967295U, 16));
        }
    };
}
