#include "pch.h"
#include "CppUnitTest.h"
#include "../TreeMap.h"
#include "../Pair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CA2TestingDSA
{
    TEST_CLASS(TreeMapTests)
    {
    public:

        TEST_METHOD(TestPutItems) {
            TreeMap<int, string> tree;

            //Add items
            tree.put(1, "One");
            tree.put(5, "Five");
            tree.put(3, "Three");

            Assert::AreEqual(string("One"), tree.get(1));//Check if key 1 maps to "One"
            Assert::AreEqual(string("Five"), tree.get(5));//Check if key 5 maps to "Five"
            Assert::AreEqual(string("Three"), tree.get(3));//Check if key 3 maps to "Three"
        }

        TEST_METHOD(TestGetItem)
        {
            TreeMap<int, std::string> tree;

            //Add items
            tree.put(1, "One");
            tree.put(2, "Two");

            Assert::AreEqual(string("One"), tree.get(1));//Check if key 1 maps to "One"
            Assert::AreEqual(string("Two"), tree.get(2));//Check if key 2 maps to "Two"
        }

        TEST_METHOD(TestContainsKey)
        {
            TreeMap<int, string> tree;

            //Add items
            tree.put(1, "One");
            tree.put(2, "Two");

            Assert::IsTrue(tree.containsKey(1));//Check if key 1 exists
            Assert::IsTrue(tree.containsKey(2));//Check if key 2 exists

            Assert::IsFalse(tree.containsKey(3));//Check if key 3 does not exist
        }

        TEST_METHOD(TestClearItems)
        {
            TreeMap<int, string> tree;
            //Add items
            tree.put(1, "One");
            tree.put(2, "Two");

            Assert::IsTrue(tree.containsKey(1));//Ensure key 1 exists
            Assert::IsTrue(tree.containsKey(2));//Ensure key 2 exists

            tree.clear();//Clear all items

            Assert::IsFalse(tree.containsKey(1));//Ensure key 1 is removed
            Assert::IsFalse(tree.containsKey(2));//Ensure key 2 is removed
        }

        TEST_METHOD(TestCount)
        {
            TreeMap<int, std::string> tree;

            //Add items
            tree.put(1, "One");
            tree.put(2, "Two");

            tree.remove(1);//Remove item with key 1

            Assert::IsFalse(tree.containsKey(1));//Ensure key 1 is removed
        }

        TEST_METHOD(TestSize)
        {
            TreeMap<int, string> tree;

            Assert::AreEqual(0, tree.size());//Ensure the tree is empty initially

            tree.put(1, "One");//Add item with key 1 and value "One"
            tree.put(2, "Two");//Add item with key 2 and value "Two"

            Assert::AreEqual(2, tree.size());//Ensure size is 2 after adding two items

            tree.remove(1);//Remove item with key 1

            Assert::AreEqual(1, tree.size());//Ensure size is 1 after removing one item
        }
    };
}
