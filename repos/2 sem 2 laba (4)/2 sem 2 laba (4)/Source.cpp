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
	char chword[MAX_LENGTH_word] = {};  // ������ ��� �����.
	int frefrequency = NULL;  // �������
	char encode[ENCODE_LENGTH] = {};  //���������
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
	while (!(feof(m))) // ������� ������� ���� � ����� ����
	{
		char buff[MAX_LENGTH] = {};
		fgets(buff, MAX_LENGTH, m);

		str = strtok(buff, " ,.-!?'\n'()>�<���");

		while (str != NULL)
		{
			flag == 0 ? strcpy(words[k].chword, str), k++ : iCnt++;;
			str = strtok(NULL, " ,.-!?'\n'()>�<���"); 
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
		puts("\n�������:");
		puts("'0' - ������ � ����� f");
		puts("'1' - ����������� ���������� ����� f");
		puts("'2' - ����������� ���������� ����� g");
		puts("'3' - ����� �� f � g");
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

		

			quantity_iCnt(f, count, flag, words);// ������� ����

			fseek(f, 0L, SEEK_SET);

			creadGod_word(count, &words); // �������� ���������

			quantity_iCnt(f, count, flag, words);// ������� ����




			estimation(count, words); // ������� ���� 
			

	//		encode(words, count, arr_encode); // �����������

		

			for (int v = 0; v < count; v++)
			{
				printf("%s", &words[v]);
				printf("\n");
			}

			fclose(f);
			fclose(g);
			break; //���������� � ������ ������� ���������� ����� f � g

		case '5': return 0;
		}
	}
	return 0;
}