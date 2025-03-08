#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {

    int n;
    scanf("%d", &n);

    Student* students = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }

    for (int i = 0; i < n; i++) {
        Student* studentPtr = &students[i];
        printf("Name: %s\n", studentPtr->name);
        printf("Age: %d\n", studentPtr->age);
        printf("GPA: %.2f\n\n", studentPtr->gpa);
    }

    free(students);
}