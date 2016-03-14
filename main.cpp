#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

#include "order.h"
//order.h 含有负责处理命令行的函数
#include "login.h"
//login.h 含有负责处理登陆的函数

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
void send(char *x,char *y,char *z){}
void h(char *x){}
void c(char *x){}
void _help(){}
void _exit(){}

char lockname[20];//锁定名
char myname[20];//用户名
int flag;//flag
int lock_status;//是否锁定

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
			case 10:return 0;
		}
	}
	return 0;
}
