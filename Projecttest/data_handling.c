#include <stdio.h>
#include <string.h>
#include "data_handling.h"

// Function to get FAQ responses based on keyword
char* getFAQResponse(char* keyword) {
    if (strcmp(keyword, "How many weeks is a course?") == 0) {
        return "A course is 15 weeks long.";
    }
    else if (strcmp(keyword, "When is the Student Success Week?") == 0) {
        return "Student Success Week is in Week 8.";
    }
    else if (strcmp(keyword, "What time are my lectures?") == 0) {
        return "Lecture Timings:\n- User Experience: Wednesday at 6 PM\n- Project 2: Thursday at 9 AM\n- Operating System: Wednesday at 1 PM";
    }
    else if (strcmp(keyword, "When does the first semester start?") == 0) {
        return "The first semester starts on September 3.";
    }
    else if (strcmp(keyword, "When does it end?") == 0) {
        return "The first semester ends approximately between April 14-20.";
    }
    else if (strcmp(keyword, "How long is each semester?") == 0) {
        return "Each semester lasts for 4 months.";
    }
    else if (strcmp(keyword, "What is the passing grade for my courses?") == 0) {
        return "The passing grade for your courses is 60%.";
    }
    return NULL;
}

// Function to log user queries (for future improvements)
void logUserQuery(char* userQuery) {
    FILE* file = fopen("query_log.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", userQuery);
        fclose(file);
    }
}
