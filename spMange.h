struct shangpin{
	long spdh;//��� 
	char name[100];//���� 
	char dw[10];//��λ 
	float cb;//�ɱ� 
	float sj;//�ۼ� 
	float zk;//�ۿ� 
	float kc;//��� 
	float xse;//���۶� 
};
typedef struct shangpin SP;

//����ԭ�� 
void showSPMenu2(SP sp[],int n);//...........
int readSP(SP sp[]);
void showALLSP(SP sp[],int n);
void writeSP(SP sp[],int n);
void showFindMenu2(SP sp[],int n); 
int FindBySpdh(SP sp[],long fspdh,int n);
int FindByName(SP sp[],char fname[], int n);
void delInformation();
int saveInformation1();
void addProduct();
