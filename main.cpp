#include<stdio.h>
#include<string.h>
#include<stdlib.h>

///本地存放一个名为location.conf 来记录当前用户，处理初始化，以及自动登录等事情。（可以进行简单的加法加密）

struct T ///结构体形参接口，如果需要传别的可适当添加形参。。。为了明了就不用全局变量处理了
{
    int forlong[20];///为了稳定。记录本结构体中数组长度，此时0为username长度，1为sockedname长度
    char username[50];///当前在登录的用户
    char sockedname[50];///当前锁定朋友
    int flag;///1-99999之间的整数
};

int fororderx(char order[10],int len)///！！！！创举！！将命令哈希成一个int。这样下面处理命令的时候直接可以swich。哈希方式是26进制法，所以只要
{                                    ///命令不一样，哪怕差一个字母或者多少一个，这个int都不一样。，，这样以来命令处理变得十分方便
    int sk=1;
    int ans=0;
    for(int i=0; i<len; i++)
    {
        ans+=(order[i]-'a')*sk;
        sk*=26;
    }
    return ans;
}

int main(int argc,char **argv)
{
    T key;
    key=forlogin();///用于处理登录，本来有本地则直接登录，交还进程。否则提示登录，成功后交还进程。(初始化key)
    char order[10];
    wait_for_order(key);///输出等待命令提示。根据key的情况输出不同情况。
    while(scanf("%s",order)!=EOF)
    {
        int orderx=fororderx(order,strlen(order));
        ///接下来直接根据不同orderx调用不同函数就行了。



        wait_for_order(key);
    }



    return 0;
}
