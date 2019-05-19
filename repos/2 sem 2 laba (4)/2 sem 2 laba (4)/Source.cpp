#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#define MAX_LENGTH 1024
#define MAX_LENGTH_word 30
#define ENCODE_LENGTH 4


struct God_word
{
	char chword[MAX_LENGTH_word] = {};  // массив для слова.
	int frefrequency = NULL;  // частота
	char encode[ENCODE_LENGTH] = {};  //кодировка
};

void int_m(FILE *m)
{
	char str2[MAX_LENGTH], str[MAX_LENGTH];
	puts("Введите строку (пустой вввод строки - выход из функции");
	do
	{
		gets_s(str2, MAX_LENGTH);
		rewind(stdin);
		OemToAnsi(str2, str);
		if (*str == '\0') break;
		strcat(str, "\n");
		fputs(str, m);
	} while (*str != '\n');
}

void out_m(FILE *m)
{
	char num[MAX_LENGTH];
	puts("\nСодержимое файла f:\n");
	while (fgets(num, MAX_LENGTH, m) != NULL)
		printf("%s", num);
}

void add_ram(God_word ** words, int& count)
{
	*words = (God_word*)realloc((*words), ((count) += 1) * sizeof(God_word));
}

void creadGod_word(int count, God_word** words)
{
	*words = (God_word*)malloc(count * sizeof(God_word));
}

void in_godword(char **arr, int count, God_word*& words)
{
	for (int i = 0; i < count; i++)
	{
		int k = 0;
		for (int j = 0; j < count; j++)
		{
			if (strlen(arr[i]) == strlen(arr[j]))
			{
				if (arr[j][0] == arr[i][0] + (char)32 || arr[j][0] == arr[i][0] - (char)32 || arr[j][0] == arr[i][0])
				{
					char arr_x[MAX_LENGTH_word];
					char arr_y[MAX_LENGTH_word];
					strcpy(arr_x, arr[j]);
					strcpy(arr_y, arr[i]);
					arr_x[0] = '0';
					arr_y[0] = '0';
					if (strstr(arr_x, arr_y))
					{
						k++;
					}
				}
			}
		}

		strcpy(words[i].chword, arr[i]);
		words[i].frefrequency = k;
	}
}

int check(char x[MAX_LENGTH_word], char y[MAX_LENGTH_word])
{
	int k = 0;
	if (strlen(x) == strlen(y))
	{
		if (*(y) == *(x)+(char)32 || *(y) == *(x)-(char)32 || *(y) == *(x))
		{
			char arr_x[MAX_LENGTH_word];
			char arr_y[MAX_LENGTH_word];
			strcpy(arr_x, y);
			strcpy(arr_y, x);
			arr_x[0] = '0';
			arr_y[0] = '0';
			if (strstr(arr_x, arr_y))
			{
				k++;
			}
		}
	}
	return k;
}

void encode(God_word*& words, int i, char& m, char& max_m)
{
	if (words[i].frefrequency * strlen(words[i].chword) > 3 + strlen(words[i].chword) + (3 * words[i].frefrequency))
	{
		for (int j = 0; j < i; j++)
		{
			if (check(words[i].chword, words[j].chword))
			{
				m = (words[j].encode)[1];
				break;
			}
		}

		m == 32 ? m++ : m;
		(words[i].encode)[0] = '*';
		(words[i].encode)[1] = m;
		(words[i].encode)[2] = *((words)[i].chword);
		(words[i].encode)[3] = '\0';
		m++;
		m < max_m ? m = max_m : m;
	}
}

void estimation(int count, God_word*& words)
{
	char m = '0', max_m = '0';
	for (int i = 0; i < count; i++)
	{
		int k = 0;
		for (int j = 0; j < count; j++)
		{
			k += check(words[i].chword, words[j].chword);
		}
		words[i].frefrequency = k;
		encode(words, i, m, max_m);
	}
}

void quantity_iCnt(FILE* m, int &iCnt, int& flag, God_word*& words)
{
	int k = 0;
	char* str;
	while (!(feof(m))) // считает сколько слов и занос слов
	{
		char buff[MAX_LENGTH] = {};
		fgets(buff, MAX_LENGTH, m);

		str = strtok(buff, " ,.-!?'\n'()>—<»«…");

		while (str != NULL)
		{
			flag == 0 ? strcpy(words[k].chword, str), k++ : iCnt++;;
			str = strtok(NULL, " ,.-!?'\n'()>—<»«…"); 
		}
	}
	flag--;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	FILE* f, *g;
	God_word* words = NULL;

	int flag = 1, count = 0, iCnt = 0;
	char* str;

	while (1)
	{
		puts("\nНажмите:");
		puts("'0' - Запись в файла f");
		puts("'1' - просмотреть содержимое файла f");
		puts("'2' - просмотреть содержимое файла g");
		puts("'3' - сжать из f в g");
		puts("'5' - выход");
		fflush(stdin);

		switch (_getch())
		{

		case '0':

			if (!(f = fopen("f.txt", "w"))) //открыть для записи
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}

			int_m(f);
			fclose(f);
			break;


		case '1':


			if (!(f = fopen("f.txt", "r"))) //открыть для чтения f
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}

			out_m(f); //просмотреть содержимое файла
			fclose(f);
			break;

		case '2':

			if (!(g = fopen("g.txt", "r"))) //открыть для чтения g
			{
				puts("\nОшибка! Файл не создан");
				_getch();
				break;
			}

			out_m(g); //просмотреть содержимое файла
			fclose(g);
			break;

		case '3':

			if (!(f = fopen("f.txt", "r"))) //открыть для чтения
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}

			if (!(g = fopen("g.txt", "w"))) //открыть для записи
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}

		

			quantity_iCnt(f, count, flag, words);// подсчет слов

			fseek(f, 0L, SEEK_SET);

			creadGod_word(count, &words); // создание структуры

			quantity_iCnt(f, count, flag, words);// перенос слов




			estimation(count, words); // частота слов 
			

	//		encode(words, count, arr_encode); // кодирование

		

			for (int v = 0; v < count; v++)
			{
				printf("%s", &words[v]);
				printf("\n");
			}

			fclose(f);
			fclose(g);
			break; //переписать в нужном порядке компоненты файла f в g

		case '5': return 0;
		}
	}
	return 0;
}