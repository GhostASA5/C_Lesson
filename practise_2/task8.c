#include <stdio.h>
#include <stdlib.h>


typedef union {
    int numericGrade;
    char letterGrade;
} Grade;

int main() {

    int n;
    scanf("%d", &n);

    Grade* grades = (Grade *) malloc(sizeof(Grade));

    for (int i = 0; i < n; i++) {
        char input[5];
        scanf("%s", input);

        if (input[0] >= '0' && input[0] <= '9') {
            grades[i].numericGrade = atoi(input);
        } else {
            grades[i].letterGrade = input[0];
        }
    }

    for (int i = 0; i < n; i++) {
        if (grades[i].numericGrade >= 0 && grades[i].numericGrade <= 100) {
            printf("Grade: %d\n", grades[i].numericGrade);
        } else {
            printf("Grade: %c\n", grades[i].letterGrade);
        }
    }

    free(grades);
}