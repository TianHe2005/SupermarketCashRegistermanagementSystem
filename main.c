#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h>
#include "spMange.h" 
#include "ddMange.h"
#include "zhuce.h"
#define N 100 


/*======
 ������
======*/

int main()
{

    int shopChoose;//ѡ���½��ʽ 
    int flag = 1;//�ж� 

    while (flag == 1)
    {
        printf("\t\t\t\t\t   �q �] % �r               �q ```�r  \n");
        printf("\t\t\t\t\t   (@^o^@) ���й���ϵͳ (��:��)\n");
        printf("\t\t\t\t\t   (~):(~)              (~)v(~) \n");
        printf("%70s", "\t\t������������������������������\n");
        printf("%66s", "[ 1.����Ա��½  ]\n");
        printf("%66s", "[ 2.�ͻ���½    ]\n");
        printf("%70s", "\t\t������������������������������\n");
        printf("��ѡ��");

        scanf("%d", &shopChoose);


        switch (shopChoose)
        {
        case 1://����Ա
            system("pause");
            system("cls");
            set();
            break;

        case 2://�ͻ�
            system("cls");
            set1();
            break;

        default:
            printf("�����������������\n");
            system("pause");
            system("cls");
            break;

        }

    }

    printf("\n");
    system("pause");
   return 0;
}


void Windowstime()
{
    SYSTEMTIME sys; //����ͷ�ļ�windows.h����ȡwindows��ʱ�亯�� 

    printf("\t\t\t\t\t  ��ǰʱ��Ϊ��");
    GetLocalTime(&sys); //��ȡϵͳʱ�䵽����ĺ��� 
    printf("%4d-%02d-%02d %02d:%02d \n",

        sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute,
        sys.wSecond, sys.wDayOfWeek); //������/��/�� ʱ/��/�� ���ڼ���ʽ��ӡ 

    printf("\n");

    return;
}

void cursor(int x, int y)
{
    COORD pos;          //COORD��Windows API�ж����һ�ֽṹ 
    HANDLE h;           //HANDLE:���
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //��õ�ǰ������ڵľ��
    SetConsoleCursorPosition(h, pos);

}

/*----------
 ��ʼ������
 (����Ա)
-----------*/



void set()
{

    int choose;         //�û������ѡ�� 
    int ture = 1;       //ѭ���ж���� 


    while (ture != 0)
    {

        printf("\t\t\t\t\t   �q �] % �r               �q ```�r  \n");
        printf("\t\t\t\t\t  (@^o^@) ������������ϵͳ (��:��)\n");
        printf("\t\t\t\t\t   (~):(~)              (~)v(~) \n");
        printf("%70s", "\t\t������������������������������\n");
        printf("%66s", "[ 1.ע���˻�    ]\n");
        printf("%66s", "[ 2.��½�˻�    ]\n");
        printf("%66s", "[ 3.�һ�����    ]\n");
        printf("%70s", "\t\t������������������������������\n");
        printf("��ѡ��");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            getchar();
            system("cls");
            registers();    //ע���˻�
            break;

        case 2:
            progress();     //������ 
            system("cls");
            Input_login();  //��¼�˻�
            getchar();
            break;

        case 3:
            getchar();
            reback();       //�һ����� 
            break;

        default:
            getchar();
            rewind(stdin);      //������̻��� 
            printf("����������������룡\n");
            system("pause");
            system("cls");
            break;
        }

    }

}


/*--------------------------
 ���������û��˺�������ļ�
        �������ƣ�
--------------------------*/

void Create_File()
{
    FILE* fp;

    if ((fp = fopen("users.txt", "rb")) == NULL)               /*�ж��ļ��Ƿ����*/
    {
        if ((fp = fopen("users.txt", "wb+")) == NULL)          /*��д������*/
        {
            printf("�޷������ļ���\n");
            exit(0);

        }
    }
}


/*-------
 ע���˺�
---------*/

void registers()
{
    //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С

    users a, b; //�ṹ�� The_users ����������
    FILE* fp;  //����ͷ�ļ� fp 


    char temp[20];//������룬����ȷ�� 
    int count = 0;
    int flag = 1;

    printf("��ӭ����ע����棡\n");

    fflush(stdin);
    Sleep(1000);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //�������ݴ�ŵĵ�ַ b  

    printf("�������˺�\n");
    scanf("%s", &a.id);

    while (flag)
    {
        if (strcmp(a.id, b.id)) /*������������*/
        {
            if (!feof(fp))    /*���δ���ļ�β*/
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else

                break;

        }
        else
        {
            printf("���û����Ѵ��ڣ�������ѡ��\n");

            getchar();
            rewind(stdin);
            Sleep(800);
            system("cls");

            return;
        }
    }

    printf("������������\n");
    scanf("%s", &a.name);

    printf("�������Ա�(f(Ů)/m(��))��\n");
    scanf(" %c", &a.sex);

    do
    {
        if (a.sex != 'f' && a.sex != 'm')
        {
            printf("�Ա�����������������룡\n");

            getchar();
            scanf("%c", &a.sex);

        }
    } while (a.sex != 'f' && a.sex != 'm');

    getchar();

    printf("������绰���룺\n");
    scanf("%ld", &a.phone);

    printf("����������\n");
    scanf(" %s", &a.pwd);

    printf("��ȷ������\n");
    scanf(" %s", &temp);

    do {

        if (!strcmp(a.pwd, temp))
        {
            fp = fopen("users.txt", "a");//׷��һ���˺� 

            fwrite(&a, sizeof(struct The_users), 1, fp);/* a ��д���ļ���ָ�� ����ַ��*/

            printf("�˺�ע��ɹ������¼������\n");
            Sleep(500);
            fclose(fp);

            return;
        }
        else
        {
            printf("�������벻ƥ�䣡���������룡\n");
            getchar();
            scanf("%s", &a.pwd);

            printf("��ȷ������\n");
            scanf("%s", &temp);
        }

    } while (1);

    return;

}


/*---------
 ��¼ϵͳ
---------*/

void  Input_login()
{
    users a, b;  //����ṹ��The_users����

    FILE* fp;   //�ļ� 
    int i = 0;

    system("cls");

    system("color 06"); //����Ϊ��ɫ��ǰ��Ϊ��ɫ 

    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t��ӭ������¼���棡\n");

    Sleep(1500);
    system("cls");//���� 
    Sleep(800);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b


    printf("\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� �������˺ţ�                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //����д��û���
        {
            break;
        }

        else
        {
            if (fp == NULL)
            {
                printf("��δӵ��ע����Ϣ����ע��\n");
                system("pause");
                system("cls");
                set();
            }


            if (!feof(fp))  //����ļ�û�ж���                            

            {
                fread(&b, sizeof(struct The_users), 1, fp);
                /*�������� b ��ŵĵ�ַλ�ã��ڴ��С��ÿ�ζ�ȡһ�����ݿ� 1 ���Զ��ķ�ʽ���ļ�*/
            }

            else
            {
                printf("���û��������ڣ�������ѡ��\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }

    printf("\n\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� ���������룺                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 8);

    while ((a.pwd[i] = getch()) != 13)//getch()����ֵ��һ����ֵ���س��ļ�ֵ��13
    {                                   //�����������洢������������Ļ�������* ���������� 
        i++;
        printf("*");//��������
    }
    a.pwd[i] = '\0';//�����Ļس���ɽ����������飩 
    printf("\n");

    do {

        if (strcmp(a.pwd, b.pwd) == 0)            /*�������ƥ��*/

        {
            fclose(fp);

            Sleep(500);
            printf("\n\n\t\t\t\t\t\t��¼������");

            Sleep(500);
            printf(".");
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(1000);
            fflush(stdin);

            printf("\n\n\t\t\t\t\t\t�� ¼ �� �� !");
            Sleep(1000);
            system("cls");

            welcome(); //�����˵�   

            return;
        }
        else
        {

            printf("�������");
            printf("\n\n\n");
            printf("\t\t\t\t   ��============================================��\n");
            printf("\t\t\t\t   �� ���������룺                         ��\n");
            printf("\t\t\t\t   ��============================================��\n");

            cursor(50, 13);
            scanf("%s", &a.pwd);

        }

    } while (strcmp(a.pwd, b.pwd) == 0);

}





/*---------
 �һ�����
----------*/

void reback()  //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С
{
    users a, b;//�ṹ�� The_users ����������
    FILE* fp;

    char temp[20];
    //int count = 0;

    printf("��ӭ�����һ�������棡\n");
    Sleep(1000);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //����һ���ṹ���ַ��� д��b

    system("cls");
    system("color 06"); //����Ϊ��ɫ��ǰ��Ϊ��ɫ 

    printf("\n\n");
    printf("\t\t\t\t   ��============================================��\n");
    printf("\t\t\t\t   �� �������˺ţ�                         ��\n");
    printf("\t\t\t\t   ��============================================��\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //����д��û���
        {
            break;
        }

        else
        {
            if (!feof(fp))  //����ļ�û�ж���                            

            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }

            else
            {
                printf("���û��������ڣ�������ѡ��\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }


    printf("\n\n");
    printf("������������\n");
    scanf("%s", &a.name);

    do
    {
        if (strcmp(a.name, b.name))
        {
            printf("��������������������룡\n");
            getchar();
            scanf("%s", &a.name);
        }
    } while (strcmp(a.name, b.name));

    printf("������绰���룺\n");
    scanf("%ld", &a.phone);

    do {
        if (a.phone != b.phone)
        {
            printf("�绰��������������������룡\n");
            getchar();
            scanf("%ld", &a.phone);
        }
    } while (a.phone != b.phone);

    printf("���������ǣ�%s\n", b.pwd);
    Sleep(3000);
    system("pause");
    system("cls");
}


/*-----------
 ��ӭ����(����)
-------------*/

void welcome()
{

    system("color F4");//��ɫ���׵׺���

    Windowstime();//��ʾ��ǰWindowsʱ��

    printf("\n\n");
    printf("\n\n\n\t\t\t\t");
    printf(" ��");
    Sleep(120);
    printf(" ӭ");
    Sleep(120);
    printf(" ʹ");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" չ");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ��");
    Sleep(120);
    printf(" ϵ");
    Sleep(120);
    printf(" ͳ��");
    Sleep(800);
    printf("\n");
    system("cls");

    menu();     //�˵� 

}



/*-------
 ������
-------*/

void progress()
{
    int i;
    int j;

    system("cls");

    printf("\n\n\n\n\n\t\t\t\t    \033[0;33;40m     �� �� �� �� ϵ ͳ���� �� �� . . .   \033[0m");

    const char* LastStr = "[--------------------------------------------------] 100%";
    // ��������־�����Ը���"*"����������
    const char ProgressIcon = '*';
    // ����ÿ��5���������ͻ��һ��ע��StepֵҪ��LastStr�е�"-"������ƥ�䣬������˵���100
    const int Step = 2;
    // �ܹ���Ҫ���ٽ��ȱ�־����LastStr��"-"������
    const int IconMaxNum = 50;

    printf("\n\n    \t\t\t\t");
    for (i = 0; i <= 100; ++i)
    {
        // -------------- ��ӡ������ --------------
        printf("<");
        int currentIndex = i / Step;
        for (j = 0; j < IconMaxNum; ++j)
        {
            if (j < currentIndex)
            {
                printf("\033[0;33;1m%c", ProgressIcon); // ��ӡ��������־
            }
            else
            {
                printf(" "); // δ��������ӡ�ո�
            }
        }
        printf("> ");
        // -------- ��ӡ���ֽ��� ----------
        printf("\033[0;35;0m%3d%%", i);
        fflush(stdout);
        // ÿ��100ms��ӡһ�Σ�����ͬʱÿ��100ms���ý��ȼ�1
        Sleep(3 * 10);
        for (j = 0; j < strlen(LastStr); ++j)  //strlen �ַ���������
        {
            printf("\b");               // ��ɾ�ַ��������ֺͽ�����ԭ�ر仯
        }
        fflush(stdout); //������������
    }

    printf("\n\n");
    return;

}



void menu()
{
	int select;
	SP sp[N];
	int n = readSP(sp);
    char choice;
    char id;
	while(1)
    {	
    	system("cls");
        printf("\n\n\n");
        printf("\t\t\t\t\t   �q �] �r          �q ```�r \n");
        printf("\t\t\t\t\t   (@^o^@) ������������ϵͳ (��:��)\n");
        printf("\t\t\t\t\t   (~):(~)                  (~)v(~) \n");
        printf("\n\n");
        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
        printf("\t\t\t\t   ��              ������������ϵͳ              ��\n");
        printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 1. ��ʼ����             2. ��ɾ��Ʒ        ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 3. �����ۿ�             4. ���ֶһ���齱  ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 5. ��ѯ��Ʒ��Ϣ         6. ͳ����Ʒ��Ϣ    ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��            0. �˳�����ϵͳ                 ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

        Windowstime();      //windows��ǰʱ�� 
        printf("\t\t��ѡ����Ҫ���е�ѡ��(0-6):");
        scanf("%d",&select);
        switch(select)
        {
        case 0:
            exit(0);
            break;
        case 1:
            do{
            	showSYMenu2(sp,n);
            	addDD(sp,n);
            	printf("��Ҫ����������(y/n)");
            	scanf(" %c",&choice);
			}while(choice == 'y'||choice == 'Y');
            break;
        case 2:
            //������ʾ��Ʒ��ɾ�����˵��ĺ���
			showSPMenu2(sp,n); 
            break;
        case 3:
			break;
        case 4:
            choujiang(sp,n); 
            break;
        case 5:
 			showFindMenu2(sp,n); 	
            break;
        case 6:
        	showALLSP2(sp,n);
           readInformation();
            break;
        default:
            printf(" ��������밴�س���������\n");
            system("cls");   //���� 
        }
    }
		
}

void set1()
{
    system("color F4");//��ɫ���׵׺���

    welcome1();
}


/*------------
 �û���ӭ����
-------------*/

void welcome1()
{
    //��ʾ��ǰWindowsʱ�� 
    Windowstime();

    printf("\n\n");
    printf("\n\n\n\t\t\t\t");
    printf(" ��");
    Sleep(100);
    printf(" ӭ");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ��");
    Sleep(100);
    printf(" ϵ");
    Sleep(100);
    printf(" ͳ");
    Sleep(100);
    printf(" ��");
    Sleep(1000);
    printf("\n");
    system("cls");

    menu1(); //�û��˵� 

}
void menu1(){
	int select;
	SP sp[N];
	int n = readSP(sp);
    char choice;
    char id;
	while(1)
    {
    	system("cls");
        printf("\n\n\n");
        printf("\t\t\t\t\t   �q �] �r          �q ```�r \n");
        printf("\t\t\t\t\t   (@^o^@) ������������ϵͳ (��:��)\n");
        printf("\t\t\t\t\t   (~):(~)                  (~)v(~) \n");
        printf("\n\n");
        printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
        printf("\t\t\t\t   ��              ������������ϵͳ              ��\n");
        printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
        printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 1. ��ʼ����             2. ��ɾ��Ʒ        ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 3. �����ۿ�             4. ���ֶһ���齱  ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   �� 5. ��ѯ��Ʒ��Ϣ         6. ͳ����Ʒ��Ϣ    ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��            0. �˳�����ϵͳ                 ��\n");
        printf("\t\t\t\t   ��                                            ��\n");
        printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

        Windowstime();      //windows��ǰʱ�� 
        printf("\t\t��ѡ����Ҫ���е�ѡ��(0-6):");
        scanf("%d",&select);
        switch(select)
        {
        case 0:
            exit(0);
            break;
        case 1:
            do{
            	showSYMenu2(sp,n);
            	addDD(sp,n);
            	printf("��Ҫ����������(y/n)");
            	scanf(" %c",&choice);
			}while(choice == 'y'||choice == 'Y');
            break;
        case 2:
			showSPMenu2(sp,n); 
            break;
        case 3:
			break;
        case 4:
        	choujiang(sp,n);
            break;
        case 5:
 			showFindMenu2(sp,n);  	
            break;
        case 6:
        	showALLSP2(sp,n);
        	readInformation();
            break;
        default:
            printf(" ��������밴�س���������\n");
            system("cls");   //���� 
        }
    }
	
}





