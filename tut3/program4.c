#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *professor;
    int *student_ids, *grades;
    int num_students;

    // Allocate memory for the professor's name
    professor = (char *)calloc(256, sizeof(char)); // 256 characters
    if (professor == NULL) {
        printf("Memory allocation for professor's name failed\n");
        return 1;
    }

    // Prompt the professor for their name
    printf("Enter your name: ");
    fgets(professor, 256, stdin); // Using fgets to read string with spaces

    // Prompt for the number of students
    printf("Enter the number of students to mark: ");
    scanf("%d", &num_students);

    // Allocate memory for student IDs and grades
    student_ids = (int *)malloc(num_students * sizeof(int));
    grades = (int *)malloc(num_students * sizeof(int));
    if (student_ids == NULL || grades == NULL) {
        printf("Memory allocation for student IDs or grades failed\n");
        free(professor); // Free professor's name memory before exiting
        return 1;
    }

    // The program would normally continue to use the allocated memory here
    // Since the program doesn't need to do anything else, we'll skip to cleanup

    // Free dynamically allocated memory before terminating
    free(professor);
    free(student_ids);
    free(grades);

    printf("Memory has been successfully freed. Program is terminating.\n");

    return 0;
}
