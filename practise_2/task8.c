#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef union {
    int numericGrade;
    char letterGrade;
} Grade;

int main() {

    int n;
    scanf("%d", &n);

    Grade grades;

    for (int i = 0; i < n; i++) {
        char input;
        scanf("%c", input);

        if (isdigit(input)) {
            grades.numericGrade = input;
        } else {
            grades.letterGrade = input;
        }
    }

    // Условие не понятно. Как можно записать два значения,
    // сохранить их в одно объединение и потом вывести эти значения?
    // В объединении по определению можно хранить только одно значение в
    // один момент времени

//    for (int i = 0; i < n; i++) {
//        if (isdigit()) {
//            printf("Grade: %d\n", grades[i].numericGrade);
//        } else {
//            printf("Grade: %s\n", grades[i].letterGrade);
//        }
//    }

}