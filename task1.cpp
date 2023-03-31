#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale>
double func1 (double x, double e) {
	int  twos = 2 * 2, k = 2, count = 0, s = 1;
	double y = 0, current, numerator = x * x, denomenator = twos * k;
	current = (numerator) / denomenator;
	while (fabs(current) > e) {
		y = y + current;
		s = -1 * s;
		twos = twos * 2 * 2;
		count += 1;
		k = k * count * (count + 2);
		numerator = numerator * x * x;
		denomenator = twos * k;
		current = s * (numerator / denomenator);
	}
	return y;
}
double func2(double x, double e) {
	int s = -1, fact = 6, k = 3;
	double y = 0, current = x, numerator = x*x*x, denomenator;
	denomenator = 18;
	while (fabs(current) > e) {
		y = y + current;
		current = s * (numerator/denomenator);
		numerator = numerator * x * x;
		k += 2;
		fact = fact * k *(k - 1);
		denomenator = fact * k;
		s = s * (-1);
	}
	return y;
}
void func3(double x, double y, int n) {
	printf("Для функции №%d при x=%lf y=%lf!", n, x, y);
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	double x, e, y;
do{
	do {
		printf("Введите номер функции, x, точность: \n");
		scanf("%d%lf%lf", &n, &x, &e);
		if (n!=1 && n!=2) {
		    printf("ошибка ввода. попробуйте снова!\n");
		}
	} while (n!=1 && n!=2);
	if (n == 1) y = func1(x, e); else y = func2(x, e);	
	func3(x, y, n);
	puts("Для выхода нажмите esc, для продолжения другую клавишу!\n");
	} while (_getch() != 27);
}