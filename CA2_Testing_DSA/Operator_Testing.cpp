#include "pch.h"
#include "CppUnitTest.h"
#include "../TreeMap.h"
#include "../Pair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CA2TestingDSA
{

    TEST_CLASS(PairUnitTests)
    {
    public:
        TEST_METHOD(TestEqualsOperator)
        {
            //Create pairs
            Pair<int, string> p1(1, "One");
            Pair<int, string> p2(1, "One");
            Pair<int, string> p3(2, "Two");

            Assert::IsTrue(p1 == p2);//Ensure p1 and p2 are equal
            Assert::IsFalse(p1 == p3);//Ensure p1 and p3 are not equal
        }

        TEST_METHOD(TestNotEqualsOperator)
        {
            //Create pairs
            Pair<int, string> p1(1, "One");
            Pair<int, string> p2(1, "One");
            Pair<int, string> p3(2, "Two");

            Assert::IsFalse(p1 == p3);//Ensure p1 and p3 are not equal
            Assert::IsTrue(p1 == p2);//Ensure p1 and p2 are equal
        }

        TEST_METHOD(TestGetFirstAndGetSecond)
        {
            //Create pairs
            Pair<int, string> p(1, "One");

            Assert::AreEqual(1, p.getFirst());//Check if getFirst() returns the key (1)
            Assert::AreEqual(string("One"), p.getSecond());//Check if getSecond() returns the value ("One")
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            //Create pairs
            Pair<int, string> p1(1, "One");
            Pair<int, string> p2(2, "Two");

            p2 = p1;//Assign p1 to p2

            Assert::AreEqual(1, p2.getFirst());//Ensure p2's key is now 1
            Assert::AreEqual(string("One"), p2.getSecond());//Ensure p2's value is now "One"
        }

        TEST_METHOD(TestLessThanOperator)
        {
            //Create pairs
            Pair<int, std::string> p1(1, "One");
            Pair<int, std::string> p2(2, "Two");
            Pair<int, std::string> p3(1, "One");

            Assert::IsTrue(p1 < p2);//Ensure p1 is less than p2 based on key comparison
            Assert::IsFalse(p1 < p3);//Ensure p1 is not less than p3 (keys are equal)
            Assert::IsFalse(p2 < p1);//Ensure p2 is not less than p1 (keys are not equal)
        }

        TEST_METHOD(TestGreaterThanOperator)
        {
            //Create pairs
            Pair<int, std::string> p1(1, "One");
            Pair<int, std::string> p2(2, "Two"); 
            Pair<int, std::string> p3(1, "One");

            Assert::IsTrue(p2 > p1);//Ensure p2 is greater than p1 based on key comparison
            Assert::IsFalse(p1 > p3);//Ensure p1 is not greater than p3 (keys are equal)
            Assert::IsFalse(p1 > p2);//Ensure p1 is not greater than p2 (keys are not equal)
        }
    };
}
