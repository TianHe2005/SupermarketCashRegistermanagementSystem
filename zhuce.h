//ע����Ϣ 
typedef struct The_users
{
    char id[11]; //�˺� 
    char pwd[20]; //���� 
    char name[15];//����Ϊ�ַ��� 
    char sex; //�Ա�Ϊ�����ַ�
    long phone; //�绰����Ϊ������ 

}users;



/*--------------

��������

----------------*/


//��ʼ������
void set();//����Ա
void set1();//�û� 

//������ 
void progress();

//ע���˻� 
void registers();

//��½�˻� 
void  Input_login();

//���棨������ 
void welcome();//����Ա 
void welcome1();//�û� 

//�˵���ʾ
void menu();//����Ա

//��ʾWindows��ǰʱ��
void Windowstime();

//�һ����� 
void reback();

//��궨λ 
void cursor(int x, int y);



//�˳�ϵͳ 
void reout();


