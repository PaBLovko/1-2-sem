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
	char chword[MAX_LENGTH_word] = {};    // ������ ��� �����.
	int frefrequency;  // �������


};

void int_m(FILE *m)
{
	char str2[MAX_LENGTH], str[MAX_LENGTH];
	puts("������� ������ (������ ����� ������ - ����� �� �������");
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
	puts("\n���������� ����� f:\n");
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
	////�������� ������ 
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

	char chword[MAX_LENGTH_word] = { '\0', };    // ������ ��� �����.
	char *ptr_on_chword = chword; // ��������� �� chword
	char ch;        // �������� ������ �� �����
	int length_word;    // ����� ����� (����� ascii �������� ��������� ������ �� ���� ��� �������� � ����)
	int begin_word; // ���� ������ �����
	int seek_word; // �������� �� ������ ����� �����
				   //char znak[2] = { '\0', };
				   //char *ptr_znak = znak;
				   //char otst;
	unsigned  j = 0, flag = 0, count = 0;
	char* str;
	char* arr[1000];


	while (1)
	{
		puts("\n�������:");
		puts("'0' - ������ � ����� f");
		puts("'1' - ����������� ���������� ����� f");
		puts("'2' - ����������� ���������� ����� g");
		puts("'3' - ����� �� f � g");
		puts("'4' - ����� �� f � g");
		puts("'5' - �����");
		fflush(stdin);

		switch (_getch())
		{

		case '0':

			if (!(f = fopen("f.txt", "w"))) //������� ��� ������
			{
				puts("\n������ �������� �����!");
				_getch();
				break;
			}

			int_m(f);
			fclose(f);
			break;


		case '1':


			if (!(f = fopen("f.txt", "r"))) //������� ��� ������ f
			{
				puts("\n������ �������� �����!");
				_getch();
				break;
			}

			out_m(f); //����������� ���������� �����
			fclose(f);
			break;

		case '2':

			if (!(g = fopen("g.txt", "r"))) //������� ��� ������ g
			{
			puts("\n������! ���� �� ������");
			_getch();
			break;
			}

			out_m(g); //����������� ���������� �����
			fclose(g);
			break;

		case '3':

			if (!(f = fopen("f.txt", "r"))) //������� ��� ������
			{
				puts("\n������ �������� �����!");
				_getch();
				break;
			}

			if (!(g = fopen("g.txt", "w"))) //������� ��� ������
			{
				puts("\n������ �������� �����!");
				_getch();
				break;
			}



			//	int descr; //����������
			//	long l; //����� �����

			//	descr = fileno(f); //������� �� ��������� �� ���� � �����������
			//	l = filelength(descr); //����������� ����� �����


			//length_word = seek_word = 0;

			while (!(feof(f)))
			{
				char buff[MAX_LENGTH] = {};
				fgets(buff, MAX_LENGTH, f);

				str = strtok(buff, " ,.-!?");

				while (str != NULL)
				{
					arr[count] = (char*)malloc(strlen(str)); // �� ��� MAX_LEN
					strcpy(arr[count], str);
					count++;
					str = strtok(NULL, " ,.-!?");
				}

			}


			for (int j = 0; j < count; j++)
			{
				in_godword(arr, count);
			}
				//	add_ram(&words, &size);// �������� ������





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







				//if ((((ch >= '�' && ch <= '�' ) || (ch >= '�' && ch <= '�') || ch == '�' || ch == '�')))
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
				//	*ptr_on_chword = '\0';  // � ����� ����� ��� xPear16, ������� ������ ��� �� ������ �������� '0'
				//	ptr_on_chword = chword;
				//	*ptr_znak = '\0';
				//	ptr_znak = znak;
				//	otst;


				//��� �� ��������� ��� ���


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
			break; //���������� � ������ ������� ���������� ����� f � g

		case '4':

			if (!(f = fopen("f.txt", "w"))) //������� ��� ������
			{
				puts("\n������ �������� �����!");
				_getch();
				break;
			}
			if (!(g = fopen("g.txt", "r"))) //������� ��� ������
			{
				puts("\n������ �������� �����!");
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