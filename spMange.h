struct shangpin{
	long spdh;//编号 
	char name[100];//名称 
	char dw[10];//单位 
	float cb;//成本 
	float sj;//售价 
	float zk;//折扣 
	float kc;//库存 
	float xse;//销售额 
};
typedef struct shangpin SP;

//函数原型 
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
