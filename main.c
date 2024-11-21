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
 主函数
======*/

int main()
{

    int shopChoose;//选择登陆方式 
    int flag = 1;//判断 

    while (flag == 1)
    {
        printf("\t\t\t\t\t   ╭ ⺌ % ╮               ╭ ```╮  \n");
        printf("\t\t\t\t\t   (@^o^@) 超市管理系统 (⌒:⌒)\n");
        printf("\t\t\t\t\t   (~):(~)              (~)v(~) \n");
        printf("%70s", "\t\t┏┅┅┅┅┅┅┅┅┅┅┅┅┅☆\n");
        printf("%66s", "[ 1.管理员登陆  ]\n");
        printf("%66s", "[ 2.客户登陆    ]\n");
        printf("%70s", "\t\t┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
        printf("请选择：");

        scanf("%d", &shopChoose);


        switch (shopChoose)
        {
        case 1://管理员
            system("pause");
            system("cls");
            set();
            break;

        case 2://客户
            system("cls");
            set1();
            break;

        default:
            printf("输入错误，请重新输入\n");
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
    SYSTEMTIME sys; //所需头文件windows.h，获取windows的时间函数 

    printf("\t\t\t\t\t  当前时间为：");
    GetLocalTime(&sys); //获取系统时间到程序的函数 
    printf("%4d-%02d-%02d %02d:%02d \n",

        sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute,
        sys.wSecond, sys.wDayOfWeek); //按照年/月/日 时/分/秒 星期几格式打印 

    printf("\n");

    return;
}

void cursor(int x, int y)
{
    COORD pos;          //COORD是Windows API中定义的一种结构 
    HANDLE h;           //HANDLE:句柄
    pos.X = x;
    pos.Y = y;
    h = GetStdHandle(STD_OUTPUT_HANDLE); //获得当前输出窗口的句柄
    SetConsoleCursorPosition(h, pos);

}

/*----------
 初始化界面
 (管理员)
-----------*/



void set()
{

    int choose;         //用户输入的选择 
    int ture = 1;       //循环判断真假 


    while (ture != 0)
    {

        printf("\t\t\t\t\t   ╭ ⺌ % ╮               ╭ ```╮  \n");
        printf("\t\t\t\t\t  (@^o^@) 超市收银管理系统 (⌒:⌒)\n");
        printf("\t\t\t\t\t   (~):(~)              (~)v(~) \n");
        printf("%70s", "\t\t┏┅┅┅┅┅┅┅┅┅┅┅┅┅☆\n");
        printf("%66s", "[ 1.注册账户    ]\n");
        printf("%66s", "[ 2.登陆账户    ]\n");
        printf("%66s", "[ 3.找回密码    ]\n");
        printf("%70s", "\t\t┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛\n");
        printf("请选择：");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            getchar();
            system("cls");
            registers();    //注册账户
            break;

        case 2:
            progress();     //进度条 
            system("cls");
            Input_login();  //登录账户
            getchar();
            break;

        case 3:
            getchar();
            reback();       //找回密码 
            break;

        default:
            getchar();
            rewind(stdin);      //清除键盘缓存 
            printf("输入错误，请重新输入！\n");
            system("pause");
            system("cls");
            break;
        }

    }

}


/*--------------------------
 创建储存用户账号密码的文件
        （二进制）
--------------------------*/

void Create_File()
{
    FILE* fp;

    if ((fp = fopen("users.txt", "rb")) == NULL)               /*判断文件是否存在*/
    {
        if ((fp = fopen("users.txt", "wb+")) == NULL)          /*读写二进制*/
        {
            printf("无法建立文件！\n");
            exit(0);

        }
    }
}


/*-------
 注册账号
---------*/

void registers()
{
    //按结构体的大小，一次写入或者读入1个结构体大小

    users a, b; //结构体 The_users 重命名定义
    FILE* fp;  //定义头文件 fp 


    char temp[20];//存放密码，二次确认 
    int count = 0;
    int flag = 1;

    printf("欢迎来到注册界面！\n");

    fflush(stdin);
    Sleep(1000);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //读出数据存放的地址 b  

    printf("请输入账号\n");
    scanf("%s", &a.id);

    while (flag)
    {
        if (strcmp(a.id, b.id)) /*如果两串不相等*/
        {
            if (!feof(fp))    /*如果未到文件尾*/
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else

                break;

        }
        else
        {
            printf("此用户名已存在！请重新选择！\n");

            getchar();
            rewind(stdin);
            Sleep(800);
            system("cls");

            return;
        }
    }

    printf("请输入姓名：\n");
    scanf("%s", &a.name);

    printf("请输入性别(f(女)/m(男))：\n");
    scanf(" %c", &a.sex);

    do
    {
        if (a.sex != 'f' && a.sex != 'm')
        {
            printf("性别输入错误！请重新输入！\n");

            getchar();
            scanf("%c", &a.sex);

        }
    } while (a.sex != 'f' && a.sex != 'm');

    getchar();

    printf("请输入电话号码：\n");
    scanf("%ld", &a.phone);

    printf("请输入密码\n");
    scanf(" %s", &a.pwd);

    printf("请确认密码\n");
    scanf(" %s", &temp);

    do {

        if (!strcmp(a.pwd, temp))
        {
            fp = fopen("users.txt", "a");//追加一个账号 

            fwrite(&a, sizeof(struct The_users), 1, fp);/* a 待写入文件的指针 （地址）*/

            printf("账号注册成功，请登录。。。\n");
            Sleep(500);
            fclose(fp);

            return;
        }
        else
        {
            printf("两次密码不匹配！请重新输入！\n");
            getchar();
            scanf("%s", &a.pwd);

            printf("请确认密码\n");
            scanf("%s", &temp);
        }

    } while (1);

    return;

}


/*---------
 登录系统
---------*/

void  Input_login()
{
    users a, b;  //定义结构体The_users别名

    FILE* fp;   //文件 
    int i = 0;

    system("cls");

    system("color 06"); //背景为黑色，前景为黄色 

    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t欢迎来到登录界面！\n");

    Sleep(1500);
    system("cls");//清屏 
    Sleep(800);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b


    printf("\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入账号：                         │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //如果有此用户名
        {
            break;
        }

        else
        {
            if (fp == NULL)
            {
                printf("还未拥有注册信息，请注册\n");
                system("pause");
                system("cls");
                set();
            }


            if (!feof(fp))  //如果文件没有读完                            

            {
                fread(&b, sizeof(struct The_users), 1, fp);
                /*读出数据 b 存放的地址位置，内存大小，每次读取一个数据块 1 ，以读的方式打开文件*/
            }

            else
            {
                printf("此用户名不存在，请重新选择！\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }

    printf("\n\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入密码：                         │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 8);

    while ((a.pwd[i] = getch()) != 13)//getch()返回值是一个键值，回车的键值是13
    {                                   //将输入的密码存储在数组中在屏幕上输出‘* ’代替数字 
        i++;
        printf("*");//隐藏密码
    }
    a.pwd[i] = '\0';//把最后的回车变成结束符（数组） 
    printf("\n");

    do {

        if (strcmp(a.pwd, b.pwd) == 0)            /*如果密码匹配*/

        {
            fclose(fp);

            Sleep(500);
            printf("\n\n\t\t\t\t\t\t登录进行中");

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

            printf("\n\n\t\t\t\t\t\t登 录 成 功 !");
            Sleep(1000);
            system("cls");

            welcome(); //动画菜单   

            return;
        }
        else
        {

            printf("密码错误！");
            printf("\n\n\n");
            printf("\t\t\t\t   │============================================│\n");
            printf("\t\t\t\t   │ 请输入密码：                         │\n");
            printf("\t\t\t\t   │============================================│\n");

            cursor(50, 13);
            scanf("%s", &a.pwd);

        }

    } while (strcmp(a.pwd, b.pwd) == 0);

}





/*---------
 找回密码
----------*/

void reback()  //按结构体的大小，一次写入或者读入1个结构体大小
{
    users a, b;//结构体 The_users 重命名定义
    FILE* fp;

    char temp[20];
    //int count = 0;

    printf("欢迎来到找回密码界面！\n");
    Sleep(1000);

    fp = fopen("users.txt", "r");

    fread(&b, sizeof(struct The_users), 1, fp); //读入一个结构体字符块 写入b

    system("cls");
    system("color 06"); //背景为黑色，前景为黄色 

    printf("\n\n");
    printf("\t\t\t\t   │============================================│\n");
    printf("\t\t\t\t   │ 请输入账号：                         │\n");
    printf("\t\t\t\t   │============================================│\n");

    cursor(50, 3);
    scanf("%s", &a.id);

    while (1)
    {
        if (strcmp(a.id, b.id) == 0)         //如果有此用户名
        {
            break;
        }

        else
        {
            if (!feof(fp))  //如果文件没有读完                            

            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }

            else
            {
                printf("此用户名不存在，请重新选择！\n");

                Sleep(500);
                fclose(fp);
                getchar();

                return;
            }

        }

    }


    printf("\n\n");
    printf("请输入姓名：\n");
    scanf("%s", &a.name);

    do
    {
        if (strcmp(a.name, b.name))
        {
            printf("姓名输入错误！请重新输入！\n");
            getchar();
            scanf("%s", &a.name);
        }
    } while (strcmp(a.name, b.name));

    printf("请输入电话号码：\n");
    scanf("%ld", &a.phone);

    do {
        if (a.phone != b.phone)
        {
            printf("电话号码输入错误！请重新输入！\n");
            getchar();
            scanf("%ld", &a.phone);
        }
    } while (a.phone != b.phone);

    printf("您的密码是：%s\n", b.pwd);
    Sleep(3000);
    system("pause");
    system("cls");
}


/*-----------
 欢迎界面(动画)
-------------*/

void welcome()
{

    system("color F4");//变色、白底红字

    Windowstime();//显示当前Windows时间

    printf("\n\n");
    printf("\n\n\n\t\t\t\t");
    printf(" 欢");
    Sleep(120);
    printf(" 迎");
    Sleep(120);
    printf(" 使");
    Sleep(120);
    printf(" 用");
    Sleep(120);
    printf(" 葛");
    Sleep(120);
    printf(" 鹤");
    Sleep(120);
    printf(" 展");
    Sleep(120);
    printf(" 超");
    Sleep(120);
    printf(" 市");
    Sleep(120);
    printf(" 银");
    Sleep(120);
    printf(" 收");
    Sleep(120);
    printf(" 管");
    Sleep(120);
    printf(" 理");
    Sleep(120);
    printf(" 系");
    Sleep(120);
    printf(" 统！");
    Sleep(800);
    printf("\n");
    system("cls");

    menu();     //菜单 

}



/*-------
 进度条
-------*/

void progress()
{
    int i;
    int j;

    system("cls");

    printf("\n\n\n\n\n\t\t\t\t    \033[0;33;40m     正 在 进 入 系 统，请 稍 后 . . .   \033[0m");

    const char* LastStr = "[--------------------------------------------------] 100%";
    // 进度条标志，可以改用"*"或其它符号
    const char ProgressIcon = '*';
    // 进度每加5，进度条就会加一格，注意Step值要和LastStr中的"-"数量相匹配，两者相乘等于100
    const int Step = 2;
    // 总共需要多少进度标志，即LastStr中"-"的数量
    const int IconMaxNum = 50;

    printf("\n\n    \t\t\t\t");
    for (i = 0; i <= 100; ++i)
    {
        // -------------- 打印进度条 --------------
        printf("<");
        int currentIndex = i / Step;
        for (j = 0; j < IconMaxNum; ++j)
        {
            if (j < currentIndex)
            {
                printf("\033[0;33;1m%c", ProgressIcon); // 打印进度条标志
            }
            else
            {
                printf(" "); // 未达进度则打印空格
            }
        }
        printf("> ");
        // -------- 打印数字进度 ----------
        printf("\033[0;35;0m%3d%%", i);
        fflush(stdout);
        // 每隔100ms打印一次，这里同时每隔100ms会让进度加1
        Sleep(3 * 10);
        for (j = 0; j < strlen(LastStr); ++j)  //strlen 字符串处理函数
        {
            printf("\b");               // 回删字符，让数字和进度条原地变化
        }
        fflush(stdout); //清空输出缓存区
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
        printf("\t\t\t\t\t   ╭ ⺌ ╮          ╭ ```╮ \n");
        printf("\t\t\t\t\t   (@^o^@) 超市收银管理系统 (⌒:⌒)\n");
        printf("\t\t\t\t\t   (~):(~)                  (~)v(~) \n");
        printf("\n\n");
        printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
        printf("\t\t\t\t   │              超市收银管理系统              │\n");
        printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 1. 开始收银             2. 增删商品        │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 3. 设置折扣             4. 积分兑换与抽奖  │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 5. 查询商品信息         6. 统计商品信息    │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │            0. 退出管理系统                 │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

        Windowstime();      //windows当前时间 
        printf("\t\t请选择你要运行的选项(0-6):");
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
            	printf("还要继续收银吗？(y/n)");
            	scanf(" %c",&choice);
			}while(choice == 'y'||choice == 'Y');
            break;
        case 2:
            //调用显示商品增删二级菜单的函数
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
            printf(" 输入错误，请按回车重新输入\n");
            system("cls");   //清屏 
        }
    }
		
}

void set1()
{
    system("color F4");//变色、白底红字

    welcome1();
}


/*------------
 用户欢迎界面
-------------*/

void welcome1()
{
    //显示当前Windows时间 
    Windowstime();

    printf("\n\n");
    printf("\n\n\n\t\t\t\t");
    printf(" 欢");
    Sleep(100);
    printf(" 迎");
    Sleep(100);
    printf(" 光");
    Sleep(100);
    printf(" 临");
    Sleep(100);
    printf(" 超");
    Sleep(100);
    printf(" 市");
    Sleep(100);
    printf(" 收");
    Sleep(100);
    printf(" 银");
    Sleep(100);
    printf(" 管");
    Sleep(100);
    printf(" 理");
    Sleep(100);
    printf(" 系");
    Sleep(100);
    printf(" 统");
    Sleep(100);
    printf(" ！");
    Sleep(1000);
    printf("\n");
    system("cls");

    menu1(); //用户菜单 

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
        printf("\t\t\t\t\t   ╭ ⺌ ╮          ╭ ```╮ \n");
        printf("\t\t\t\t\t   (@^o^@) 超市收银管理系统 (⌒:⌒)\n");
        printf("\t\t\t\t\t   (~):(~)                  (~)v(~) \n");
        printf("\n\n");
        printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
        printf("\t\t\t\t   │              超市收银管理系统              │\n");
        printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
        printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 1. 开始收银             2. 增删商品        │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 3. 设置折扣             4. 积分兑换与抽奖  │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │ 5. 查询商品信息         6. 统计商品信息    │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   │            0. 退出管理系统                 │\n");
        printf("\t\t\t\t   │                                            │\n");
        printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

        Windowstime();      //windows当前时间 
        printf("\t\t请选择你要运行的选项(0-6):");
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
            	printf("还要继续收银吗？(y/n)");
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
            printf(" 输入错误，请按回车重新输入\n");
            system("cls");   //清屏 
        }
    }
	
}





