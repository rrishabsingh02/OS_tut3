#include <stdlib.h>
#include <stdio.h>

// Define the student struct
typedef struct {
    int id;
    int age;
    int startYear;
} student;

// Function to save student data to a file
void save_student(student s) {
    FILE *file = fopen("students.txt", "a"); // Open the file in append mode
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%d,%d,%d\n", s.id, s.age, s.startYear); // Write data to the file
    fclose(file); // Close the file
}

int main(void) {
    student s; // Declare a student struct

    // Prompt the user for their student id, age, and the year they started at UOIT
    printf("Enter your student ID: ");
    scanf("%d", &s.id);
    printf("Enter your age: ");
    scanf("%d", &s.age);
    printf("Enter the year you started at UOIT: ");
    scanf("%d", &s.startYear);

    // Call the save_student function to save the data
    save_student(s);

    printf("Student information saved.\n");

    return 0;
}
