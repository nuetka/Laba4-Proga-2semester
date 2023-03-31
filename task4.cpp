#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define SIZE 50
#define TWO 2
void inputArray(int n, int *a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", a++);
}
void outputA(int n, int *a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", *(a + i * n + j));
		}
		printf("\n");
	}
}
void processingArray(int n, int* a, int* b, int* k, int* above, int* below, int* on, int* max)
{
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag == 0) {
				*max = *a;
				*b = 0; *(b + 1) = 0;//B[0][0] = 0; B[0][1] = 0;
				*k = 1;
				flag = 1;
			}
			else if (*(a + i*n + j) > *max) {// (A[i][j] > *max) {
				*max = *(a + i * n + j);
				*k = 1;
				*b = i; *(b + 1) = j;
			}
			else if (*(a + i * n + j) == *max) {
				*(b + *k * 2) = i; *(b + * k * 2 + 1) = j;//B[*k][0] = i; B[*k][1] = j;
				*k += 1;
			}
		}
	}
	for (int i = 0; i < *k; i++) {
		if (*(b+i*2)==*(b+i*2+1))  *on += 1;//(B[i][0] == B[i][1])
		else if (*(b + i * 2) > *(b + i * 2 + 1))  *below += 1;
		else if (*(b + i * 2) < *(b + i * 2 + 1))  *above += 1;
	}
}
void outputB(int *b, int* k) {
	for (int i = 0; i < *k; i++) {
		printf("(%d, %d) ", *(b + i * 2 + 0), *(b + i * 2 + 1));// B[i][0], B[i][1]); *(a + i * m + j)
		printf("\n");
	}
}
int main() {
	do {
		setlocale(LC_ALL, "Rus");
		int n, A[SIZE][SIZE], B[SIZE][TWO], k, above = 0, below = 0, on = 0, max;
		printf("Введите порядок матрицы A(n * n), не больше %d: \n", SIZE);
		do {
			scanf("%d", &n);
	    } while (n <= 0);
		printf("Введите матрицу построчно: \n");
		inputArray(n, &A[0][0]);
		printf("Вы ввели матрицу:\n");
		outputA(n, &A[0][0]);
		processingArray(n, &A[0][0], &B[0][0], &k, &above, &below, &on, &max);
		printf("Индексы (i, j) элементов с наибольшим значением:\n");
		outputB(&B[0][0], &k);
		printf("\nНаибольшее значение: %d\n", max);
		printf("\nКоличество наибольших элементов исходной матрицы: %d\n", k);
		printf("\nКоличество наибольших элементов выше главной диагонали: %d\n", above);
		printf("\nКоличество наибольших элементов ниже главной диагонали: %d\n", below);
		printf("\nКоличество наибольших элементов на главной диагонали: %d\n", on);
		puts("Для окончания работы нажмите esc\n");
	} while (_getch() != 27);
}