#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
struct List
{
	float value;
	struct List *next;
};

typedef struct List List;


void addValue(List* head, float value_)
{
	while (head->next != 0)
		head = head->next;

	head->next = (List*)malloc(sizeof(List));
	head->next->value = 1 / value_;
	head->next->value = rand() % 100 + head->next->value;
	head->next->next = 0;
}

void addValues(List* head, int count)
{
	for (int i = 0; i < count; ++i)
	{
		addValue(head, 1 + rand() % 100);
	}
}

void outputList(List* head)
{
	while (head != 0)
	{
		if (head->next == 0)
			printf("%.8f.", head->value);
		else
			printf("%.8f -> ", head->value);
		head = head->next;
	}
	printf("\n");
}

void addelem(List *head)
{
	List *temp, *p;
	temp = (List*)malloc(sizeof(List));
	p = head->next;
	head->next = temp;
	temp->next = p;
	temp->value = 1 + rand() % 100;
	temp->value = 1 / temp->value;
	temp->value = rand() % 100 + temp->value;;
}




int F(List *head, float n)
{
	int k = 0;
	while (1)
	{	
		if (head->next->value == n)
		{
			addelem(head);
			k = 1;
			break;
		}
		if (head->next->next == 0)
			break;
		head = head->next;
	}
	return k;
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));
	List *number  = (List*)malloc(sizeof(List));
	number->next = 0;
	number->value = 1 + rand() % 100;
	number->value = 1 / number->value;
	number->value = rand() % 100 + number->value;
	addValues(number, 4);
	outputList(number);
	float n;
	printf("Введите число: ");
	scanf_s("%f", &n);
	if (n == number->value)
	{
		float z;
		z = 1 + rand() % 100;
		z = 1 / z;
		z = rand() % 100 + z;
		printf("%.8f -> ", z);
		outputList(number);
		system("pause");
		exit(1);
	}
	int m;
	m = F(number, n);
	if (m == 1)
	{
		outputList(number);
	}
	else
	{
		printf("Нет такого числа!\n");
	}
	
	system("pause");
	return 0;
}