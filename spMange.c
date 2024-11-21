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
		printf("��Ʒ��Ϣ�ļ���ʧ��!\n");
		return 0;
	}
	fscanf(fp,"%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\t%*s\n");//���Ա�����
	for (i = 0;feof(fp)==0;i++)//���ļ�д4������
		fscanf(fp,"%d\t%s\t%s\t%f\t%f\t%f\t%f\t%f\n", &sp[i].spdh,&sp[i].name,&sp[i].dw, &sp[i].cb,&sp[i].sj,&sp[i].zk,&sp[i].kc,&sp[i].xse);
	er=fclose(fp);
	if (er == 0) { printf("��Ʒ��Ϣ����ɹ�����ʼ����ɣ�\n"); }//�ж��Ƿ�رճɹ���0�ɹ�����0ʧ��
	else  printf("��Ʒ��Ϣ����ʧ�ܣ�\n");
	return i;
}
void showSYMenu2(SP sp[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d-----%s\t",sp[i].spdh,sp[i].name);\
		if((i+1)%5 == 0)
		printf("\n");//5��һ�У� 
	}
	printf("----------------\n");
}
void showALLSP2(SP sp[],int n)
{
	int i;
	printf("\n��Ʒ����\t��Ʒ����\t��λ\t�ɱ�\t�ۼ�\t�ۿ�\t���\t���۶�\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
	}
}

void showALLSP(SP sp[],int n)
{
	int i;
	printf("\n��Ʒ����\t��Ʒ����\t��λ\t�ɱ�\t�ۼ�\t�ۿ�\t���\t���۶�\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
	}
	printf("������ϣ�\n");
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
	fprintf(fp,"\n��Ʒ����\t��Ʒ����\t��λ\t�ɱ�\t�ۼ�\t�ۿ�\t���\t���۶�\n");//���ļ�д������
	for (i = 0;feof(fp)==0;i++)//���ļ�д4������
		fprintf(fp,"%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);//�洢���ѯ����Ʒ����);
	er=fclose(fp);
	if (er == 0) { printf("��Ʒ��Ϣ�����ɹ���\n"); }//�ж��Ƿ�رճɹ���0�ɹ�����0ʧ��
	else  printf("��Ʒ��Ϣ����ʧ�ܣ�\n");
	
}

//��ʾ��Ʒ��������˵� 
void showSPMenu2(SP sp[],int n)
{
	system("cls");
    int c;    
	printf("\n\t\t**********��Ʒ��ɾ��������˵�***********\n");
    printf("\t\t��-------------------------------------��\n");
    printf("\t\t|    1.������Ʒ��Ϣ                    |\n");
    printf("\t\t|    2.ɾ����Ʒ��Ϣ                    |\n");
    printf("\t\t|    3.�༭��Ʒ��Ϣ   		           |\n");
    printf("\t\t|    4.��ʾ������Ʒ��Ϣ                |\n");
    printf("\t\t|    0.�������˵�                	   |\n");
    printf("\t\t��-------------------------------------��\n");
    printf("\t\t��ѡ����Ҫ���е�ѡ��(0-5):");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            return  ;  //������������ 
            break;
        case 1:
            //����������Ʒ���� 
           addProduct();
            break;
        case 2:
            //����ɾ����Ʒ����
			delInformation(sp);
            break;
        case 3:
            
			break;
        case 4:
            showALLSP(sp,n);
            break;
        default:
            printf(" ��������밴�س���������\n");
            //system("cls");   //���� 
    }		
}

void showFindMenu2(SP sp[],int n)
{
	int c,i=-1;
	long fspdh;//�洢���ѯ����Ʒ����  
	char fname[100];
	while(1){ 
	printf("\n\t\t**********��Ʒ��ѯ��������˵�***********\n");
    printf("\t\t��-------------------------------------��\n");
    printf("\t\t|    1.��ѯ��Ʒ(�����)                |\n");
    printf("\t\t|    2.��ѯ��Ʒ(������)                |\n");
    printf("\t\t|    3.��ѯ����   		               |\n");
    printf("\t\t|    0.�������˵�                	   |\n");
    printf("\t\t��-------------------------------------��\n");
    printf("\t\t��ѡ����Ҫ���е�ѡ��(0-5):");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            return  ;  //������������ 
            break;
        case 1:
            printf("�������ѯ����Ʒ����: ");
			scanf("%d",&fspdh);
			i = FindBySpdh(sp,fspdh,n);
			if(i>-1){
				printf("���ҵ���Ʒ��Ϣ����: \n");
				printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
			} 
			else
			{
				printf("δ�ҵ���ѯ����Ʒ��Ϣ��\n");
			}
            break;
        case 2:
            printf("�������ѯ����Ʒ����: ");
            scanf(" %s",&fname);
		    i = FindByName(sp,fname,n);
		    if(i>-1){
				printf("���ҵ���Ʒ��Ϣ����: \n");
				printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",sp[i].spdh,sp[i].name,sp[i].dw, sp[i].cb,sp[i].sj,sp[i].zk,sp[i].kc,sp[i].xse);
			} 
			else
			{
				printf("δ�ҵ���ѯ����Ʒ��Ϣ��\n");
			}
			break;
        case 3:
            
			break;
         default:
            printf(" ��������밴�س���������\n");
            //system("cls");   //���� 
    }		
  }
}
int FindBySpdh(SP sp[],long fspdh,int n)
{
	int i;
	for(i = 0;i < n;i++)
		if(sp[i].spdh == fspdh)
		{
			return i;  //����ѭ���������������� 
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
	FILE *file = fopen("data.txt", "a"); // �Զ�дģʽ���ļ�������������򴴽�  
    SP product;  
    printf("\n\n");
    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
    printf("\t\t\t\t   ��                 ������Ʒ��Ϣ               ��\n");
    printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� ��Ʒ��ţ�                    ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� ���ƣ�                        ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� ��λ��                        ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� �ɱ���                        ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� �ۼۣ�                        ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� �ۿۣ�                        ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� ���:                         ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   �� ���۶                      ��\n");
    printf("\t\t\t\t   ��==========================================  ��\n");
    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");

    cursor(47, 7);
    scanf("%d", &product.spdh);//��� 

    cursor(44, 9);
    scanf("%s", &product.name);//���� 

    cursor(44, 11);
    scanf("%s", &product.dw);//��λ 

    cursor(44, 13);
    fflush(stdin);
    scanf("%f", &product.cb);//�ɱ� 
    getchar();
    
    cursor(44, 15);
    fflush(stdin);
    scanf("%f",&product.sj);//�ۼ� 

    cursor(44, 17);
    scanf("%f",&product.zk);//�ۿ� 

    cursor(44, 19);
    scanf("%f", &product.kc);//����� 

    cursor(46, 21);
    scanf("%f", &product.xse);//���۶� 
  
   // д���ļ�  
    rewind(file); // ���ļ�ָ���Ƶ��ļ���ͷ  
    if (ftell(file) != 0) { // ����ļ���Ϊ�գ�����ĩβ���һ�����з�  
        fseek(file, 0, SEEK_END);  
        fputc('\n', file);  
    }  
    fprintf(file, "%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",product.spdh, product.name, product.dw,product.cb, product.sj,product.zk,product.kc, product.xse);  
    fflush(file); // ȷ������д����� 
}  
	
void readInformation()  
{  
    FILE* fp;   /*�ļ�ָ��*/  
    SP* p;    /*�ṹ��ָ��*/ 
  
    fp = fopen("data.txt", "r");    
    
    if (fp == NULL) {    
        printf("���ļ�ʧ�ܣ�");    
        exit(1);    
    }    
    
    // ��ȡ������������  
    char dummy[1024]; // ��������в��ᳬ��1023���ַ�������һ��'\0'��������  
    if (fgets(dummy, sizeof(dummy), fp) == NULL) {  
        // �����ȡ������ʧ�ܣ���������ļ�Ϊ�ջ�����������  
        printf("��ȡ������ʧ�ܻ��ļ�Ϊ�գ�");  
        fclose(fp);  
        exit(1);  
    }  
  
    // ���ڿ�ʼ��ȡ������  
    while (!feof(fp)) {    
        p = (SP*)malloc(sizeof(SP));    
        if (p == NULL) {    
            printf("�ڴ����ʧ�ܣ�");    
            fclose(fp);    
            exit(1);  
        }    
        p->next = NULL;     
    
        // ��ȡ���ݣ������fscanf�ķ���ֵ    
        if (fscanf(fp, "%d\t%s\t%s\t%f\t%f\t%f\t%f\t%f\n", &p->spdh, &p->name,&p->dw, &p->cb, &p->sj, &p->zk, &p->kc, &p->xse) != 8) {    
            // ��ȡʧ�ܻ��ļ��������ͷ�p   
			free(p);   
            break;    
        }    
    
        // ����ǵ�һ���ڵ㣬��headָ����    
        if (head == NULL) {    
            head = p;    
            p1 = head;    
        } else {    
            p1->next = p;    
            p1 = p;    
        }    
    }    
    
    if (fclose(fp) == EOF) {    
        printf("�ر��ļ�ʧ��");    
        exit(1);    
    }    

    printf("�ļ�ͳ�Ƴɹ�. . .");    
    printf("\n\n\n");    
    system("pause");  // ������Ҫ�����Ƿ�ʹ��  
    system("cls");    // ������Ҫ�����Ƿ�ʹ�ã����ⲻ�ǿ�ƽ̨��  
  
    return;  
}

void deleteProduct(const char *filename, const char *productId) {  
    FILE *fp_in, *fp_out;  
    char line[1024];  
    char temp_filename[] = "temp.txt";  
    char id[1024]; // ������Ʒ��Ų��ᳬ��1023���ַ�  
  
    // �������ļ�  
    fp_in = fopen(filename, "r");  
    if (fp_in == NULL) {  
        perror("���ļ�ʧ��");  
        exit(1);  
    }  
  
    // �򿪣��򴴽�������ļ�  
    fp_out = fopen(temp_filename, "w");  
    if (fp_out == NULL) {  
        perror("������ʱ�ļ�ʧ��");  
        fclose(fp_in);  
        exit(1);  
    }  
  
    // ��ȡ��������Ʒ��Ϣ  
    int isFirstLine = 1; // ��������������  
    while (fgets(line, sizeof(line), fp_in) != NULL) {  
        if (isFirstLine) {  
            // ���Ʊ����е�����ļ�  
            fputs(line, fp_out);  
            isFirstLine = 0;  
            continue;  
        }  
  
        // ��ȡ��Ʒ���  
        sscanf(line, "%[^\t]", id); // ��ȡֱ�������Ʊ��Ϊֹ  
  
        // �����Ʒ����Ƿ�ƥ��Ҫɾ������Ʒ  
        if (strcmp(id, productId) != 0) {  
            // �����ƥ�䣬��д����ʱ�ļ�  
            fputs(line, fp_out);  
        }  
    }  
  
    // �ر��ļ�  
    fclose(fp_in);  
    fclose(fp_out);  
  
    // ɾ��ԭ�ļ�  
    remove(filename);  
  
    // ����ʱ�ļ�������Ϊԭ�ļ���  
    rename(temp_filename, filename);  
  
    printf("��Ʒɾ���ɹ���\n");  
}  

int saveInformation1()
{
	
    FILE* fp;//�ļ�ָ�� 
    SP* p;//��Ʒ��Ϣָ�� 
    p = head;//p��ֵΪͷ��� 

    fp = fopen("data.txt", "w");//д���ļ���Ϣ 

    if (fp == NULL)//�ж��ļ��Ƿ������� 
    {
        printf("���ܴ��ļ���");
        exit(1);
    }

    while (p != NULL)//p2��Ϊ��ʱ�������ݵ�¼��
    {

        fprintf(fp, "%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",p->spdh, p->name, p->dw, p->cb, p->sj, p->zk, p->kc, p->xse);

        p = p->next;

    }

    Sleep(800);

    printf("\n");
    printf("�ļ����ݸ��³ɹ���\n");

    getch();

    system("pause");
    system("cls");
    //break;

    if (fclose(fp))
    {
        printf("���ܹر��ļ���");
        exit(1);
    }

}
	
void delInformation(SP sp[])
{

    int option;//�û������ѡ��
    int s_option;//�ж�ѡ�� 
	int s_num=0;


	do{
	
	    printf("\n");
	    printf("\t��-^-^-^-^-^-^-^-^-��\n");;
	    printf("\t |1����ѯɾ��      |\n");
	    printf("\t |2���˳�ɾ��      |\n");
	    printf("\t�� V-V-V-V-V-V-V-V-��\n");
	
	    rewind(stdin);
	    printf("��ѡ��");
	    scanf("%d", &option);
	
	
	    switch (option)
	    {
	
		    case 1://���ɾ�� 
		
		        system("pause");
		        system("cls");
				
		        printf("\n\n");
		        printf("\t\t\t\t   ��==========================================  ��\n");
		        printf("\t\t\t\t   �� ��������Ʒ��ţ�                   ��\n");
		        printf("\t\t\t\t   ��==========================================  ��\n");
					
		        cursor(54, 3);
		        scanf("%d",&s_num);
		                printf("\n\n");
		                printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
		                printf("\t\t\t\t   ��                    ��Ʒ��Ϣ               ��\n");
		                printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		                printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
		                printf("\t\t\t\t   �� 1.��ţ�%d                        ��\n", sp[s_num-1].spdh);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 2.���ƣ�%s                        ��\n", sp[s_num-1].name);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 5.��λ��%s                        ��\n", sp[s_num-1].dw);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 4.�ɱ���%.2f                        ��\n", sp[s_num-1].cb);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 3.�۸�%.2f                        ��\n", sp[s_num-1].sj);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 7.�ۿۣ�%.2f                        ��\n",sp[s_num-1].zk);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 4.��棺%.2f                        ��\n",sp[s_num-1].kc);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   �� 9.���۶%.2f                      ��\n", sp[s_num-1].xse);
		                printf("\t\t\t\t   ��==========================================  ��\n");
		                printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");
		
		
		                printf("�Ƿ�ѡ��ɾ��?\n");
		                printf("1--yse  0--no\n");
		
		
		                printf("��ѡ��");
		                scanf("%d", &s_option);
		
		
		                if (s_option == 1)
		                {
		                    printf("ɾ��������");
		
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
		                    char productId[11]; // ������ƷID���ᳬ��10λ���֣�����һ�����ַ�'\0'  
			    			snprintf(productId, sizeof(productId), "%d", s_num); // ������ת��Ϊ�ַ���  
		                    deleteProduct("data.txt", productId);
		
		                }
		                else if (s_option == 0)
		                {
		                    printf("ȡ��ɾ��!");
		                }
	
	    case 2:   //�˳�ɾ�� 
	        printf("��лʹ�ã�\n");
	        break;
	
	    default:
	        printf("����������˳���\n");
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
		       	printf("\n\t\t******��Ʒ�齱��������˵�*********\n");
				printf("\t\t��-------------------------------------��\n");
				printf("\t\t|    1.��ʼ�齱	                       |\n");
				printf("\t\t|    0.�������˵�                	   |\n");
				printf("\t\t��-------------------------------------��\n");
				showSYMenu2(sp, n);  
				printf("\t��ѡ����Ҫ���е�ѡ��(0-1):\n");
				scanf("%d",&c);
			if(c==1){
		        printf("���ڳ齱...\n"); 
				Sleep(1000); 
		        	static bool srandCalled = false;
						if (!srandCalled) {
							srand(time(NULL));
							srandCalled = true;
						}
					
						// ����һ���������  
						int u = rand() % n; 
		            printf("\n\n");
				    printf("\t\t\t\t   �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�����T�T�T�r\n");
				    printf("\t\t\t\t   ��                 �н���Ʒ��Ϣ               ��\n");
				    printf("\t\t\t\t   �t�T�T�T�����T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
				    printf("\t\t\t\t   ����������������������������������������������������������������������������������������-��\n");
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� ��ţ�%d                      ��\n", sp[u].spdh);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� ���ƣ�%s                      ��\n",sp[u].name);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� ��λ��%s                      ��\n", sp[u].dw);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� �ɱ���%.2f                    ��\n", sp[u].cb);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� �ۼۣ�%.2f                    ��\n",sp[u].sj);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� �ۿۣ�%.2f                    ��\n",sp[u].zk);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� ���: %.2f                    ��\n",sp[u].kc);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   �� ���۶%.2f                  ��\n", sp[u].xse);
				    printf("\t\t\t\t   ��==========================================  ��\n");
				    printf("\t\t\t\t   ��������������������������������������������������������������������������������������������\n");  
		    }
		    if(c==0){
		    	break;
			}
		        printf("��Ҫ�����齱��(y/n): \n");  
		        if (scanf(" %c", &choice) != 1) {  
		            while (getchar() != '\n'); 
		            printf("�����������������(y/n): ");  
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
		printf("��Ʒ����:");
		scanf("%d",&spdh);
		printf("��Ʒ����:");
		scanf("%d",&num);
		//������Ʒ����spdh ���Ҹ���Ʒ��Ϣ
		//�ж�num�Ƿ�<=��Ʒ�Ŀ������
		//�������������Ϣ //������ʾ��Ʒ��治��
		i = FindBySpdh(sp,spdh,n);
		if(i>-1)//��Ʒ����
		{
			if(num <= sp[i].kc)
			{
				DD dd;
				dd.did = suijiNum;
				dd.spdh = sp[i].spdh;
				strcpy(dd.name,sp[i].name);
				strcpy(dd.dw,sp[i].dw);
				dd.num = num;totalNum += num;//�ۼƼ�����
				dd.sj= sp[i].sj;
				dd.zk = sp[i].zk;
				dd.ze = sp[i].sj*num*sp[i].zk;//�ܶ 
				totalCash += dd.ze;//�ۼ��ܽ�
				//���ú�������dd׷��д�뱣�涩�����ļ���(cash.txt)
				writeDD(dd);
				printf("\n��Ʒ����\t��Ʒ����\t��λ\t����\t�ۼ�\t�ۿ�\t�ܶ�\n");
				printf("%d\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n",dd.spdh,dd.name,dd.dw,dd.num,dd.sj,dd.zk,dd.ze);
			}
			else
			    printf("\n��Ʒ��治�㣡\n");	    
		 } 
		 printf("��Ҫ����������(y/n)");
	     scanf(" %c",&choice);
	}while(choice == 'y'|| choice == 'Y');
	printf("\n����������%d������%.2fԪ\n",totalNum,totalCash);
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
    if (er == 0) { printf("����ɹ���\n"); }//�ж��Ƿ�رճɹ���0�ɹ�����0ʧ��
	else  printf("����ʧ�ܣ�\n");
 } 
 void FindByDDdh(DD dd,int n)
 {
 	
  } 
