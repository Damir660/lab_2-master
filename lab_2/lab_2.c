#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <Locale.h>
#define m 1000 // строковая константа "число столбцов"
#define n m // строковая константа "число строк"

int main(void)
{
    setlocale(LC_ALL, "Russian");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end; // объявляем переменные для определения времени выполнения

    int i = 0, j = 0, r;
    int elem_c;

    int** one = (int**)malloc(n * sizeof(int*)); // выделяем память под динамический двумерный массив a[n][m]
    for (int i = 0; i < n; i++)
    {
        one[i] = (int*)malloc(m * sizeof(int));
    }

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    while (i < n)
    {
        j = 0; // сбрасываем j для каждой строки
        while (j < m)
        {
            one[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
            j++;
        }
        i++;
    }

    int** two = (int**)malloc(n * sizeof(int*)); // выделяем память под динамический двумерный массив b[n][m]
    for (int i = 0; i < n; i++)
    {
        two[i] = (int*)malloc(m * sizeof(int));
    }

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    i = 0;
    while (i < n)
    {
        j = 0; // сбрасываем j для каждой строки
        while (j < m)
        {
            two[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
            j++;
        }
        i++;
    }

    int** tree = (int**)malloc(n * sizeof(int*)); // выделяем память под динамический двумерный массив c[n][m]
    for (int i = 0; i < n; i++)
    {
        tree[i] = (int*)malloc(m * sizeof(int));
    }

    start = clock(); // в переменную start записываем время от начала запуска программы

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            elem_c = 0;
            for (r = 0; r < n; r++)
            {
                elem_c += one[i][r] * two[r][j];
            }
            tree[i][j] = elem_c;
        }
    }

    end = clock(); // в переменную end записываем время от начала запуска программы
    float time = (float)(end - start) / CLOCKS_PER_SEC; // вычисляем разность(т.е. время, затраченное на умножение матриц)
    float milliseconds = time * 1000; // переводим время в миллисекунды

    printf("Время выполнения: %.2f ms (%.2f s)\n", milliseconds, time); // выводим результат работы программы

    for (int i = 0; i < n; i++) // очищаем память динамического двумерного массива a[n][m]
    {
        free(one[i]);
    }
    free(one);

    for (int i = 0; i < n; i++) // очищаем память динамического двумерного массива b[n][m]
    {
        free(two[i]);
    }
    free(two);

    for (int i = 0; i < n; i++) // очищаем память динамического двумерного массива c[n][m]
    {
        free(tree[i]);
    }
    free(tree);

    return 0;
}