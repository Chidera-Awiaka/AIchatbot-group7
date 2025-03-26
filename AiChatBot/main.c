#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_interaction.h"
#include "ai_processing.h"
#include "data_handling.h"

int main() {
    char input[100];

    displayWelcomeMessage();

    while (1) {
        strcpy_s(input, sizeof(input), getUserInput());

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Check for greetings
        if (strcmp(input, "hi") == 0 || strcmp(input, "hello") == 0) {
            printf("Chatbot: Hello! How can I help you?\n");
            displayFAQ();
            continue;
        }

        // Check if input is a number
        int choice;
        if (sscanf_s(input, "%d", &choice) == 1) {
            switch (choice) {
            case 1: printf("A course is 15 weeks long.\n"); break;
            case 2: printf("Student Success Week is in Week 8.\n"); break;
            case 3: printf("Lecture Timings:\n- User Experience: Wednesday at 6 PM\n- Project 2: Thursday at 9 AM\n- Operating System: Wednesday at 1 PM\n"); break;
            case 4: printf("The first semester starts on September 3.\n"); break;
            case 5: printf("The first semester ends approximately between April 14-20.\n"); break;
            case 6: printf("Each semester lasts for 4 months.\n"); break;
            case 7: printf("The passing grade for your courses is 60%%.\n"); break;
            default: printf("Invalid choice. Please enter a number between 1-7.\n");
            }
        }
        else {
            // Process hidden questions and FAQs
            printf("%s\n", processQuery(input));
        }
    }

    return 0;
}
