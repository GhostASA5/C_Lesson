#include <stdio.h>
#include <string.h>


float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

typedef float (*Operation)(float, float);

int main() {
    char expression[100];
    float num1, num2;
    char op;
    Operation operation = NULL;

    printf("Введите выражение: ");
    fgets(expression, sizeof(expression), stdin);

    sscanf(expression, "%f %c %f", &num1, &op, &num2);

    switch (op) {
        case '+': operation = add; break;
        case '-': operation = subtract; break;
        case '*': operation = multiply; break;
        case '/':
            if (num2 == 0) {
                printf("ОШибка. Деление на ноль.");
            }
            operation = divide;
            break;
    }

    float result = operation(num1, num2);

    printf("Результат: %.2lf\n", result);

    return 0;
}