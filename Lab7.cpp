#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
struct Node {
	int day, month, year, money;
	char surname[40],name[40], patronymic[40];
	char account_number[40];
	Node *next, *prev;
};
Node* init();
Node* find_tail(Node* head);
Node* find_head(Node* head);
void print_elem(Node* elem,bool check);
Node* insert_before_curr(Node** head,Node* curr_elem, bool check);
void insert_in_tail(Node** tail);
void insert_in_tail(Node* tail, Node* ins_elem);
void delete_curr(Node** head, Node *curr);
void insert_data(Node *elem);
void print_list(Node* head, bool check);
void reduct_elem(Node* curr);
void parse_date(Node* elem);
void delete_list(Node* head);
void search_by_surname(Node* head, bool check);
void after_date(Node* head, bool check);
void swap_elem(Node** first, Node** second);
void sort(Node** head, bool(*compare)(Node*, Node*));
int work_with_elem(Node* elem, bool check);
int work_with_list();
bool compare_snp(Node* first, Node* second);
bool compare_money(Node* first, Node* second);
bool compare_date(Node* first, Node* second);
bool compare_an(Node* first, Node* second);
void sort_menu(Node** head);
void write(Node *head)
{
	FILE *wr = NULL;
	wr = fopen("output.bin", "wb");
	Node* tmp = head;
	while(tmp!=NULL)
	{
			fprintf(wr, "%s\n", tmp->surname);
			fprintf(wr, "%s\n", tmp->name);
			fprintf(wr, "%s\n", tmp->patronymic);
			fprintf(wr, "%d\n", tmp->money);
			fprintf(wr, "%s\n", tmp->account_number);
			fprintf(wr, "%d\n", tmp->day);
			fprintf(wr, "%d\n", tmp->month);
			fprintf(wr, "%d\n", tmp->year);
			tmp = tmp->next;
	}
	fclose(wr);
}
Node* read() {
	FILE *wr = NULL;
	wr = fopen("output.bin", "rb");
	Node* head = init();
	fscanf(wr, "%s\n", head->surname);
	fscanf(wr, "%s\n", head->name);
	fscanf(wr, "%s\n", head->patronymic);
	fscanf(wr, "%d\n", &head->money);
	fscanf(wr, "%s\n", head->account_number);
	fscanf(wr, "%d\n", &head->day);
	fscanf(wr, "%d\n", &head->month);
	fscanf(wr, "%d\n", &head->year);
	while (wr) {
		Node* tail = find_tail(head);
		Node* tmp = (Node*)malloc(sizeof(Node));
		fscanf(wr, "%s\n", tmp->surname);
		fscanf(wr, "%s\n", tmp->name);
		fscanf(wr, "%s\n", tmp->patronymic);
		fscanf(wr, "%d\n", &tmp->money);
		fscanf(wr, "%s\n", tmp->account_number);
		fscanf(wr, "%d\n", &tmp->day);
		fscanf(wr, "%d\n", &tmp->month);
		fscanf(wr, "%d\n", &tmp->year);
		tail->next = tmp;
		tmp->prev = tail;
		tmp->next = NULL;
		if (tmp->money == -842150451) break;
	}
	Node* tail = find_tail(head)->prev;
	free(find_tail(head));
	tail->next = NULL;
	return head;
}
int main() {
	setlocale(LC_ALL, "");
	Node* head = NULL;
	bool head_init = false;
	while (1) {
		if (head != NULL) {
			head = find_head(head);
		}
		Node* tmp = head;
		int wwl = work_with_list();
		switch (wwl) {
		case 0: {
			while (1) {
				if (head == NULL) head_init = false;
				int wwe = work_with_elem(tmp, head_init);
				switch (wwe) {
				case 0: {
					reduct_elem(tmp);
					if(tmp!=NULL) head_init = true;
				}break;
				case 1: {
					delete_curr(&head, tmp);
					if (tmp != NULL) {
						if (tmp->next != NULL && tmp -> prev != NULL) tmp = head;
					}
				}break;
				case 2: {
					if (head == NULL) {
						head = insert_before_curr(&head, tmp, head_init);
						head_init = true;
						tmp = head;
					}
					else {
						Node* tmp1 = insert_before_curr(&head, tmp, head_init);
					}
				}break;
				case 75: {
					if(head!=NULL)if (tmp->prev != NULL) tmp = tmp->prev;
				}break; 
				case 77: {
					if (head != NULL) {
					if (tmp->next != NULL) tmp = tmp->next;
				}
				}break;
				}
				if (wwe == 3) {
					break;
				}
			}
		}break;
		case 1: {

			insert_in_tail(&head);
			head_init = true;
		}break;
		case 2: {
			sort_menu(&head);
		}break;
		case 3: {
			search_by_surname(head, head_init);
		}break;
		case 4: {
			print_list(head, head_init);
		}break;
		case 5: {
			after_date(head, head_init);
		}break;
		case 6: {
			head = read();
			head_init = true;
		}break;
		case 7: {
			write(head);
		}break;
		case 8: {
			delete_list(head);
			return 0;
		}
		}
	}
	return 0;
}
Node* init() {
	Node *head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->prev = NULL;
	return head;
}
Node* find_tail(Node* head) {
	Node* tmp = head;
	if (head == NULL) {
		return head;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	return tmp;
}
void print_elem(Node* elem, bool check) {
	if (check==false) {
		printf("Список пуст!\n");
	}
	if (elem==NULL) return;
	else {
		printf("ФИО: %s %s %s\n", elem->surname, elem->name, elem->patronymic);
		printf("Номер лицевого счета: %s\n", elem->account_number);
		printf("Денег на счету: %d\n", elem->money);
		printf("Дата создания счета: %d/%d/%d\n", elem->day, elem->month, elem->year);
	}
}
Node* insert_before_curr(Node** head,Node* curr_elem, bool check) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->next = curr_elem;
	if (!check) {
		*head = init();
		insert_data(*head);
		return *head;
	}
	else if (curr_elem->prev == NULL) {
		tmp->prev = NULL;
		curr_elem->prev = tmp;
		insert_data(tmp);
		if (check==false) {
			*head = tmp;
			return tmp;
		}
	}
	else {
		Node* prev = curr_elem->prev;
		curr_elem->prev = tmp;
		tmp->prev = prev;
		prev->next = tmp;
		insert_data(tmp);
		return tmp;
	}
}
Node* find_head(Node* head) {
	while (head->prev != NULL) {
		head = head->prev;
	}
	return head;
}
void delete_curr(Node** head, Node *curr) {
	if (*head == NULL) {
		return;
	}
	else if ((*head)->next==NULL) {
		free(*head);
		*head = NULL;
	}
	else if ((*head) == curr) {
		*head = (*head)->next;
		free(curr);
		(*head)->prev = NULL;
	}
	else if (curr->next == NULL) {
		curr->prev->next = NULL;
		free(curr);
	}
	else 
	{
		Node *tmp = curr->prev;
		Node *tmp2 = curr->next;
		tmp->next = tmp2;
		tmp2->prev = tmp;
		free(curr);
	}
}
void insert_in_tail(Node** head) {
	if ((*head) == NULL) {
		(*head) = init();
		(*head)->next = NULL;
		(*head)->prev = NULL;
		insert_data(*head);
	}
	else
	{
		Node* tail = find_tail(*head);
		Node* tmp = (Node*)malloc(sizeof(Node));
		tail->next = tmp;
		tmp->prev = tail;
		tmp->next = NULL;
		insert_data(tmp);
	}
}
void insert_in_tail(Node* tail, Node* ins_elem) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tail->next = tmp;
	tmp->prev = tail;
	tmp->next = NULL;
	strcpy_s(tmp->account_number, ins_elem->account_number);
	strcpy_s(tmp->surname, ins_elem->surname);
	strcpy_s(tmp->name, ins_elem->name);
	strcpy_s(tmp->patronymic, ins_elem->patronymic);
	tmp->day = ins_elem->day;
	tmp->year = ins_elem->year;
	tmp->month = ins_elem->month;
	tmp->money = ins_elem->money;
}
void insert_data(Node *elem) {
	getchar();
	printf("Введите Фамилию: ");
	SetConsoleCP(1251);
	gets_s(elem->surname);
	SetConsoleCP(866);
	printf("Введите Имя: ");
	SetConsoleCP(1251);
	gets_s(elem->name);
	SetConsoleCP(866);
	printf("Введите отчество: ");
	SetConsoleCP(1251);
	gets_s(elem->patronymic);
	SetConsoleCP(866);
	printf("Введите номер лицевого счет: ");
	gets_s(elem->account_number);
	printf("Введите количество денег на счету: ");
	scanf_s("%d", &elem->money);
	parse_date(elem);
}
void print_list(Node* head, bool check) {
	system("cls");
	int i = 1;
	Node* tmp = head;
	do {
		printf("%d. ", i);
		print_elem(tmp, check);
		i++;
		tmp = tmp->next;
	} while (tmp!= NULL);
	getchar();
}
void reduct_elem(Node* curr) {
	if (curr == NULL) {
		return;
	}
	HANDLE hs = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hs, 5);
	int position = 0;
	while (1) {
		system("cls");
		printf("Что вы желаете изменить?");
		switch (position) {//Меню выбора изменения
		case 0: {
			SetConsoleTextAttribute(hs, 5);
			printf("Фамилия\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Имя\n");
			printf("Отчество\n");
			printf("Номер счета\n");
			printf("Дата создания\n");
			printf("Количество средств на счете: ");
		}break;
		case 1: {
			printf("Фамилия\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Имя\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Отчество\n");
			printf("Номер счета\n");
			printf("Дата создания\n");
			printf("Количество средств на счете: ");
		}break;
		case 2: {
			printf("Фамилия\n");
			printf("Имя\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Отчество\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Номер счета\n");
			printf("Дата создания\n");
			printf("Количество средств на счете: ");
		}break;
		case 3: {
			printf("Фамилия\n");
			printf("Имя\n");
			printf("Отчество\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Номер счета\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Дата создания\n");
			printf("Количество средств на счете: ");
		}break;
		case 4: {
			printf("Фамилия\n");
			printf("Имя\n");
			printf("Отчество\n");
			printf("Номер счета\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Дата создания\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Количество средств на счете: ");
		}break;
		case 5: {
			printf("Фамилия\n");
			printf("Имя\n");
			printf("Отчество\n");
			printf("Номер счета\n");
			printf("Дата создания\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Количество средств на счете: ");
			SetConsoleTextAttribute(hs, 7);
		}
		}
		int key = _getch();
		if ((key == 0) || (key == 224)) key = _getch();
		switch (key) {//Обработка нажатия
		case 72: if (position != 0) position--; break;
		case 80: if (position != 5) position++; break;
		case 13: {
			switch (position) {
			case 0: {
				system("cls");
				SetConsoleCP(1251);
				gets_s(curr->surname);
				SetConsoleCP(866);
			}break;
			case 1: {
				system("cls");
				SetConsoleCP(1251);
				gets_s(curr->name);
				SetConsoleCP(866);
			}break;
			case 2: {
				system("cls");
				SetConsoleCP(1251);
				gets_s(curr->patronymic);
				SetConsoleCP(866);
			}break;
			case 3: {
				system("cls");
				SetConsoleCP(1251);
				gets_s(curr->account_number);
				SetConsoleCP(866);
			}break;
			case 4: {
				system("cls");
				parse_date(curr);
			}break;
			case 5: {
				system("cls");
				scanf_s("%d", &curr->money);
			}
			}
		}break;
		case 27:return; break;
		default:continue; break;
		}
	}
}
void parse_date(Node* elem) {
	char *ptr;
	int num;
	do {
		char date[11];
		getchar();
		printf("Введите дату: ");
		SetConsoleCP(1251);
		gets_s(date);
		SetConsoleCP(866);
		char delim[5] = "/-.,";
		ptr = strtok(date, delim);
		num = atoi(ptr);
		if (num == 0) {
			printf("Ошибка ввода!");
			continue;
		}
		elem->day = num;
		ptr = strtok(NULL, delim);
		num = atoi(ptr);
		if (num == 0) {
			printf("Ошибка ввода!");
			continue;
		}
		elem->month = num;
		ptr = strtok(NULL, delim);
		num = atoi(ptr);
		if (num == 0) {
			printf("Ошибка ввода!");
			continue;
		}
		elem->year = num;
	} while (num == 0);
}
void delete_list(Node* head) {
	while (head != NULL) {
		Node* tmp = head;
		head = head->next;
		free(tmp);
	}
}
void search_by_surname(Node* head, bool check) {
	char inquiry[20];
	char *str;
	bool check_find = true;
	Node* temp = head;
	do {
		char exc[32] = "1234567890/.'\;][,*()_+=-&^%$#@!";
		printf("Введите фамилию поиска: ");
		SetConsoleCP(1251);
		gets_s(inquiry);
		SetConsoleCP(866);
		for (int i = 0; i < 20; i++) {
			str = strstr(inquiry, exc);
			if (str == NULL) break;
			else printf("Ошибка ввода!");
		}
	} while (str != NULL);
	while (temp != NULL) {
		char tmp[20];
		strcpy(tmp, temp->surname);
		bool check_equal = false;
			for (int i = 0; i < strlen(tmp); i++) {
				tmp[i] = tolower(tmp[i]);
				inquiry[i] = tolower(inquiry[i]);
				if (inquiry[i] != tmp[i]) {
					check_equal = false;
					break;
				}
				else {
					check_equal = true;
				}
			}
		if (check_equal == true) print_elem(temp, check);
		temp = temp->next;
	}
	getchar();
}
void after_date(Node* head, bool check) {
	char date[11];
	Node* tmp = head;
	int d, m, y;
	do {
		system("cls");
		printf("Введите дату: ");
		SetConsoleCP(1251);
		gets_s(date);
		SetConsoleCP(866);
		char delim[6] = "/-., ";
		char *ptr = strtok(date, delim);
		d = atoi(ptr);
		if (d == 0) {
			printf("Ошибка ввода");
			continue;
		}
		ptr = strtok(NULL, delim);
		m = atoi(ptr);
		if (m == 0) {
				printf("Ошибка ввода");
				continue;
		}
		ptr = strtok(NULL, delim);
		y = atoi(ptr);
		if (y == 0) {
			printf("Ошибка ввода");
			continue;
		}
		break;
	} while (1);
	int res = 0;
	Node* second_list = NULL;
	while (tmp != NULL) {
		if (y < tmp->year) {
			if (second_list == NULL) {
				second_list = init();
				strcpy_s(second_list->account_number, tmp->account_number);
				strcpy_s(second_list->surname, tmp->surname);
				strcpy_s(second_list->name, tmp->name);
				strcpy_s(second_list->patronymic, tmp->patronymic);
				second_list->day = tmp->day;
				second_list->year = tmp->year;
				second_list->month = tmp->month;
				second_list->money = tmp->money;
				res += tmp->money;
			}
			else {
				insert_in_tail(find_tail(second_list), tmp);
				res += tmp->money;
			}
		}
		else if ((y == tmp->year)&&(m<tmp->month)) {
			if (second_list == NULL) {
				second_list = init();
				strcpy_s(second_list->account_number, tmp->account_number);
				strcpy_s(second_list->surname, tmp->surname);
				strcpy_s(second_list->name, tmp->name);
				strcpy_s(second_list->patronymic, tmp->patronymic);
				second_list->day = tmp->day;
				second_list->year = tmp->year;
				second_list->month = tmp->month;
				second_list->money = tmp->money;
				res += tmp->money;
			}
			else {
				insert_in_tail(find_tail(second_list), tmp);
				res += tmp->money;
			}
		}
		else if ((y == tmp->year) && (m == tmp->month) && (d < tmp->day)) {
			if (second_list == NULL) {
				second_list = init();
				strcpy_s(second_list->account_number, tmp->account_number);
				strcpy_s(second_list->surname, tmp->surname);
				strcpy_s(second_list->name, tmp->name);
				strcpy_s(second_list->patronymic, tmp->patronymic);
				second_list->day = tmp->day;
				second_list->year = tmp->year;
				second_list->month = tmp->month;
				second_list->money = tmp->money;
				res += tmp->money;
			}
			else {
				insert_in_tail(find_tail(second_list), tmp);
				res += tmp->money;
			}
		}
		tmp = tmp->next;
	}
	sort_menu(&second_list);
	second_list = find_head(second_list);
	print_list(second_list, check);
	printf("Сумма денег на счетах: %d", res);
	getchar();
	delete_list(second_list);
}
void swap_elem(Node** first,Node** second) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	strcpy_s(tmp->account_number, (*first)->account_number);
	strcpy_s(tmp->surname, (*first)->surname);
	strcpy_s(tmp->name, (*first)->name);
	strcpy_s(tmp->patronymic, (*first)->patronymic);
	tmp->day = (*first)->day;
	tmp->year = (*first)->year;
	tmp->month = (*first)->month;
	tmp->money = (*first)->money;
	strcpy_s((*first)->account_number, (*second)->account_number);
	strcpy_s((*first)->surname, (*second)->surname);
	strcpy_s((*first)->name, (*second)->name);
	strcpy_s((*first)->patronymic, (*second)->patronymic);
	(*first)->day = (*second)->day;
	(*first)->year = (*second)->year;
	(*first)->month = (*second)->month;
	(*first)->money = (*second)->money;
	strcpy_s((*second)->account_number, tmp->account_number);
	strcpy_s((*second)->surname, tmp->surname);
	strcpy_s((*second)->name, tmp->name);
	strcpy_s((*second)->patronymic, tmp->patronymic);
	(*second)->day = tmp->day;
	(*second)->year = tmp->year;
	(*second)->month = tmp->month;
	(*second)->money = tmp->money;
}
void sort(Node** head, bool(*compare)(Node*,Node*)) {
	if (*head == NULL) {
		return;
	}
	while ((*head)->next != NULL) {
		Node* temp = (*head)->next;
		while (temp != NULL) {
			if (!compare(*head, temp)) {
				swap_elem(head, &temp);
			}
			temp = temp->next;
		}
		*head = (*head)->next;
	}
}
void sort_menu(Node** head) {
	HANDLE hs = GetStdHandle(STD_OUTPUT_HANDLE);
	int position = 0;
	while (1) {
		system("cls");
		switch (position) {
		case 0: {
			SetConsoleTextAttribute(hs, 5);
			printf("Сортировать по ФИО\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Сортировать по номеру счета\n");
			printf("Сортировать по дате\n");
			printf("Сортирова по количеству средств на счете\n");
		}break;
		case 1: {
			printf("Сортировать по ФИО\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Сортировать по номеру счета\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Сортировать по дате\n");
			printf("Сортирова по количеству средств на счете\n");
		}break;
		case 2: {
			printf("Сортировать по ФИО\n");
			printf("Сортировать по номеру счета\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Сортировать по дате\n");
			SetConsoleTextAttribute(hs, 7);
			printf("Сортирова по количеству средств на счете\n");
		}break;
		case 3: {
			printf("Сортировать по ФИО\n");
			printf("Сортировать по номеру счета\n");
			printf("Сортировать по дате\n");
			SetConsoleTextAttribute(hs, 5);
			printf("Сортирова по количеству средств на счете\n");
			SetConsoleTextAttribute(hs, 7);
		}break;
		}
		int key = _getch();
		if (key == 0 || key == 224)key = _getch();
		switch (key) {
		case 72: {
			if (position != 0)position--;
		}break;
		case 80: {
			if (position != 3)position++;
		}break;
		case 27: {
			return;
		}break;
		}
		if (key == 13) break;
	}
		switch (position) {
		case 0: {
			sort(head, compare_snp);
		}break;
		case 1: {
			sort(head, compare_an);
		}break;
		case 2: {
			sort(head, compare_date);
		}break;
		case 3: {
			sort(head, compare_money);
		}break;
	}
}
bool compare_snp(Node* first, Node* second) {
	if (strcmp(first->surname, second->surname) > 0) {
		return 0;
	}
	else if (strcmp(first->surname, second->surname) == 0 && strcmp(first->name, second->name) > 0) {
		return 0;
	}
	else if (strcmp(first->surname, second->surname) == 0 && strcmp(first->name, second->name) == 0 && strcmp(first->patronymic, second->patronymic) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
bool compare_money(Node* first, Node* second) {
	if (first->money > second->money) {
		return 0;
	}
	else {
		return 1;
	}
}
bool compare_date(Node* first, Node* second) {
	if (first->year > second->year) {
		return 0;
	}
	else if (first->year == second->year && first->month > second->month) {
		return 0;
	}
	else if (first->year == second->year && first->month == second->month && first->day > second->day) {
		return 0;
	}
	else {
		return 1;
	}
}
bool compare_an(Node* first, Node* second) {
	if (strcmp(first->account_number, second->account_number) > 0) {
		return 0;
	}
	else {
		return 1;
	}
}
int work_with_list() {
	HANDLE hs = GetStdHandle(STD_OUTPUT_HANDLE);
	int position = 0;
	while (1) {
		system("cls");
		switch (position) {
		case 0: {
			SetConsoleTextAttribute(hs, 5);
			printf("1. Работа с элементами\n");
			SetConsoleTextAttribute(hs, 7);
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 1: {
			printf("1. Работа с элементами\n");
			SetConsoleTextAttribute(hs, 5);
			printf("2. Добавить элемент в конец списка\n");
			SetConsoleTextAttribute(hs, 7);
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 2: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			SetConsoleTextAttribute(hs, 5);
			printf("3. Сортировка \n");
			SetConsoleTextAttribute(hs, 7);
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 3: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			SetConsoleTextAttribute(hs, 5);
			printf("4. Поиск по фамилии\n");
			SetConsoleTextAttribute(hs, 7);
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 4: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			SetConsoleTextAttribute(hs, 5);
			printf("5. Открыть весь список\n");
			SetConsoleTextAttribute(hs, 7);
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 5: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			SetConsoleTextAttribute(hs, 5);
			printf("6. Открыть список открытых счетов после даты\n");
			SetConsoleTextAttribute(hs, 7);
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 6: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			SetConsoleTextAttribute(hs, 5);
			printf("7. Считать из файла\n");
			SetConsoleTextAttribute(hs, 7);
			printf("8. Сохранить в файл\n");
			printf("9. Закрыть программу\n");
		}break;
		case 7: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			SetConsoleTextAttribute(hs, 5);
			printf("8. Сохранить в файл\n");
			SetConsoleTextAttribute(hs, 7);
			printf("9. Закрыть программу\n");
		}break;
		case 8: {
			printf("1. Работа с элементами\n");
			printf("2. Добавить элемент в конец списка\n");
			printf("3. Сортировка \n");
			printf("4. Поиск по фамилии\n");
			printf("5. Открыть весь список\n");
			printf("6. Открыть список открытых счетов после даты\n");
			printf("7. Считать из файла\n");
			printf("8. Сохранить в файл\n");
			SetConsoleTextAttribute(hs, 5);
			printf("9. Закрыть программу\n");
			SetConsoleTextAttribute(hs, 7);
		}break;
		}
		int key = _getch();
		if ((key == 0) || (key == 224)) key = _getch();
		switch (key) {
		case 72:if (position != 0) position--; break;
		case 80:if (position != 8) position++; break;
		case 13: return position;
		default:continue; break;
		}
	}
}
int work_with_elem(Node* elem, bool check) {
	HANDLE hs = GetStdHandle(STD_OUTPUT_HANDLE);
	int position = 0;
	while (1) {
		system("cls");
		print_elem(elem,check);
		switch (position) {
		case 0: {
			SetConsoleTextAttribute(hs, 5);
			printf("1.Редактировать элемент\n");
			SetConsoleTextAttribute(hs, 7);
			printf("2.Удалить элемент\n");
			printf("3.Вставить элемент перед текущим\n");
			printf("4.Выйти в предыдущее меню\n");
		}break;
		case 1: {
			printf("1.Редактировать элемент\n");
			SetConsoleTextAttribute(hs, 5);
			printf("2.Удалить элемент\n");
			SetConsoleTextAttribute(hs, 7);
			printf("3.Вставить элемент перед текущим\n");
			printf("4.Выйти в предыдущее меню\n");
		}break;
		case 2: {
			printf("1.Редактировать элемент\n");
			printf("2.Удалить элемент\n");
			SetConsoleTextAttribute(hs, 5);
			printf("3.Вставить элемент перед текущим\n");
			SetConsoleTextAttribute(hs, 7);
			printf("4.Выйти в предыдущее меню\n");
		}break;
		case 3: {
			printf("1.Редактировать элемент\n");
			printf("2.Удалить элемент\n");
			printf("3.Вставить элемент перед текущим\n");
			SetConsoleTextAttribute(hs, 5);
			printf("4.Выйти в предыдущее меню\n");
			SetConsoleTextAttribute(hs, 7);
		}break;
		}
		int key = _getch();
		if ((key == 0) || (key == 224)) key = _getch();
		switch (key) {
		case 72:if (position != 0)position--; break;
		case 80:if (position != 3)position++; break;
		case 13: return position;break;
		case 75: return 75; break;
		case 77: return 77; break;
		default:continue; break;
		}
	}
}