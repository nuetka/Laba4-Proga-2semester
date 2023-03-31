#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define SIZE 50
#define TWO 2
void inputArray(int n, int A[][SIZE])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		     	scanf("%d", &A[i][j]);
}
void outputA(int n, int A[][SIZE]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", A[i][j]);
		}
	printf("\n");
	}
}
void processingArray(int n, int A[][SIZE], int B[][TWO],  int* k, int* above, int* below, int* on, int* max)
{
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag == 0) {
				*max = A[0][0];
				B[0][0] = 0; B[0][1] = 0;
				*k = 1;
				flag = 1;
			}
			else if (A[i][j] > *max) {
					*max = A[i][j];
					*k = 1;
					B[0][0] = i; B[0][1] = j;
		     	}
			else if (A[i][j] == *max) {
						B[*k][0] = i; B[*k][1] = j;
						*k += 1;
					}
		}
	}
	for (int i = 0; i < *k; i++) {
		if (B[i][0] == B[i][1]) *on += 1;
		else if (B[i][0] > B[i][1]) *below += 1;
		else if (B[i][0] < B[i][1]) *above += 1;
	}
 
}
void outputB(int B[][TWO], int* k) {
	for (int i = 0; i < *k; i++) {
		printf("(%d, %d) ", B[i][0], B[i][1]);
	    printf("\n");
	}
}
int main() {
do{
	setlocale(LC_ALL, "Rus");
	int n, A[SIZE][SIZE], B[SIZE][TWO], k, above = 0, below = 0, on = 0, max;
	printf("Введите порядок матрицы A(n * n), не больше %d: \n", SIZE); 
	do {
		scanf("%d", &n);
	} while (n <= 0);
	printf("Введите матрицу построчно: \n");
	inputArray(n, A);     
	printf("Вы ввели матрицу:\n");
	outputA(n, A);
	processingArray(n, A, B, &k, &above, &below, &on, &max);
	printf("Индексы (i, j) элементов с наибольшим значением:\n");
	outputB (B, &k);
	printf("\nНаибольшее значение: %d\n", max);
	printf("\nКоличество наибольших элементов исходной матрицы: %d\n", k);
	printf("\nКоличество наибольших элементов выше главной диагонали: %d\n", above);
	printf("\nКоличество наибольших элементов ниже главной диагонали: %d\n", below);
	printf("\nКоличество наибольших элементов на главной диагонали: %d\n", on);
	puts("Для окончания работы нажмите esc\n");
} while (_getch() != 27);
}