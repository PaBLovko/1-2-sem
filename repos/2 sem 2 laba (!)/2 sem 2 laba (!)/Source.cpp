L. ��Zj�  �       .drectve        �   D               
 .debug$S        pV  �              @ B.debug$T        l   V^              @ B.text$mn        %   �^               P`.debug$S        �   �^  �_         @B.text$mn        Y  `  ^a          P`.debug$S        �  Db  d         @B.text$mn        �   e  �e          P`.debug$S        �  �f  <h         @B.text$mn        *   �h  i          P`.debug$S        �   i  j         @B.text$mn        *   Tj  ~j          P`.debug$S    
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
		printf("%s ", num);
	}
	puts("\n");
}

int main()
{
	setlocale(LC_ALL, "RUS");
	FILE* f, *g;
	char chword[MAX_LENGTH_word] = { '\0', };    // ������ ��� �����.
	char *ptr_on_chword = chword; // ��������� �� chword
	char ch;        // �������� ������ �� �����
	int length_word;    // ����� ����� (����� ascii ����ta          7   �              @0@.rdata             J�              @0@.rdata             L�              @0@.rdata             b�              @0@.rdata             e�              @0@.rdata             i�              @0@.rdata          
   m�              @0@.rdata             w�              @0@.rdata          %   ��              @0@.rdata          %   ��              @0@.rdata             ؋              @0@.rdata             �              @0@.rdata             �               g");
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
			fcrs\PaBlO\source\repos\2 sem 2 laba (!)\2 sem 2 laba (!)\Debug\Source.obj : <!    �c   �c Microsoft (R) Optimizing Compiler �=cwd C:\Users\PaBlO\source\repos\2 sem 2 laba (!)\2 sem 2 laba (!) cl C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.11.25503\bin\HostX86\x86\CL.exe cmd -c -ZI -nologo -W3 -WX- -diagnostics:classic -sdl -Od -Oy- -D_MBCS -Gm -EHs -EHc -RTC1 -MDd -GS -fp:precise -Zc:wchar_t -Zc:forScope -Zc:inline -Fo"C:\Users\PaBlO\source\repos\2 sem 2 laba (ch();
				break;
			}



		//	int descr; //����������
		//	long l; //����� �����

		//	descr = fileno(f); //������� �� ��������� �� ���� � �����������
		//	l = filelength(descr); //����������� ����� �����


			length_word = seek_word = 0;

			while (!(feof(f)))
			{
				ch = fgetc(f);

				if (ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == '"')
				{
					*ptr_znak = ch;
					ptr_znak++;
				}	

				if (ch == ' ')
					otst = ch;
				
				if ((((ch >= '�' && ch <= '�' rt" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\um" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\shared" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\winrt" -I"C:\Users\PaBlO\source\repos\2 sem 2 laba (!)\2 sem 2 laba (!)\Include\um" -X src Source.cpp pdb C:\Users\PaBlO\source\repos\2 sem 2 laba (!)\2 sem 2 laba (!)\Debug\vc141.pdb  �   D  # 	   BINDSTATUS_FINDINGRESOURCE  	   BINDSTATUS_CONNECTING  	   BINDSTATUS_REDIRECTING % 	   BIst;


					//��� �� ��������� ��� ���


					otst = 0;
					length_word = 0;
				}



			}

		//	work(f, g, l);



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
			} BINDSTATUS_BEGINUPLOADDATA ! 	   BINDSTATUS_UPLOADINGDATA ! 	   BINDSTATUS_ENDUPLOADDATA # 	   BINDSTATUS_PROTOC