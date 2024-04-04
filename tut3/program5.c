#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int student_id;
    int mark;
} grade;

void grade_students(grade *grades, int num_students) {
    FILE *file = fopen("grades.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    int sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += grades[i].mark;
        fprintf(file, "Student ID: %d, Mark: %d\n", grades[i].student_id, grades[i].mark);
    }

    double average = (double)sum / num_students;
    double variance = 0;
    for (int i = 0; i < num_students; i++) {
        variance += pow(grades[i].mark - average, 2);
    }
    double stddev = sqrt(variance / num_students);

    fprintf(file, "Average: %.2f, Standard Deviation: %.2f\n", average, stddev);
    fclose(file);
}

int main(void) {
    char *professor = (char *)calloc(256, sizeof(char));
    if (professor == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter your name: ");
    fgets(professor, 256, stdin);
    professor[strcspn(professor, "\n")] = 0; // Remove newline character

    int num_students;
    printf("Enter the number of students to mark: ");
    scanf("%d", &num_students);

    grade *grades = (grade *)malloc(num_students * sizeof(grade));
    if (grades == NULL) {
        printf("Memory allocation failed\n");
        free(professor);
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        printf("Enter student ID and mark for student %d: ", i + 1);
        scanf("%d %d", &grades[i].student_id, &grades[i].mark);
    }

    grade_students(grades, num_students);

    free(professor);
    free(grades);
    printf("Grading complete. Memory freed.\n");

    return 0;
}
