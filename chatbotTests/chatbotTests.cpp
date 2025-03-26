#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
extern "C" {

data_handling
#include "../AiChatBot/data_handling.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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