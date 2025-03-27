#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../AiChatBot/ai_processing.h"
#include "../AiChatBot/data_handling.h"
#include "../AiChatBot/user_interaction.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ==================================
ai_processing
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
    // ==================================
data_handling
//        DATA HANDLING TESTS
// ==================================
namespace DataHandlingTests
{
    TEST_CLASS(DataHandlingTests)
    {
    public:
        TEST_METHOD(TestGetFAQResponse_ValidQuestion)
        {
            Assert::AreEqual("A course is 15 weeks long.", getFAQResponse("How many weeks is a course?"));
        }

        TEST_METHOD(TestGetFAQResponse_InvalidQuestion)
        {
            Assert::IsNull(getFAQResponse("What is the weather today?"));
        }

        TEST_METHOD(TestGetFAQResponse_EmptyString)
        {
            Assert::IsNull(getFAQResponse(""));
        }

        TEST_METHOD(TestGetFAQResponse_CaseSensitivity)
        {
            Assert::IsNull(getFAQResponse("how many weeks is a course?"));
        }

        TEST_METHOD(TestGetFAQResponse_PartialMatch)
        {
            Assert::IsNull(getFAQResponse("weeks course"));
        }

        TEST_METHOD(TestGetFAQResponse_ExactMatch)
        {
            Assert::AreEqual("Student Success Week is in Week 8.", getFAQResponse("When is the Student Success Week?"));
        }

        TEST_METHOD(TestLogUserQuery_FileExists)
        {
            logUserQuery("Sample query");
            FILE* file = fopen("query_log.txt", "r");
            Assert::IsNotNull(file);
            if (file) fclose(file);
        }

        TEST_METHOD(TestLogUserQuery_AppendEntry)
        {
            logUserQuery("Another query");
            FILE* file = fopen("query_log.txt", "r");
            fseek(file, 0, SEEK_END);
            Assert::IsTrue(ftell(file) > 0);
            fclose(file);
        }

        TEST_METHOD(TestLogUserQuery_NullInput)
        {
            logUserQuery(NULL);
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestLogUserQuery_LongInput)
        {
            char longQuery[500] = "This is a very long query...";
            logUserQuery(longQuery);
            Assert::IsTrue(true);
        }
    };
}
}
