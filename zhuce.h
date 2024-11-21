//注册信息 
typedef struct The_users
{
    char id[11]; //账号 
    char pwd[20]; //密码 
    char name[15];//姓名为字符串 
    char sex; //性别为单个字符
    long phone; //电话号码为长整型 

}users;



/*--------------

函数声明

----------------*/


//初始化界面
void set();//管理员
void set1();//用户 

//进度条 
void progress();

//注册账户 
void registers();

//登陆账户 
void  Input_login();

//界面（动画） 
void welcome();//管理员 
void welcome1();//用户 

//菜单显示
void menu();//管理员

//显示Windows当前时间
void Windowstime();

//找回密码 
void reback();

//光标定位 
void cursor(int x, int y);



//退出系统 
void reout();


