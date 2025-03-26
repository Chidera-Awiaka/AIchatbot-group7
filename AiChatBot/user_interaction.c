#include <stdio.h>
#include <string.h>
#include "user_interaction.h"

void displayWelcomeMessage() {
    printf("Welcome to the Course FAQ Chatbot! Type 'exit' to end the conversation.\n");
}

void displayFAQ() {
    printf("\nFrequently Asked Questions:\n");
    printf("1. How many weeks is a course?\n");
    printf("2. When is the Student Success Week?\n");
    printf("3. What time are my lectures?\n");
    printf("4. When does the first semester start?\n");
    printf("5. When does it end?\n");
    printf("6. How long is each semester?\n");
    printf("7. What is the passing grade for my courses?\n");
    printf("\nYou can type the number of the question to get an answer.\n");
}

char* getUserInput() {
    static char input[100];
    printf("\nYou: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    return input;
}