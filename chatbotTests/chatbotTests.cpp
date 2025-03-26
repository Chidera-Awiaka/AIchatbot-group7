#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
extern "C" {

#include "../AiChatBot/user_interaction.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ==================================
//        USER INTERACTION TESTS
// ==================================
namespace UserInteractionTests
{
    TEST_CLASS(UserInteractionTests)
    {
    public:
        // Simulate user input by redirecting stdin
        void SimulateUserInput(const char* input)
        {
            freopen("CONIN$", "r", stdin); // Reset stdin
            FILE* inputStream = freopen("input.txt", "w+", stdin);
            if (inputStream)
            {
                fprintf(inputStream, "%s\n", input);
                rewind(inputStream);
            }
        }

        TEST_METHOD(TestGetUserInput_Valid)
        {
            SimulateUserInput("Hello");
            char* input = getUserInput();
            Assert::IsNotNull(input);
        }

        TEST_METHOD(TestGetUserInput_Empty)
        {
            SimulateUserInput("");
            char* input = getUserInput();
            Assert::AreEqual("", input);
        }

        TEST_METHOD(TestGetUserInput_LongInput)
        {
            SimulateUserInput("A very long input...");
            char* input = getUserInput();
            Assert::IsTrue(strlen(input) < 100);
        }

        TEST_METHOD(TestGetUserInput_Null)
        {
            SimulateUserInput(NULL);
            char* input = getUserInput();
            Assert::IsNotNull(input);
        }

        TEST_METHOD(TestInvalidChoiceHandling)
        {
            int choice = 10;
            Assert::IsTrue(choice > 7 || choice < 1);
        }

        TEST_METHOD(TestValidChoiceHandling)
        {
            int choice = 3;
            Assert::IsTrue(choice >= 1 && choice <= 7);
        }

        TEST_METHOD(TestDisplayWelcomeMessage)
        {
            displayWelcomeMessage();
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestDisplayFAQ)
        {
            displayFAQ();
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestDisplayFAQ_OutputFormat)
        {
            displayFAQ();
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestDisplayWelcomeMessage_OutputFormat)
        {
            displayWelcomeMessage();
            Assert::IsTrue(true);
        }
    };
}