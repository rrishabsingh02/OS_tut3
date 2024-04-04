#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Declare an array to store the ten integers
    int numbers[10];
    
    // Open the file for reading
    FILE *file = fopen("question2.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1; // Return with error code
    }
    
    // Read the ten integers from the file
    for (int i = 0; i < 10; i++) {
        // Check if fscanf was able to read an integer
        if (fscanf(file, "%d", &numbers[i]) != 1) {
            printf("Error reading integer from file\n");
            fclose(file); // Close the file before returning
            return 1; // Return with error code
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print the contents of the array
    printf("Contents of the array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", numbers[i]);
    }
    
    return 0;
}
