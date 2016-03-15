#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
char AK[50]="iFYg0UuCbUHK_eSj1SxzjrAH68kVtRoPKyhTcOiv";
char SK[50]="ocn7jjNDyYUQjjrJNS49RZi881NA60My8kZRq3f3";
char LK[50]="7xrasr.com1.z0.glb.clouddn.com";
char BK[50]="oucjudge";
//上面是七牛的密钥以及空间链接名称和空间的名称

char lockname[20];//锁定名
char myname[20];//用户名
int flag;//这是唯一一个可以直接引用的全局变量，不允许其他变量名为flag
int lock_status;//是否锁定

using namespace std;
#include "order.h"
//order.h 含有负责处理命令行的函数
#include "login.h"
//login.h 含有负责处理登陆的函数
#include "help.h"
//help.h 含有帮助函数
#include "clear.h"
//clear.h 含有清空历史记录的函数
#include "history.h"
//history.h 含有显示历史记录的函数
#include "send.h"
//send.h 含有发送附件的函数

//下面这些函数仅为了保证程序可以编译，若要调试函数，请删除同名函数。
int sign(char *x,char *y){
	return 1;
}
void find(char *x){}
int lock(char *x){
	return 1;
}
void msg(char *x,char *y,char *z){}
void frd(){}
void refresh(void){}
//以上


int main(){
	char tmp[500];
	struct order_class cmd;
	int login_status=login(myname);
	if (!login_status){
		while (1){
			cout<<"Please login >";
			fgets(tmp,100,stdin);
			cmd=order(tmp);
			if (cmd.argv==-1) printf("%s\n",cmd.error);
			else if (cmd.argv==10) return 0;
			else if (!cmd.argv) {
				if (sign(cmd.argc[0],cmd.argc[1])) {
					printf("Hello, %s\n",cmd.argc[0]);
					strcpy(myname,cmd.argc[0]);
					break;
				}
				else printf("Failed\n");
			}
		}
	}
	else printf("Hello, %s\n",myname);

	while (1){
		printf("<%s>",myname);
		if (lock_status) printf("to <%s>",lockname);
		fgets(tmp,100,stdin);
		cmd=order(tmp);
		if (cmd.argv==3) {
			if (lock(cmd.argc[1])) {
				strcpy(lockname,cmd.argc[1]);
				lock_status=1;
				continue;
			}
		}
		switch(cmd.argv){
			case -1:printf("%s\n",cmd.error);break;
			case 1 :frd();break;
			case 2 :find(cmd.argc[1]);break;
			case 4 :if (lock_status) msg(myname,lockname,cmd.argc[1]);break;
			case 5 :refresh();break;
			case 6 :if (lock_status) send(myname,lockname,cmd.argc[1]);break;
			case 7 :if (lock_status) h(lockname);break;
			case 8 :if (lock_status) c(lockname);break;
			case 9 :_help();break;
			case 10:return 0;break;
			case 11:system("rm -f .location.conf");system("rm -f *.his");return 0;
		}
	}
	return 0;
}
