#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>


#define MAX_LENGHT 128

typedef struct Computer
{
	char *login;
	char *password;
	union
	{
	int number;
	};
	Computer *nextelement;
} Computer;

void outComputer(Computer *computer)
{
	printf_s("{number: %d, login: \"%s\", password: \"%s\"}\n",
		computer->number, computer->login, computer->password);
}

void freeComputersArray(Computer** computers, unsigned size)
{
	unsigned i;
	for (i = 0; i < size; i++) 
	{
		free((*computers)[i].login);
		free((*computers)[i].password);
	}
	free(*computers);
}

void creadComputers(unsigned size, Computer** computers)
{
	*computers = (Computer*)malloc(size * sizeof(Computer));
}

void inComputers(Computer** computers, unsigned size, char buffer[128], char buffer1[128])
{
	unsigned i;
	for (i = 0; i < size; i++)
	{
		printf_s("Number #%d \n  login: ", i);
		rewind(stdin);
		gets_s(buffer1, MAX_LENGHT);
		OemToAnsi(buffer1,buffer);
		(*computers)[i].number = i;
		(*computers)[i].login = (char*)malloc(strlen(buffer) + 1);
		strcpy((*computers)[i].login, buffer);

		printf_s("  password: ");
		rewind(stdin);
		gets_s(buffer1, MAX_LENGHT);
		OemToAnsi(buffer1, buffer);
		(*computers)[i].password = (char*)malloc(strlen(buffer) + 1);
		strcpy((*computers)[i].password, buffer);
	}
}

int sortLog(const void *a, const void *b)
{
	return strcmp(((Computer*)a)->login, ((Computer*)b)->login);
}

int sortNumber(const void *a, const void *b)
{
	float f = ((Computer*)a)->number - ((Computer*)b)->number;
	return (f < 0.0) ? -1 : (f > 0.0) ? 1 : 0;
}

int sortPas(const void *a, const void *b)
{
	return strcmp(((Computer*)a)->password, ((Computer*)b)->password);
}

void viborSort(int v, Computer **computers, unsigned size)
{
	if (v == 1)
	{
		 qsort(*computers, size, sizeof(struct Computer), sortNumber);
	}
	if (v == 2)
	{
		qsort(*computers, size, sizeof(struct Computer), sortLog);
	}
	if (v == 3)
	{
		qsort(*computers, size, sizeof(struct Computer), sortPas);
	}
	else puts("Произошла ошибка");

}

void Clear(struct Computer *& computers)
{
	
		if (computers)
		{
			Clear(computers->nextelement);
			delete computers;
		}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	Computer *computers = NULL;
	unsigned size=0;
	char buffer[128],buffer1[128], c;
	unsigned i;
	int j =0, k = 0, v = 0 ;

	while (1)
	{			
		printf_s("\n");
		printf_s("1: Количество комьпютеров\n");
		printf_s("2: Инициализация\n");
		printf_s("3: Вывод\n");
		printf_s("4: Сортировка\n");
		printf_s("5: Выход\n");
		printf_s("\n");


		do {
			scanf_s("%d", &j);
			rewind(stdin);
			printf_s("\n");

		} while (!(j >= 1 && j <= 5));

		switch (j)
		{
			case 1:
			{
				
				printf_s("Введите Количество комьпютеров \n\n");
				do{
					scanf_s("%d", &size);// установка кол-во структур
					rewind(stdin);
					printf_s("\n");
				}while (!size > 0);
				creadComputers(size, &computers);// создание массива структур
			}

			case 2:
			{
				rewind(stdin);
				printf_s("Инициализация\n\n");
				inComputers(&computers, size, buffer, buffer1);// инициализация массива структур
				break;
			}

			case 3:
			{
				for (i = 0; i < size; i++)
				{
					outComputer(&computers[i]);// Вывод на экран
				}
				break;
			}

			case 4:
			{
				printf_s("1: Сортировка по номеру\n");
				printf_s("2: Сортировка по логину\n");
				printf_s("3: Сортировка по паролю\n");
				do {
					scanf_s("%d", &k);
					rewind(stdin);
					printf_s("\n");
				} while (!(k > 0 && k < 4));

				switch (k)
				{
					case 1:
					{
						viborSort(1, &computers, size);
						break;
					}
					case 2:
					{
						viborSort(2, &computers, size);
						break;
					}
					case 3:
					{
						viborSort(3, &computers, size);
						break;
					}
				}
				break;
			}						

			case 5:
			{
				//Clear(computers);
				freeComputersArray(&computers, size);// освобождение 
				return 0;

			}
		}

	}

	return 0;
}