#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <locale.h>

#define MAX_SIZE 30
#define MAX_COMP 2


struct Computer
{
	char manufacturer[MAX_SIZE];
	int data_of_production;
	char Cpu[MAX_SIZE];
	int ram;
	int disk_capacity;
	char model_of_video_card[MAX_SIZE];
	int price;
}count[MAX_COMP];

void clean_stdin();

//void inComputer(struct Computer *kolvo, int comp);	

//void outComputer(Computer* kolvo, int comp);

//void creadComputer(Computer* kolvo, int comp);

//void sort(int* kolvo);




int main()
{
	setlocale(LC_ALL, "Russian");


	//struct Computer *kolvo;
	//void creadCompute(Computer* kolvo,int comp);
	/*int comp = 0;


	printf_s("������� ���������� �����������  ");
	scanf_s("%d", &comp);*/
	//kolvo = (struct Computer*)malloc(comp * sizeof(struct Computer*));



	//void inComputer(struct Computer *kolvo, int comp);

	for (int i = 0; i < MAX_COMP; i++)
	{
		rewind(stdin);
		printf_s("������� ��������� %d", i + 1);

		printf_s("\n �������������:");
		rewind(stdin);
		gets_s(count[i].manufacturer, MAX_SIZE);
		if (!*count[i].manufacturer)
			break;

		/*printf_s("\n ���� ������������:");
		rewind(stdin);
		while (!scanf_s("%d", &kolvo[i].data_of_production))
			clean_stdin();

		printf_s("\n ������ ���������:");
		rewind(stdin);
		gets_s(kolvo[i].Cpu, MAX_SIZE);
		if (!*kolvo[i].Cpu)
			break;

		printf_s("\n ����� ������������ ������ (��):");
		rewind(stdin);
		while (!scanf_s("%d", &kolvo[i].ram))
			clean_stdin();

		printf_s("\n ����� ������� ����� (��):");
		rewind(stdin);
		while (!scanf_s("%d", &kolvo[i].disk_capacity))
			clean_stdin();

		printf_s("\n ������ ����������:");
		rewind(stdin);
		gets_s(kolvo[i].model_of_video_card, MAX_SIZE);
		if (!*kolvo[i].model_of_video_card)
			break;

		printf_s("\n ����:");
		rewind(stdin);
		while (!scanf_s("%d", &kolvo[i].price))
			clean_stdin();
		rewind(stdin);*/
	}





	for (int i = 0; i < MAX_COMP; i++)
	{

		//void outComputer(struct Computer kolvo[i]);
		printf_s("\n\n �������������: %s \n ", count[i].manufacturer);
		/*printf_s("\n ���� ������������: %3d \n", kolvo[i].data_of_production);
		printf_s("\n ���������: %3s \n", kolvo[i].Cpu);
		printf_s("\n ����������� ������: %3d \n", kolvo[i].ram);
		printf_s("\n ����� �����: %3d \n", kolvo[i].disk_capacity);
		printf_s("\n ������ ����������: %3s \n", kolvo[i].model_of_video_card);
		printf_s("\n ����: %3d \n", kolvo[i].price);*/
	}


	//free(kolvo);
	system("pause");
	return 0;
}


//void creadComputer(Computer* kolvo, int comp)
//{
//	printf_s("������� ���������� �����������  ");
//	scanf_s("%d", &comp);
//	struct Computer *kolvo;
//	kolvo = (struct Computer*)malloc(comp * sizeof(struct Computer));
//}


//void inComputer(struct Computer *kolvo, int comp)
//{
//	for (int i = 0; i <comp; i++)
//	{
//		rewind(stdin);
//		printf_s("������� ��������� %d", i + 1);
//
//		printf_s("\n �������������:");
//		rewind(stdin);
//		gets_s(kolvo[i].manufacturer, MAX_SIZE);
//		if (!*kolvo[i].manufacturer)
//			break;
//
//		printf_s("\n ���� ������������:");
//		rewind(stdin);
//		while (!scanf_s("%d", &kolvo[i].data_of_production))
//			clean_stdin();
//
//		printf_s("\n ������ ���������:");
//		rewind(stdin);
//		gets_s(kolvo[i].Cpu, MAX_SIZE);
//		if (!*kolvo[i].Cpu)
//			break;
//
//		printf_s("\n ����� ������������ ������ (��):");
//		rewind(stdin);
//		while (!scanf_s("%d", &kolvo[i].ram))
//			clean_stdin();
//
//		printf_s("\n ����� ������� ����� (��):");
//		rewind(stdin);
//		while (!scanf_s("%d", &kolvo[i].disk_capacity))
//			clean_stdin();
//
//		printf_s("\n ������ ����������:");
//		rewind(stdin);
//		gets_s(kolvo[i].model_of_video_card, MAX_SIZE);
//		if (!*kolvo[i].model_of_video_card)
//			break;
//
//		printf_s("\n ����:");
//		rewind(stdin);
//		while (!scanf_s("%d", &kolvo[i].price))
//			clean_stdin();
//		rewind(stdin);
//	}
//}


void outComputer(Computer* kolvo)
{
	/*for (int i = 0; i < comp; i++)
	{*/
	printf_s("�������������: %s \n ", kolvo->manufacturer);
	/*printf_s("���� ������������: %3d \n", kolvo[i].data_of_production);
	printf_s("���������: %3s \n", kolvo[i].Cpu);
	printf_s("����������� ������: %3d \n", kolvo[i].ram);
	printf_s("����� �����: %3d \n", kolvo[i].disk_capacity);
	printf_s("������ ����������: %3s \n", kolvo[i].model_of_video_card);
	printf_s("����: %3d \n", kolvo[i].model_of_video_card);*/
	//}
}


//void sort(int* kolvo)
//{/*
// char c;
// for (c = 'A' || c = '�' || c = 'a' || c = '�'; c <= 'Z' || c <= 'z' || c <= '�' || c <= '�'; c++)
// for (int i = 0; i < MAX_COMP; i++)
// {
// if ((!kolvo[i].manufacturer))
// }*/
//}



void clean_stdin()
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}