void ln(){
	printf("\n");
}
void _help(){
	printf("\tsign <username> <password>\t登陆或注册");
	ln();
	printf("\tfriend\t\t\t\t列出你的所有好友及其id");
	ln();
	printf("\tlock <id>\t\t\t与该id好友建立对话");
	ln();
	printf("\tmsg <content>\t\t\t向当前好友发送信息");
	ln();
	printf("\t回车及其他内容\t\t\t刷新");
	ln();
	printf("\tsend <filename>\t\t\t向当前好友发送文件");
	ln();
	printf("\th\t\t\t\t显示与当前好友的聊天记录");
	ln();
	printf("\tc\t\t\t\t清空与当前好友的聊天记录");
	ln();
	printf("\thelp\t\t\t\t显示帮助");
	ln();
	printf("\texit\t\t\t\t退出程序但保存设置");
	ln();
	printf("\tlogout\t\t\t\t退出程序且删除所有本地配置");
	ln();
	return ;
}
