
#include <stdio.h>
#include <string.h>
#include "ai_processing.h"
#include "data_handling.h"

char* processQuery(char* userQuery) {
    // ?? Fix: Check for greetings FIRST
    if (strcmp(userQuery, "hi") == 0 || strcmp(userQuery, "hello") == 0) {
        return "Chatbot: Hello! How can I help you?";
    }

    // Check hidden questions first
    if (strcmp(userQuery, "How many courses are there in each semester?") == 0) {
        return "There are 6 courses in each semester.";
    }
    else if (strcmp(userQuery, "Who are my professors?") == 0) {
        return "Your professors are:\n- User Experience: Ranga\n- Operating System: Sumeet\n- Project 2: Gurpreet";
    }

    // Check FAQ responses
    char* response = getFAQResponse(userQuery);
    if (response != NULL) {
        return response;
    }

    return "Sorry, I don't understand that question.";
}