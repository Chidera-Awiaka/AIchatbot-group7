#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../AiChatBot/ai_processing.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ==================================
//        AI PROCESSING TESTS
// ==================================
namespace AIProcessingTests
{
    TEST_CLASS(AIProcessingTests)
    {
    public:
        TEST_METHOD(TestProcessQuery_ValidFAQ)
        {
            Assert::AreEqual("A course is 15 weeks long.", processQuery("How many weeks is a course?"));
        }

        TEST_METHOD(TestProcessQuery_InvalidQuery)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery("Tell me a joke."));
        }

        TEST_METHOD(TestProcessQuery_HiddenQuestion)
        {
            Assert::AreEqual("There are 6 courses in each semester.", processQuery("How many courses are there in each semester?"));
        }

        TEST_METHOD(TestProcessQuery_EmptyInput)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery(""));
        }

        TEST_METHOD(TestProcessQuery_CaseSensitivity)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery("how many weeks is a course?"));
        }

        TEST_METHOD(TestProcessQuery_SpecialCharacters)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery("@#$%&*"));
        }

        TEST_METHOD(TestProcessQuery_ExactMatchVsSimilar)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery("weeks course?"));
        }

        TEST_METHOD(TestProcessQuery_LongQuery)
        {
            char longQuery[500] = "This is a very long query...";
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery(longQuery));
        }

        TEST_METHOD(TestProcessQuery_NullInput)
        {
            Assert::AreEqual("Sorry, I don't understand that question.", processQuery(""));
        }

        TEST_METHOD(TestProcessQuery_Greetings)
        {
            char* response = processQuery("hello");
            Assert::AreEqual("Chatbot: Hello! How can I help you?", response);
        }
    };
}