#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable: 4996)
#define N 100

struct study
{
	char fam[255];
	char name[255];
	char otch[255];
	char angl[255];
	int group_num;
};
study s[N];
void smena(int i, int j)
{
	study tmr;
	tmr = s[i];
	s[i] = s[j];
	s[j] = tmr;
}
void sortirovka(int size)
{
	for (int i = 0; i <size - 1; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (strcmp(s[i].fam, s[j].fam) > 0)
			{
				smena(i, j);
			}
			if (strcmp(s[i].fam, s[j].fam) == 0)
			{
				if (strcmp(s[i].name, s[j].name) > 0)
				{
					smena(i, j);
				}
				if (strcmp(s[i].name, s[j].name) == 0)
				{
					if (strcmp(s[i].otch, s[j].otch) > 0)
					{
						smena(i, j);
					}
					if (strcmp(s[i].otch, s[j].otch) == 0)
					{
						if ((s[i].group_num > s[j].group_num) || (size != 1))
						{
							smena(i, j);
						}
					}
				}
			}
		}
	}
}
void pechat(study *s, int size)
{
	FILE *angl = NULL;
	FILE *nemec = NULL;
	FILE *fra = NULL;
	angl = fopen("angl.txt", "w");
	nemec = fopen("nem.txt", "w");
	fra = fopen("fran.txt", "w");
	sortirovka(size);
	for (int i = 0; i < size; i++)
	{
		if (s[i].angl[0] == 'А')
		{
			fprintf(angl, "Фамилия: %s\n", s[i].fam);
			fprintf(angl, "Имя: %s\n", s[i].name);
			fprintf(angl, "Отчество: %s\n", s[i].otch);
			fprintf(angl, "Группа: %d\n", s[i].group_num);
			fprintf(angl, "Изучаемый язык : %s\n", s[i].angl);
		}
		if (s[i].angl[0] == 'Н')
		{
			fprintf(nemec, "Фамилия: %s\n", s[i].fam);
			fprintf(nemec, "Имя: %s\n", s[i].name);
			fprintf(nemec, "Отчество: %s\n", s[i].otch);
			fprintf(nemec, "Группа: %d\n", s[i].group_num);
			fprintf(nemec, "Изучаемый язык : %s\n", s[i].angl);
		}
		if (s[i].angl[0] == 'Ф')
		{
			fprintf(fra, "Фамилия: %s\n", s[i].fam);
			fprintf(fra, "Имя: %s\n", s[i].name);
			fprintf(fra, "Отчество: %s\n", s[i].otch);
			fprintf(fra, "Группа: %d\n", s[i].group_num);
			fprintf(fra, "Изучаемый язык : %s\n", s[i].angl);
		}
	}
	fclose(angl);
	fclose(nemec);
	fclose(fra);
}
void insertperson(int size)//ДОБАВЛЕНИЕ
{
	system("cls");
	printf("Введите фамилию: ");
	SetConsoleCP(1251);
	gets_s(s[size].fam);
	SetConsoleCP(866);
	printf("Введите имя: ");
	SetConsoleCP(1251);
	gets_s(s[size].name);
	SetConsoleCP(866);
	printf("Введите отчество: ");
	SetConsoleCP(1251);
	gets_s(s[size].otch);
	SetConsoleCP(866);
	printf("Введите номер группы: ");
	scanf_s("%d", &s[size].group_num);
	getchar();
	printf("Введите изучаемый язык: ");
	SetConsoleCP(1251);
	gets_s(s[size].angl);
	SetConsoleCP(866);
	
}
int schit(study *s)//ЗАПИСЬ В СТРУКТУРУ
{
	printf("Хотите ли вы открыть уже имеющийся файл или же ввести новые данные?\n Enter - ввести данные вручную.\n Пробел - считать данные с уже имеющегося файла.");
	int key = getch();
	if ((key == 0) || (key == 224)) key = getch();
	if (key == 32) {
		FILE *student = NULL;
		printf("\nУкажите путь к файлу. Если файл лежит в корневой папке, просто укажите его название(вместе с расширением): ");
		char file[100];
		gets_s(file);
		student = fopen(file, "r");
		int size = 0;
		for (int i = 0; i < N; i++)
		{
			fscanf(student, "%s\t", s[i].fam);
			fscanf(student, "%s\t", s[i].name);
			fscanf(student, "%s\t", s[i].otch);
			fscanf(student, "%d\t", &s[i].group_num);
			fscanf(student, "%s", s[i].angl);
			if (s[i].group_num != 0) { size++; }
		}
		return size;
	}
	if (key == 13)
	{	
		int size = 0;
		while (1) {
			insertperson(size);
			size++;
			printf("Желаете добавить еще элементов? Enter - Да, Esc - Нет.");
			key = getch();
			if ((key == 0) || (key == 224))
			{
				key = getch();
			}
			if (key == 13) continue;
			if (key == 27)
			{
				printf("Введите название файла, в который будут сохранены данные(на английском вместе с расширением): ");
				char nazv[200];
				gets_s(nazv);
				FILE *nov = NULL;
				nov = fopen(nazv, "a");
				if (nazv == NULL)
				{
					printf("Ошибка создания!");
				}
				else
				{
					for (int i = 0; i < size; i++)
					{
						fprintf(nov, "Фамилия: %s\n", s[i].fam);
						fprintf(nov, "Имя: %s\n", s[i].name);
						fprintf(nov, "Отчество: %s\n", s[i].otch);
						fprintf(nov, "Группа: %d\n", s[i].group_num);
						fprintf(nov, "Изучаемый язык : %s\n", s[i].angl);
					}
					return size;
				}
			}
		}
	}
}

int menu()//МЕНЮ
{
	printf("\n\n\t\t\t\t\tВыберите одной из следующих действий\nCтрелка вправо(->): следующая запись;\nCтрелка влево(<-): предыдущая запись;\nEnter: редактировать запись;\nDel: удалить запись;\nIns: создать новую запись;\nEsc: выход из программы.");
	int key = getch();
	if ((key == 0) || (key == 244))	key = getch();
	return key;
}
int deleteperson(int i, study *s, int size)//УДАЛЕНИЕ ЗАПИСИ
{
	smena(i, size-1);
	size--;
	sortirovka(size);
	return size;
}
int vyhod()
{
	printf("\n\tВы уверены, что хотите выйти? Esc - нет, Enter - да\n");
	int key = getch();
	if ((key == 0) || (key == 224)) key = getch();
	switch (key)
	{
	case 13:
		return 0;
	case 27:
		return 1;
	}
}
void printperson(int i, study *s, int size)
{
	printf("Запись №%d из %d\nФамилия: %s\nИмя: %s\nОтчество: %s\nГруппа: %d\nИзучаемый язык: %s\n", i + 1, size,s[i].fam, s[i].name, s[i].otch, s[i].group_num, s[i].angl);
}
int reductperson(int i)
{
	int k = 0;
	printf("Enter - редактирование нынешних данных\nSpace(Пробел) - cледующие данные\nEsc - выход из меню редактирование\n");
	printf("\nФамилия: ");
	int key;
	key = getch();
	if ((key == 0)||(key==244))
	{
		key = getch();
	}
	if (key == 13)
	{
		SetConsoleCP(1251);
		gets_s(s[i].fam);
		SetConsoleCP(866);
	}
	else if (key == 27)
	{
		return k;
	}
	else
	printf("%s", s[i].fam);
	printf("\nИмя: ");
		key = getch();
		if ((key == 0)||(key==244))
		{
			key = getch();
		}
		if (key == 13)
		{
			SetConsoleCP(1251);
			gets_s(s[i].name);
			SetConsoleCP(866);
		}
		else if (key == 27)
		{
			return k;
		}
		else
		puts(s[i].name);
		printf("Отчество: ");
		key = getch();
		if ((key == 0)||(key==244))
		{
			key = getch();
		}
		if (key == 13)
		{
			SetConsoleCP(1251);
			gets_s(s[i].otch);
			SetConsoleCP(866);
		}
		else if (key == 27)
		{
			return k;
		}
		else
		puts(s[i].otch);
		printf("Группа: ");
		key = getch();
		if ((key == 0)||(key==244))
		{
			key = getch();
		}
		if (key == 13)
		{
			scanf_s("%d", &s[i].group_num);
			getchar();
		}

		else if (key == 27)
		{
			return k;
		}
		else
		printf("%d", s[i].group_num);
		printf("\nИзучаемый язык: ");
		key = getch();
		if ((key == 0)||(key==244))
		{
			key = getch();
		}
		if (key == 13)
		{
			SetConsoleCP(1251);
			gets_s(s[i].angl);
			SetConsoleCP(866);
		}
			
		else if (key == 27)
		{
			return k;
		}
		else {
			puts(s[i].angl);
			getchar();
			return k;
		}
}
int main()
{
	system("color F0");
	setlocale(LC_ALL, "");
	while (1) {
		int size = schit(s);
		sortirovka(size);
		int i = 0;
		int f = 0;
		while (1)
		{
			system("cls");
			printperson(i, s, size);
			int key = menu();
			if (key == 75) {
				if (i > 0) {
					i--;
				}
				else if (i == 0)
				{
					i = size - 1;
				}
			}
			if (key == 77) {
				if (i < size) i++;
				if (i == size)
				{
					i = 0;
				}
			}
			if (key == 82) {
				insertperson(size);
				size++;
				sortirovka(size);
			}
			if (key == 83) {
				if (size == 1)
				{
					printf("\nУдаление невозможно!");
					getchar();
					continue;
				}
				size = deleteperson(i, s, size);
			}
			if (key == 13)
			{
				int k = reductperson(i);
				sortirovka(size);
			}
			if (key == 27) {
				int m = vyhod();
				if (m == 0)
				{
					break;
				}
			}
		}
		pechat(s, size);
		printf("\nХотите ли вы выбрать другой файл?\nEnter - Да. Esc - завершение программы.");
		int m = getch();
		if ((m == 0) || (m == 224))
		{
			m = getch();
		}
		if (m == 13) continue;
		if (m == 27)
		{
			printf("\nХорошего дня!");
			getchar();
			break;
		}
	}
	getchar();
	return 0;
}