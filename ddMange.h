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

void showSYMenu2(SP sp[],int n);
void addDD(SP sp[],int n);
void writeDD(DD onedd);
void readDD(DD onedd);
void FindByDDdh(DD dd,int n);
