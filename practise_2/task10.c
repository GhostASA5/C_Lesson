#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    int credits;
    char professor[50];
} Course;

int main() {

    int n;
    scanf("%d", &n);

    Course* courses = (Course*)malloc(n * sizeof(Course));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", courses[i].name, &courses[i].credits, courses[i].professor);
    }

    for (int i = 0; i < n; i++) {
        printf("Course: %s\n", courses[i].name);
        printf("Credits: %d\n", courses[i].credits);
        printf("Professor: %s\n\n", courses[i].professor);
    }

}