#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
void Check(int index)
{
	if ((index % 3 != 0) && (index % 5 != 0))
	{
		printf("%d ", index);
	}
	else if ((index % 3 == 0) && (index % 5 != 0))
	{
		printf("Fizz ");
	}
	else if ((index % 3 != 0) && (index % 5 == 0))
	{
		printf("Buzz ");
	}
	else if ((index % 3 == 0) && (index % 5 == 0))
	{
		printf("FizzBuzz");
	}
}
void CycleCode(int num)
{
	for (int i = 1; i <= num; ++i)
	{
		Check(i);
	}
}
void Recurrent(int num, int start)
{
	if (start <= num) {
		Check(start);
		start++;
		Recurrent(num, start);
	}
	else return;
}
int main()
{
	setlocale(LC_ALL, "");
	printf("Задача: Вывести все числа от 1 до N, причем:\n если число кратно 3, то вместо него вывести Fizz;\n если кратно 5, то вывести Buzz;\n если кратно и 3, и 5, то вывести FizzBuzz\n");
	int num;
	printf("Введите любое значение n: ");
	scanf_s("%d", &num);
	printf("Решение через цикл\n");
	CycleCode(num);
	printf("\nРешение через рекурсию\n");
	Recurrent(num, 1);
	getchar();
	getchar();
	return 0;
}