#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
struct Node
{
	double value;
	struct Node *next;
};
Node* init()
{
	Node* head=(Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->value = 0;
	return head;
}
int get_size()
{
	system("cls");
	int size;
	printf("Введите размерность списка: ");
	scanf_s("%d", &size);
	return size;
}
double get_value(int index) {
	system("cls");
	double value;
	printf("%d = ", index);
	scanf_s("%lf", &value);
	return value;
}
double get_value()
{
	system("cls");
	double value;
	printf("Введите значение: ");
	scanf_s("%lf", &value);
	return value;
}
void delete_element(Node *head)
{
	system("cls");
	int index_of_deleted;
	printf("Введите номер удаляемого элемента: ");
	scanf_s("%d", &index_of_deleted);
	index_of_deleted--;
	Node *temp, *tempdel;
	temp = head;
	for (int i = 0; i < index_of_deleted - 1; i++) temp = temp->next;
	tempdel = temp->next;
	temp->next = tempdel->next;
	free(tempdel);
}
void add_element_in_tail(Node *tail, double value)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	tail->next = temp;
	temp->next = NULL;
	temp->value = value;
}
Node* find_tail(Node* head)
{
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}
int main_menu(bool check)
{
	system("cls");
	int position = 0;
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1)
	{
		if (position == 0)
		{
			SetConsoleTextAttribute(hc, 4);
			printf("1.Работа с данными\n");
			SetConsoleTextAttribute(hc, 15);
			printf("2.Очистить и начать работу с новыми данными\n");
			printf("3.Завершить работу\n");
		}
		if (position == 1)
		{
			printf("1.Работа с данными\n");
			SetConsoleTextAttribute(hc, 4);
			printf("2.Очистить и начать работу с новыми данными\n");
			SetConsoleTextAttribute(hc, 15);
			printf("3.Завершить работу\n");
		}
		if (position == 2)
		{
			printf("1.Работа с данными\n");
			printf("2.Очистить и начать работу с новыми данными\n");
			SetConsoleTextAttribute(hc, 4);
			printf("3.Завершить работу\n");
			SetConsoleTextAttribute(hc, 15);
		}
		int key = _getch();
		if ((key == 0) || (key == 224))
		{
			key = _getch();
		}
		switch (key)
		{
		case 72:
		{
			if (position != 0) position--;
		} break;
		case 80:
		{
			if (position != 2) position++;

		} break;
		case 13:
		{
			if (check==true) return position;
			else if((check==false)&&(position==1)) ("Вы еще не начинали работу!");
		}break;
		default: continue;
		}
		system("cls");
	}
}
int date_menu()
{
	system("cls");
	int position = 0;
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1)
	{
		if (position == 0)
		{
			SetConsoleTextAttribute(hc, 4);
			printf("1.Задать размер списка\n");
			SetConsoleTextAttribute(hc, 15);
			printf("2.Задать значение элементов\n");
			printf("3.Добавить элемент\n");
			printf("4.Удалить элемент\n");
			printf("5.Вывести список на экран\n");
			printf("6.Результирующий список\n");
			printf("7.Выход в главное меню\n");
		}
		if (position == 1)
		{
			printf("1.Задать размер списка\n");
			SetConsoleTextAttribute(hc, 4);
			printf("2.Задать значение элементов\n");
			SetConsoleTextAttribute(hc, 15);
			printf("3.Добавить элемент\n");
			printf("4.Удалить элемент\n");
			printf("5.Вывести список на экран\n");
			printf("6.Результирующий список\n");
			printf("7.Выход в главное меню\n");
		}
		if (position == 2)
		{
			printf("1.Задать размер списка\n");
			printf("2.Задать значение элементов\n");
			SetConsoleTextAttribute(hc, 4);
			printf("3.Добавить элемент\n");
			SetConsoleTextAttribute(hc, 15);
			printf("4.Удалить элемент\n");
			printf("5.Вывести список на экран\n");
			printf("6.Результирующий список\n");
			printf("7.Выход в главное меню\n");
		}
		if (position == 3)
		{
			printf("1.Задать размер списка\n");
			printf("2.Задать значение элементов\n");
			printf("3.Добавить элемент\n");
			SetConsoleTextAttribute(hc, 4);
			printf("4.Удалить элемент\n");
			SetConsoleTextAttribute(hc, 15);
			printf("5.Вывести список на экран\n");
			printf("6.Результирующий список\n");
			printf("7.Выход в главное меню\n");
		}
		if (position == 4)
		{
			printf("1.Задать размер списка\n");
			printf("2.Задать значение элементов\n");
			printf("3.Добавить элемент\n");
			printf("4.Удалить элемент\n");
			SetConsoleTextAttribute(hc, 4);
			printf("5.Вывести список на экран\n");
			SetConsoleTextAttribute(hc, 15);
			printf("6.Результирующий список\n");
			printf("7.Выход в главное меню\n");
		}
		if (position == 5)
		{
			printf("1.Задать размер списка\n");
			printf("2.Задать значение элементов\n");
			printf("3.Добавить элемент\n");
			printf("4.Удалить элемент\n");
			printf("5.Вывести список на экран\n");
			SetConsoleTextAttribute(hc, 4);
			printf("6.Результирующий список\n");
			SetConsoleTextAttribute(hc, 15);
			printf("7.Выход в главное меню\n");
		}
		if (position == 6)
		{
			printf("1.Задать размер списка\n");
			printf("2.Задать значение элементов\n");
			printf("3.Добавить элемент\n");
			printf("4.Удалить элемент\n");
			printf("5.Вывести список на экран\n");
			printf("6.Результирующий список\n");
			SetConsoleTextAttribute(hc, 4);
			printf("7.Выход в главное меню\n");
			SetConsoleTextAttribute(hc, 15);
		}
		int key = _getch();
		if ((key == 0) || (key == 224))
		{
			key = _getch();
		}
		switch (key)
		{
		case 72:
		{
			if (position != 0) position--;
		} break;
		case 80:
		{
			if (position != 6) position++;

		} break;
		case 13:
		{
			system("cls");
			return position;
		}
		default: continue;
		}
		system("cls");
	}
}
void restart_work()
{

}
int choose_list()
{
	system("cls");
	int position = 0;
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1)
	{
		if (position == 0)
		{
			printf("Выберите список\n");
			SetConsoleTextAttribute(hc, 4);
			printf("A\n");
			SetConsoleTextAttribute(hc, 15);
			printf("B");
		}
		if (position == 1)
			{
				printf("Выберите список\n");
				printf("A\n");
				SetConsoleTextAttribute(hc, 4);
				printf("B");
				SetConsoleTextAttribute(hc, 15);
			}
			int key = _getch();
			if ((key == 0) || (key == 224)) key = _getch();
			switch (key)
			{
			case 72:if (position == 1)position--; break;
			case 80:if (position == 0)position++; break;
			case 13: return position; break;
			}
			system("cls");
	}
}
void print_list(Node *head)
{
	system("cls");
	Node *temp = head;
	if (head == NULL)
	{
		printf("Список пуст!");
	}
	else {
		do {
			printf("| %lf |", temp->value);
			temp = temp->next;
		} while (temp != NULL);
	}
	getchar();
	getchar();
}
Node* create_third(Node* headfirst, Node* headsecond)
{
	int index = -1;
	Node* head = init();
	Node* tempfirst = headfirst, *tempsecond = headsecond;
	head->value = tempfirst->value;
	tempfirst = tempfirst->next;
	while (1)
	{
		index++;
		if ((tempfirst == NULL) && (tempsecond == NULL)) break;
		if (index % 2 != 0){
			if (tempfirst != NULL) {
				add_element_in_tail(find_tail(head), tempfirst->value);
			}
			else if (tempfirst == NULL) {
				add_element_in_tail(find_tail(head), 0);
				continue;
			}
			if (tempfirst->next != NULL) {
				tempfirst = tempfirst->next;
			}
			else if (tempfirst->next == NULL) {
				tempfirst = NULL;
			}
		}
		if (index % 2 == 0) {
			if (tempsecond != NULL) {
				add_element_in_tail(find_tail(head), tempsecond->value);
			}
			else if (tempsecond == NULL) {
				add_element_in_tail(find_tail(head), 0);
				continue;
			}
			if (tempsecond->next != NULL) {
				tempsecond = tempsecond->next;
			}
			else if (tempsecond->next == NULL) {
				tempsecond = NULL;
			}
		}
	}
	return head;
}
void delete_list(Node* head)
{
	Node* tmp = head;
	while (tmp != NULL)
	{
		Node* tmp =	head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
int main()
{
	setlocale(LC_ALL, "");
	while (1)
	{
		bool flag_work = true, flag_sizeA=true,flag_sizeB=true;
		int work;
		int first_key = main_menu(flag_work);
		Node* headA = init();
		Node* headB = init();
		Node* headC = init();
		int sizeA, sizeB;
		while (1) {
			switch (first_key)
			{
			case 0: work = date_menu(); break;
			case 1:
			{
				restart_work();
				work = date_menu();
			}break;
			case 2: return 0; break;
			}
				switch (work)
				{
					case 0: {
								switch (choose_list())
								{
								case 0: {
									if (flag_sizeA==true) {
										sizeA = get_size();
										flag_sizeA = false;
									}
									else {
										printf("Размерность уже введена!");
										getchar();
									}
								}break;
								case 1: {
										if (flag_sizeB == true) {
											sizeB = get_size();
											flag_sizeB = false;
										}
										else {
											printf("Размерность уже введена!");
											getchar();
										}
								}break;
								}
							}; break;
					case 1: {
								switch (choose_list()) {
								case 0: {
									if (flag_sizeA == true)
									{
										printf("Ошибка, введите размерность!");
										getchar();
									}
									else {
										for (int i = 0; i < sizeA; i++)
										{
											double val = get_value(i + 1);
											if (i == 0) {
												headA->value = val;
											}
											else {
												Node* tailA = find_tail(headA);
												add_element_in_tail(tailA, val);
											}
										}
									}
								} break;
								case 1: {
									if (flag_sizeB) {
										printf("Ошибка, введите размерность!");
										getchar();
									}
									else {
										for (int i = 0; i < sizeB; i++)
										{
											double val = get_value(i + 1);
											if (i == 0) {
												headB->value = val;
											}
											else {
												Node* tailB = find_tail(headB);
												add_element_in_tail(tailB, val);
											}
										}
									}
								} break;
								}
					}; break;
					case 2: {
						switch (choose_list())
						{
						case 0: {
							add_element_in_tail(find_tail(headA), get_value());
							sizeA++;
						} break;
						case 1: {
							add_element_in_tail(find_tail(headB), get_value());
							sizeB++;
						} break;
						}
					}; break;
					case 3: {
						switch (choose_list())
						{
						case 0: {
							delete_element(headA);
						} break;
						case 1: {				
							delete_element(headB);
						} break;
						}
					}; break;
					case 4: {
						switch (choose_list())
						{
						case 0: print_list(headA); break;
						case 1: print_list(headB); break;
						}
					}; break;
					case 5: {
						headC = create_third(headA, headB);
						print_list(headC);
					}; break;
					case 6:break; break;
				}
		}
		system("cls");
		delete_list(headA);
		delete_list(headB);
		delete_list(headC);
	}
	return 0;
}