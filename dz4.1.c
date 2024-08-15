/*
 Задание 1. Биномиальный коэффициент
Реализовать программу 1-го практического задания с помощью
биномиального коэффициента.
Данные на вход: Два целых числа N и M
Данные на выход: Одно целое число – количество вариантов
 */


#include <stdio.h>

// Функция для вычисления факториала числа
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция для вычисления биномиального коэффициента C(N, M)
unsigned long long binomial_coefficient(int N, int M) {
    if (M > N) {
        return 0;  // Если M больше N, то результат 0, так как это невозможно
    }
    unsigned long long numerator = factorial(N);
    unsigned long long denominator = factorial(M) * factorial(N - M);
    return numerator / denominator;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    unsigned long long result = binomial_coefficient(N, M);
    printf("%llu\n", result);

    return 0;
}
