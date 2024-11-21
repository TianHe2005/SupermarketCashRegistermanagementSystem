#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h>

struct shangpin{
	long spdh;
	char name[100];
	char dw[10];
	float cb;
	float sj;
	float zk;
	float kc;
	float xse;
	struct shangping* next;
};
typedef struct shangpin SP;
	SP* head = NULL;
	SP* p1 = NULL;

int readSP(SP sp[])
{
	FILE* fp;
	int i,er;
     fp=fopen("data.txt", "r");
	if (fp==NULL)
	{
		printf("商品信息文件打开失败!\n");
		return 0;
	}
	fscanf(fp,"%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");//忽略标题行
	for (i = 0;feof(fp)==0;i++)//往文件写4行数据
		fscanf(fp,"%d\t%s\t%s\t%f\t%f\t%f\t%f\t%f\n", &sp[i].spdh,&sp[i].name,&sp[i].dw, &sp[i].cb,&sp[i].sj,&sp[i].zk,&sp[i].kc,&sp[i].xse);
	er=fclose(fp);
	if (er == 0) { printf("商品信息导入成功！初始化完成！\n"); }//判断是否关闭成功。0成功；非0失败
	else  printf("商品信息导入失败！\n");
	return i;
}
void showSYMenu2(SP sp[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d-----%s\t",sp[i].spdh,sp[i].name);\
		if((i+1)%5 == 0)
		printf("\n");//5个一行； 
	}
	printf("----------------\n");
}
void showALLSP2(SP sp[],int n)
{
	int i;
	printf("\n商品代号\t商品名称\t单位\t成本\t售价\t折扣\t库存\t销售额\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
	}
}

void showALLSP(SP sp[],int n)
{
	int i;
	printf("\n商品代号\t商品名称\t单位\t成本\t售价\t折扣\t库存\t销售额\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
	}
	printf("输入完毕！\n");
	system("pause");
}
void writeSP(SP sp[],int n)
{
	FILE* fp;
	int i,er;
     fp=fopen("output.txt", "w");
	if (fp==0)
	{
		printf("eorr!\n");
		return ;
	}
	fprintf(fp,"\n商品代号\t商品名称\t单位\t成本\t售价\t折扣\t库存\t销售额\n");//往文件写标题行
	for (i = 0;feof(fp)==0;i++)//往文件写4行数据
		fprintf(fp,"%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);//存储需查询的商品代号);
	er=fclose(fp);
	if (er == 0) { printf("商品信息导出成功！\n"); }//判断是否关闭成功。0成功；非0失败
	else  printf("商品信息导出失败！\n");
	
}

//显示商品管理二级菜单 
void showSPMenu2(SP sp[],int n)
{
	system("cls");
    int c;    
	printf("\n\t\t**********商品增删管理二级菜单***********\n");
    printf("\t\t┌-------------------------------------┐\n");
    printf("\t\t|    1.增加商品信息                    |\n");
    printf("\t\t|    2.删除商品信息                    |\n");
    printf("\t\t|    3.编辑商品信息   		           |\n");
    printf("\t\t|    4.显示所有商品信息                |\n");
    printf("\t\t|    0.返回主菜单                	   |\n");
    printf("\t\t└-------------------------------------┘\n");
    printf("\t\t请选择你要运行的选项(0-5):");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            return  ;  //返回主调函数 
            break;
        case 1:
            //调用增加商品函数 
           addProduct();
            break;
        case 2:
            //调用删除商品函数
			delInformation(sp);
            break;
        case 3:
            
			break;
        case 4:
            showALLSP(sp,n);
            break;
        default:
            printf(" 输入错误，请按回车重新输入\n");
            //system("cls");   //清屏 
    }		
}

void showFindMenu2(SP sp[],int n)
{
	int c,i=-1;
	long fspdh;//存储需查询的商品代号  
	char fname[100];
	while(1){ 
	printf("\n\t\t**********商品查询管理二级菜单***********\n");
    printf("\t\t┌-------------------------------------┐\n");
    printf("\t\t|    1.查询商品(按编号)                |\n");
    printf("\t\t|    2.查询商品(按名称)                |\n");
    printf("\t\t|    3.查询订单   		               |\n");
    printf("\t\t|    0.返回主菜单                	   |\n");
    printf("\t\t└-------------------------------------┘\n");
    printf("\t\t请选择你要运行的选项(0-5):");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            return  ;  //返回主调函数 
            break;
        case 1:
            printf("请输入查询的商品代号: ");
			scanf("%d",&fspdh);
			i = FindBySpdh(sp,fspdh,n);
			if(i>-1){
				printf("查找的商品信息如下: \n");
				printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
			} 
			else
			{
				printf("未找到查询的商品信息！\n");
			}
            break;
        case 2:
            printf("请输入查询的商品名称: ");
            scanf(" %s",&fname);
		    i = FindByName(sp,fname,n);
		    if(i>-1){
				printf("查找的商品信息如下: \n");
				printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
			} 
			else
			{
				printf("未找到查询的商品信息！\n");
			}
			break;
        case 3:
            
			break;
         default:
            printf(" 输入错误，请按回车重新输入\n");
            //system("cls");   //清屏 
    }		
  }
}
int FindBySpdh(SP sp[],long fspdh,int n)
{
	int i;
	for(i = 0;i < n;i++)
		if(sp[i].spdh == fspdh)
		{
			return i;  //结束循环，返回主调函数 
		}	
    return -1; 	
} 
int FindByName(SP sp[],char fname[],int n)
{
    int i;
	
	for(i = 0;i < n;i++)
		if(strcmp(sp[i].name,fname) == 0)
		{
			return i;  
		}	
	return -1;
}
	
	



void addProduct() {  
	system("cls");
	FILE *file = fopen("data.txt", "a"); // 以读写模式打开文件，如果不存在则创建  
    SP product;  
    printf("\n\n");
    printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
    printf("\t\t\t\t   │                 超市商品信息               │\n");
    printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 商品编号：                    │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 名称：                        │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 单位：                        │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 成本：                        │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 售价：                        │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 折扣：                        │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 库存:                         │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   │ 销售额：                      │\n");
    printf("\t\t\t\t   │==========================================  │\n");
    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");

    cursor(47, 7);
    scanf("%d", &product.spdh);//编号 

    cursor(44, 9);
    scanf("%s", &product.name);//名称 

    cursor(44, 11);
    scanf("%s", &product.dw);//单位 

    cursor(44, 13);
    fflush(stdin);
    scanf("%f", &product.cb);//成本 
    getchar();
    
    cursor(44, 15);
    fflush(stdin);
    scanf("%f",&product.sj);//售价 

    cursor(44, 17);
    scanf("%f",&product.zk);//折扣 

    cursor(44, 19);
    scanf("%f", &product.kc);//销库存 

    cursor(46, 21);
    scanf("%f", &product.xse);//销售额 
  
   // 写入文件  
    rewind(file); // 将文件指针移到文件开头  
    if (ftell(file) != 0) { // 如果文件不为空，则在末尾添加一个换行符  
        fseek(file, 0, SEEK_END);  
        fputc('\n', file);  
    }  
    fprintf(file, "%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",product.spdh, product.name, product.dw,product.cb, product.sj,product.zk,product.kc, product.xse);  
    fflush(file); // 确保数据写入磁盘 
}  
	
void readInformation()  
{  
    FILE* fp;   /*文件指针*/  
    SP* p;    /*结构体指针*/ 
  
    fp = fopen("data.txt", "r");    
    
    if (fp == NULL) {    
        printf("打开文件失败！");    
        exit(1);    
    }    
    
    // 读取并丢弃标题行  
    char dummy[1024]; // 假设标题行不会超过1023个字符（加上一个'\0'结束符）  
    if (fgets(dummy, sizeof(dummy), fp) == NULL) {  
        // 如果读取标题行失败，则可能是文件为空或发生其他错误  
        printf("读取标题行失败或文件为空！");  
        fclose(fp);  
        exit(1);  
    }  
  
    // 现在开始读取数据行  
    while (!feof(fp)) {    
        p = (SP*)malloc(sizeof(SP));    
        if (p == NULL) {    
            printf("内存分配失败！");    
            fclose(fp);    
            exit(1);  
        }    
        p->next = NULL;     
    
        // 读取数据，并检查fscanf的返回值    
        if (fscanf(fp, "%d\t%s\t%s\t%f\t%f\t%f\t%f\t%f\n", &p->spdh, &p->name,&p->dw, &p->cb, &p->sj, &p->zk, &p->kc, &p->xse) != 8) {    
            // 读取失败或文件结束，释放p   
			free(p);   
            break;    
        }    
    
        // 如果是第一个节点，让head指向它    
        if (head == NULL) {    
            head = p;    
            p1 = head;    
        } else {    
            p1->next = p;    
            p1 = p;    
        }    
    }    
    
    if (fclose(fp) == EOF) {    
        printf("关闭文件失败");    
        exit(1);    
    }    

    printf("文件统计成功. . .");    
    printf("\n\n\n");    
    system("pause");  // 根据需要决定是否使用  
    system("cls");    // 根据需要决定是否使用，且这不是跨平台的  
  
    return;  
}

void deleteProduct(const char *filename, const char *productId) {  
    FILE *fp_in, *fp_out;  
    char line[1024];  
    char temp_filename[] = "temp.txt";  
    char id[1024]; // 假设商品编号不会超过1023个字符  
  
    // 打开输入文件  
    fp_in = fopen(filename, "r");  
    if (fp_in == NULL) {  
        perror("打开文件失败");  
        exit(1);  
    }  
  
    // 打开（或创建）输出文件  
    fp_out = fopen(temp_filename, "w");  
    if (fp_out == NULL) {  
        perror("创建临时文件失败");  
        fclose(fp_in);  
        exit(1);  
    }  
  
    // 读取并过滤商品信息  
    int isFirstLine = 1; // 用于跳过标题行  
    while (fgets(line, sizeof(line), fp_in) != NULL) {  
        if (isFirstLine) {  
            // 复制标题行到输出文件  
            fputs(line, fp_out);  
            isFirstLine = 0;  
            continue;  
        }  
  
        // 提取商品编号  
        sscanf(line, "%[^\t]", id); // 读取直到遇到制表符为止  
  
        // 检查商品编号是否匹配要删除的商品  
        if (strcmp(id, productId) != 0) {  
            // 如果不匹配，则写入临时文件  
            fputs(line, fp_out);  
        }  
    }  
  
    // 关闭文件  
    fclose(fp_in);  
    fclose(fp_out);  
  
    // 删除原文件  
    remove(filename);  
  
    // 将临时文件重命名为原文件名  
    rename(temp_filename, filename);  
  
    printf("商品删除成功！\n");  
}  

int saveInformation1()
{
	
    FILE* fp;//文件指针 
    SP* p;//商品信息指针 
    p = head;//p赋值为头结点 

    fp = fopen("data.txt", "w");//写入文件信息 

    if (fp == NULL)//判断文件是否正常打开 
    {
        printf("不能打开文件！");
        exit(1);
    }

    while (p != NULL)//p2不为空时进行数据的录入
    {

        fprintf(fp, "%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",p->spdh, p->name, p->dw, p->cb, p->sj, p->zk, p->kc, p->xse);

        p = p->next;

    }

    Sleep(800);

    printf("\n");
    printf("文件数据更新成功！\n");

    getch();

    system("pause");
    system("cls");
    //break;

    if (fclose(fp))
    {
        printf("不能关闭文件！");
        exit(1);
    }

}
	
void delInformation(SP sp[])
{

    int option;//用户输入的选项
    int s_option;//判断选项 
	int s_num=0;


	do{
	
	    printf("\n");
	    printf("\t┌-^-^-^-^-^-^-^-^-┐\n");;
	    printf("\t |1、查询删除      |\n");
	    printf("\t |2、退出删除      |\n");
	    printf("\t└ V-V-V-V-V-V-V-V-┘\n");
	
	    rewind(stdin);
	    printf("请选择：");
	    scanf("%d", &option);
	
	
	    switch (option)
	    {
	
		    case 1://编号删除 
		
		        system("pause");
		        system("cls");
				
		        printf("\n\n");
		        printf("\t\t\t\t   │==========================================  │\n");
		        printf("\t\t\t\t   │ 请输入商品编号：                   │\n");
		        printf("\t\t\t\t   │==========================================  │\n");
					
		        cursor(54, 3);
		        scanf("%d",&s_num);
		                printf("\n\n");
		                printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
		                printf("\t\t\t\t   │                    商品信息               │\n");
		                printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
		                printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
		                printf("\t\t\t\t   │ 1.编号：%d                        │\n", sp[s_num-1].spdh);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 2.名称：%s                        │\n", sp[s_num-1].name);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 5.单位：%s                        │\n", sp[s_num-1].dw);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 4.成本：%.2f                        │\n", sp[s_num-1].cb);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 3.价格：%.2f                        │\n", sp[s_num-1].sj);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 7.折扣：%.2f                        │\n",sp[s_num-1].zk);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 4.库存：%.2f                        │\n",sp[s_num-1].kc);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   │ 9.销售额：%.2f                      │\n", sp[s_num-1].xse);
		                printf("\t\t\t\t   │==========================================  │\n");
		                printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
		
		
		                printf("是否选择删除?\n");
		                printf("1--yse  0--no\n");
		
		
		                printf("请选择：");
		                scanf("%d", &s_option);
		
		
		                if (s_option == 1)
		                {
		                    printf("删除进行中");
		
		                    Sleep(500);
		                    printf(".");
		                    Sleep(500);
		                    printf(".");
		                    Sleep(500);
		                    printf(".");
		                    Sleep(500);
		                    printf(".");
		                    Sleep(500);
		                    printf(".");
		                    Sleep(500);
		                    printf(".\n");
		                    Sleep(1000);
		                    fflush(stdin);
		                    char productId[11]; // 假设商品ID不会超过10位数字，加上一个空字符'\0'  
			    			snprintf(productId, sizeof(productId), "%d", s_num); // 将整数转换为字符串  
		                    deleteProduct("data.txt", productId);
		
		                }
		                else if (s_option == 0)
		                {
		                    printf("取消删除!");
		                }
	
	    case 2:   //退出删除 
	        printf("感谢使用！\n");
	        break;
	
	    default:
	        printf("输入错误，已退出！\n");
	        system("pause");
	        break;
	
	    }
	}while(option==1);

}
	

	
void choujiang(SP sp[],int n){
	int c;
	char choice;
	do {    
		        system("cls");
		       	printf("\n\t\t******商品抽奖管理二级菜单*********\n");
				printf("\t\t┌-------------------------------------┐\n");
				printf("\t\t|    1.开始抽奖	                       |\n");
				printf("\t\t|    0.返回主菜单                	   |\n");
				printf("\t\t└-------------------------------------┘\n");
				showSYMenu2(sp, n);  
				printf("\t请选择你要运行的选项(0-1):\n");
				scanf("%d",&c);
			if(c==1){
		        printf("正在抽奖...\n"); 
				Sleep(1000); 
		        	static bool srandCalled = false;
						if (!srandCalled) {
							srand(time(NULL));
							srandCalled = true;
						}
					
						// 生成一个随机索引  
						int u = rand() % n; 
		            printf("\n\n");
				    printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				    printf("\t\t\t\t   │                 中奖商品信息               │\n");
				    printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				    printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 编号：%d                      │\n", sp[u].spdh);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 名称：%s                      │\n",sp[u].name);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 单位：%s                      │\n", sp[u].dw);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 成本：%.2f                    │\n", sp[u].cb);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 售价：%.2f                    │\n",sp[u].sj);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 折扣：%.2f                    │\n",sp[u].zk);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 库存: %.2f                    │\n",sp[u].kc);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   │ 销售额：%.2f                  │\n", sp[u].xse);
				    printf("\t\t\t\t   │==========================================  │\n");
				    printf("\t\t\t\t   └────────────────────────────────────────────┘\n");  
		    }
		    if(c==0){
		    	break;
			}
		        printf("还要继续抽奖吗？(y/n): \n");  
		        if (scanf(" %c", &choice) != 1) {  
		            while (getchar() != '\n'); 
		            printf("输入错误，请重新输入(y/n): ");  
		            scanf(" %c", &choice);  
		        }  
		    } while (choice == 'y' || choice == 'Y'); 
		    
		    
	}



struct dingdan{
	long did;
	long spdh;
	char name[100];
	char dw[10];
	int num;
	float sj;
	float zk;
	float ze;
};
typedef struct dingdan DD;



void addDD(SP sp[],int n)
{
	long spdh;
	int num,totalNum = 0;
	int i;
	float totalCash = 0;
	char choice;
	srand(time(NULL));
	long suijiNum=rand() % 1000 +1;
	do{
		printf("商品代号:");
		scanf("%d",&spdh);
		printf("商品数量:");
		scanf("%d",&num);
		//根据商品代号spdh 查找该商品信息
		//判断num是否<=商品的库存数量
		//是则产生订单信息 //否则提示商品库存不足
		i = FindBySpdh(sp,spdh,n);
		if(i>-1)//商品存在
		{
			if(num <= sp[i].kc)
			{
				DD dd;
				dd.did = suijiNum;
				dd.spdh = sp[i].spdh;
				strcpy(dd.name,sp[i].name);
				strcpy(dd.dw,sp[i].dw);
				dd.num = num;totalNum += num;//累计件数；
				dd.sj= sp[i].sj;
				dd.zk = sp[i].zk;
				dd.ze = sp[i].sj*num*sp[i].zk;//总额； 
				totalCash += dd.ze;//累计总金额；
				//调用函数，将dd追加写入保存订单的文件中(cash.txt)
				writeDD(dd);
				printf("\n商品代号\t商品名称\t单位\t数量\t售价\t折扣\t总额\n");
				printf("%d\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n",dd.spdh,dd.name,dd.dw,dd.num,dd.sj,dd.zk,dd.ze);
			}
			else
			    printf("\n商品库存不足！\n");	    
		 } 
		 printf("还要继续购买吗？(y/n)");
	     scanf(" %c",&choice);
	}while(choice == 'y'|| choice == 'Y');
	printf("\n本次收银共%d件，共%.2f元\n",totalNum,totalCash);
}

void writeDD(DD onedd)
{
	FILE *fp;
	int i,er; 
	fp=fopen("cash.txt","a") ;
	if(fp==0)
	  {
	   printf("eorr!\n"); 
	   return ; 
	  } 
	fprintf(fp,"%d\t%d\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n",onedd.did,onedd.spdh,onedd.name,onedd.dw,onedd.num,onedd.sj,onedd.zk,onedd.ze); 
	er=fclose(fp); 
    if (er == 0) { printf("导入成功！\n"); }//判断是否关闭成功。0成功；非0失败
	else  printf("导入失败！\n");
 } 
 void FindByDDdh(DD dd,int n)
 {
 	
  } 
