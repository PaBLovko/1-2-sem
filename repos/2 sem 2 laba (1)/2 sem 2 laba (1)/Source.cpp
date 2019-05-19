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

struct God_word
{
	char chword[MAX_LENGTH_word] = {};    // массив для слова.
	int frefrequency;  // частота


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
	while (1)
	{
		fscanf(m, "%s", &num);
		if (feof(m))
			break;
		printf("%s", num);
	}
	puts("\n");
}

void add_ram(God_word ** words, unsigned* size)
{
	*words = (God_word*)realloc((*words), ((*size) += 1) * sizeof(God_word));
}

char* pupular(char **ms, int size, int number)
{
	////Выделяем память 
	Data* array;
	Data** array1;
	array = (Data*)malloc(sizeof(Data)*size);
	array1 = (Data**)malloc(sizeof(Data)*size);

	for (int i = 0; i < size; i++)
	{
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (strlen(ms[i]) == strlen(ms[j]))
			{
				if (strstr(ms[j], ms[i]))
				{
					k++;
				}
			}
		}

		array[i].word = ms[i];
		array[i].quantity = k;

		array1[i] = &array[i];

	}

	sort(array1, size);

	/*for (int j = 0; j < size; j++)
	{
	printf("\n%s", array1[j]->word);
	printf("\t%d", array1[j]->quantity);

	}*/

	if ((array1[number]->quantity) > 1)
	{
		return (array1[number]->word);
	}
	else
	{
		return "0#NeverFind";
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	FILE* f, *g;
	God_word *words = NULL;
	unsigned size = 0;

	char chword[MAX_LENGTH_word] = { '\0', };    // массив для слова.
	char *ptr_on_chword = chword; // указатель на chword
	char ch;        // читаемый символ из файла
	int length_word;    // длина слова (набра ascii символов состоящих только из букв без пробелов и тире)
	int begin_word; // флаг начала слова
	int seek_word; // смещение от начала файла слова
				   //char znak[2] = { '\0', };
				   //char *ptr_znak = znak;
				   //char otst;
	unsigned  j = 0, flag = 0, count = 0;
	char* str;
	char* arr[1000];


	while (1)
	{
		puts("\nНажмите:");
		puts("'0' - Запись в файла f");
		puts("'1' - просмотреть содержимое файла f");
		puts("'2' - просмотреть содержимое файла g");
		puts("'3' - сжать из f в g");
		puts("'4' - сжать из f в g");
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



			//	int descr; //дескриптор
			//	long l; //длина файла

			//	descr = fileno(f); //переход от указателя на файл к дескриптору
			//	l = filelength(descr); //определение длины файла


			//length_word = seek_word = 0;

			while (!(feof(f)))
			{
				char buff[MAX_LENGTH] = {};
				fgets(buff, MAX_LENGTH, f);

				str = strtok(buff, " ,.-!?");

				while (str != NULL)
				{
					arr[count] = (char*)malloc(strlen(str)); // ну или MAX_LEN
					strcpy(arr[count], str);
					count++;
					str = strtok(NULL, " ,.-!?");
				}

			}


			for (int j = 0; j < count; j++)
			{
				in_godword(arr, count);
			}
				//	add_ram(&words, &size);// выделяем память





				//ch = fgetc(f);
				//do
				//{
				//	if (ch ==( '.' || ',' || '?' || '!' || '"' || ' '))
				//	{
				//		words[size].znak[i] = ch;
				//		i++;
				//		//flag += 1;
				//	}	

				//	while (ch != ('.' || ',' || '?' || '!' || '"' || ' ' || EOF))
				//	{
				//		words[size].chword[j];
				//		j++;
				//		//flag += 1;
				//	}
				//}while((words[size].znak && words[size].chword > 0) || feof(f))







				//if ((((ch >= 'А' && ch <= 'Я' ) || (ch >= 'а' && ch <= 'я') || ch == 'Ё' || ch == 'ё')))
				//	begin_word = 1;
				//else begin_word = 0;

				//if (begin_word)
				//{
				//	*ptr_on_chword = ch;
				//	ptr_on_chword++;
				//	length_word++;
				//}

				//else if ((begin_word == 0) && (length_word != 0))
				//{
				//	seek_word = ftell(f) - length_word - 1;
				//	*ptr_on_chword = '\0';  // в конце слова для xPear16, которая делает хэш из строки заканчив '0'
				//	ptr_on_chword = chword;
				//	*ptr_znak = '\0';
				//	ptr_znak = znak;
				//	otst;


				//как то сохранить все это


				//char buffer[MAX_LENGHT], buffer1[MAX_LENGHT];

				//for (i; i < size; i++)
				//{
				//	unsigned k = i + *m;
				//	printf_s("Number #%d \n  login: ", k);
				//	rewind(stdin);
				//	gets_s(buffer1, MAX_LENGHT);
				//	OemToAnsi(buffer1, buffer);
				//	(*computers)[i].number = k;
				//	(*computers)[i].login = (char*)malloc(strlen(buffer) + 1);
				//	strcpy((*computers)[i].login, buffer);

				//	printf_s("  password: ");
				//	rewind(stdin);
				//	gets_s(buffer1, MAX_LENGHT);
				//	OemToAnsi(buffer1, buffer);
				//	(*computers)[i].password = (char*)malloc(strlen(buffer) + 1);
				//	strcpy((*computers)[i].password, buffer);
				//}



				//////////////////////////////////////////////////////


				/*		otst = 0;
				length_word = 0;
				}*/



			

			//	work(f, g, l);

			for (int v = 0; v < count; v++)
			{
				printf("%s", &arr[v]);
			}
			
			fclose(f);
			fclose(g);
			break; //переписать в нужном порядке компоненты файла f в g

		case '4':

			if (!(f = fopen("f.txt", "w"))) //открыть для чтения
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}
			if (!(g = fopen("g.txt", "r"))) //открыть для записи
			{
				puts("\nОшибка открытия файла!");
				_getch();
				break;
			}



			//	work(f, g, l);



			fclose(f);
			fclose(g);
			break;

		case '5': return 0;
		}
	}
	return 0;
}