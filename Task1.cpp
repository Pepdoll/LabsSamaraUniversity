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
	printf("������: ������� ��� ����� �� 1 �� N, ������:\n ���� ����� ������ 3, �� ������ ���� ������� Fizz;\n ���� ������ 5, �� ������� Buzz;\n ���� ������ � 3, � 5, �� ������� FizzBuzz\n");
	int num;
	printf("������� ����� �������� n: ");
	scanf_s("%d", &num);
	printf("������� ����� ����\n");
	CycleCode(num);
	printf("\n������� ����� ��������\n");
	Recurrent(num, 1);
	getchar();
	getchar();
	return 0;
}