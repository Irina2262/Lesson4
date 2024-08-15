/*
Задание 2. Обратная польская запись
Написать алгоритм перевода из инфиксной записи в обратную польскую. Для
его реализации нужны данные по приоритетам операций. Реализовать
алгоритм, используя побитовые операции (&, |, ^)
 */


#include <stdio.h>
#include <ctype.h>  // для функции isdigit()

#define MAX_SIZE 100

// Функция для получения приоритета оператора
int getPriority(char op) {
    switch (op) {
        case '|': return 1;
        case '^': return 2;
        case '&': return 3;
        case '(': return 0;
    }
    return -1; // В случае неопознанного оператора
}

// Функция для перевода инфиксной записи в обратную польскую
void infixToPostfix(const char* expression, char* output) {
    char stack[MAX_SIZE];
    int top = -1;
    int index = 0;
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        // Если токен - операнд (цифра или буква), добавляем его к выходной строке
        if (isalnum(token)) {
            output[index++] = token;
        }
        // Если токен - открывающая скобка, помещаем ее в стек
        else if (token == '(') {
            stack[++top] = token;
        }
        // Если токен - закрывающая скобка, извлекаем из стека до открывающей скобки
        else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                output[index++] = stack[top--];
            }
            top--; // Удаляем '(' из стека
        }
        // Если токен - оператор
        else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(token)) {
                output[index++] = stack[top--];
            }
            stack[++top] = token;
        }
    }

    // Извлекаем все оставшиеся операторы из стека
    while (top != -1) {
        output[index++] = stack[top--];
    }

    output[index] = '\0'; // Завершаем строку
}

int main() {
    const char* expression = "a|b&c^d";
    char output[MAX_SIZE];

    infixToPostfix(expression, output);

    printf("Postfix expression: %s\n", output);

    return 0;
}
