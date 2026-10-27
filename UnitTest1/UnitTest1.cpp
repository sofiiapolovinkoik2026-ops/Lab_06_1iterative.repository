#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1iterative.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int SIZE = 5;
            int testArray[SIZE] = { -5, 10, -3, -7, 2 };

            int actualCount = countElements(testArray, SIZE);
            Assert::AreEqual(4, actualCount);

            int actualSum = sumElements(testArray, SIZE);
            Assert::AreEqual(4, actualSum);

            modifyArray(testArray, SIZE);

            Assert::AreEqual(0, testArray[0]);
            Assert::AreEqual(0, testArray[1]);
            Assert::AreEqual(0, testArray[2]);
            Assert::AreEqual(-7, testArray[3]);
            Assert::AreEqual(0, testArray[4]);
        }
    };
}