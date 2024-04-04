#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Declare variables to store the user's first name, age, and height
    char firstName[100]; // Assuming the first name will not exceed 99 characters
    int age;
    float height;

    // Prompt the user for their first name, age, and height
    printf("Enter your first name: ");
    scanf("%99s", firstName); // Use %99s to prevent buffer overflow
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    // Print the inputs back to the console
    printf("Name: %s, Age: %d, Height: %.2f meters\n", firstName, age, height);

    return 0;
}
