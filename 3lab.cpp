#include <windows.h> 
#include <string.h> 
#include <stdio.h> 
#include <locale.h>
//memmove(tmr + 2, tmr + 1, 4);
//*(tmr + 1) = '-';
int len(char *tmr)
{
	int l = 0;
	while(*tmr)
	{
		l++;
		tmr++;
	}
	return l;
}
void slovo(char tmr[], int l)
{
	char sogl[43] = "������������������������������������������";
	char gl[23] = "���������޸���������";
	char isk[2] = "�";
	int x = strcspn(tmr, gl);
	while (*tmr)
	{
		
		if (*tmr == '�') {//��������� �� �
			if ((*(tmr + 1) == '�') || (*(tmr + 1) == '�')) {
				if (((*(tmr + 2) == '�') || (*(tmr + 2) == '�')) && (*(tmr + 4) != '�')) {
					memmove(tmr + 4, tmr + 3, l);
					*(tmr + 3) = '-';
				}
				else {
					memmove(tmr + 3, tmr + 2, l);
					*(tmr + 2) = '-';
				}
			}
			tmr += 2;
		}
		if ((*tmr == '�') || (*tmr == '�'))
		{
			if ((*(tmr+1) == '�') && (*(tmr + 2) != ' ') && (*(tmr + 3) != ' '))//��
			{
				if ((*(tmr + 2) == '�') && (*(tmr + 3) != ' ') && (*(tmr + 4) != ' '))//���
				{
					memmove(tmr + 4, tmr + 3, l);
					*(tmr + 3) = '-';
					tmr += 2;
				}
				else {
					memmove(tmr + 3, tmr + 2, l);
					*(tmr + 2) = '-';
					tmr + 2;
				}
			}
			if ((*(tmr + 1) == '�') && (*(tmr + 2) == '�') && (*(tmr + 3) == '�'))
			{
				if ((*(tmr + 4) == '�') && (*(tmr + 5) = '�') && (*(tmr + 6) == ' ') && (*(tmr + 7) == ' '))
				{
					memmove(tmr + 7, tmr + 6, l);
					*(tmr + 6) = '-';
					tmr += 6;
				}
				if ((*(tmr + 4) == '�') && (*(tmr + 6) == ' ') && (*(tmr + 7) == ' '))
				{
					memmove(tmr + 6, tmr + 5, l);
					*(tmr + 5) = '-';
					tmr += 5;
				}
			}
		}
		
		for (int i = 0; i < 23; i++)
		{

			if (*tmr == gl[i])//����� ������ �������
			{//��������� ����� 2 �����
				if (x == 0) {
					x += 1;
					break;
				}
				for (int f = 0; f < 23; f++) {
					if (*(tmr - 1) == gl[f])
					{
						break;
					}
				}
				if(*(tmr+1)=='\0')
				{
					break;
				}
				for (int f = 0; f < 43; f++)//�������� �� ���������
				{
					if (*(tmr + 1) == sogl[f])//����� ���������
					{
						for (int k = 0; k < 43; k++)
						{
							if (*(tmr + 2) == sogl[k])//���������� ���������
							{
								memmove(tmr + 3, tmr + 2, l);
								*(tmr + 2) = '-';
							}
						}
						for (int k = 0; k < 23; k++)
						{
							if ((*(tmr + 2) == gl[k])&&(*(tmr-1)!=' '))//����� �������
							{
								memmove(tmr + 2, tmr + 1, l);
								*(tmr + 1) = '-';
							}
							if ((*(tmr + 2) == gl[k]) && (*(tmr - 1) != ' '))//���������� �������
							{
								memmove(tmr + 3, tmr + 2, l);
								*(tmr + 2) = '-';
							}
						}
					}
				}
				for (int f = 0; f < 23; f++)//�������� �� �������
				{
					if ((*(tmr - 1) == '-') || (*(tmr - 1) == ' '))
					{
						break;
					}
					if (*(tmr + 1) == gl[f])//����� �������
					{
						for (int k = 0; k < 23; k++)
						{
							if (*(tmr + 2) == gl[k])//���������� �������
							{
								memmove(tmr + 3, tmr + 2, l);
								*(tmr + 2) = '-';
							}
						}
						for (int k = 0; k < 43; k++)
						{
							if (*(tmr + 2) == sogl[k]) //���������� �������
							{
								memmove(tmr + 2, tmr + 1, l);
								*(tmr + 1) = '-';
							}
						}
					}
				}

			}
		}
		if ((*tmr == '�') && (*(tmr - 1) == '-'))
		{
			memmove(tmr - 1, tmr, 1);
		}
		
		tmr++;
		if ((*tmr == '\0') && (*(tmr - 1) == '-')) {
			memmove(tmr - 1, tmr, 1);
		}
	}
}
int main() 
{
	setlocale(LC_ALL, "");
	char text[10000];
	SetConsoleCP(1251);
	gets_s(text);
	SetConsoleCP(866);
	int l = len(text);
	slovo(text, l);
	puts(text);
	getchar();
	getchar();
	return 0;
}
 
