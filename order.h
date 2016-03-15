//order函数的作用是，获取一个行串，返回该行串所包含的命令值。
struct order_class{
	int argv;
	char cmd[10];
	char option[10];
	char argc[2][10];
	char error[30];
};
void mm(char * x){
	memset(x,0,sizeof x);
}
struct order_class order(char *x){
	struct order_class result;

	while (x[0]==' '||x[0]=='\t') x++;

	int k;
	if (strstr(x," ")==NULL){
		if (strstr(x,"\t")==NULL)
			k=strstr(x,"\n")-x;
		else k=strstr(x,"\t")-x;

	}
	else {
		k=strstr(x," ")-x;
			
	//	if (k>strstr(x,"\t")-x) k=strstr(x,"\t")-x;



	}

	x[k]=0;
	strcpy(result.cmd,x);
	result.argv=5;
	if (!strcmp(x,"sign")) result.argv=0;
	if (!strcmp(x,"friend")) result.argv=1;
	if (!strcmp(x,"find")) result.argv=2;
	if (!strcmp(x,"lock")) result.argv=3;
	if (!strcmp(x,"msg")) result.argv=4;
	if (!strcmp(x,"send")) result.argv=6;
	if (!strcmp(x,"h")) result.argv=7;
	if (!strcmp(x,"c")) result.argv=8;
	if (!strcmp(x,"help")) result.argv=9;
	if (!strcmp(x,"exit")) result.argv=10;
	if (!strcmp(x,"logout")) result.argv=11;


	if (result.argv==0){
		x+=k+1;
		while (x[0]==' '||x[0]=='\t') x++;
		if (!strstr(x," ")){
			result.argv=-1;
			mm(result.error);
			strcat(result.error,"Username not found");
			return result;
		}
		if (strstr(x," ")==NULL){
			if (strstr(x,"\t")==NULL)
				k=strstr(x,"\n")-x;
			else k=strstr(x,"\t")-x;
		}
		else {
			k=strstr(x," ")-x;
	//		if (k>strstr(x,"\t")-x) k=strstr(x,"\t")-x;
		}

		x[k]=0;
		strcpy(result.argc[0],x);

		x+=k+1;
		while (x[0]==' '||x[0]=='\t') x++;
		k=strstr(x,"\n")-x;
		if (k==0){
			result.argv=-1;
			mm(result.error);
			strcat(result.error,"Password not found");
			return result;
		}
		x[k]=0;
		strcpy(result.argc[1],x);
	}

	if (result.argv==2||result.argv==3||result.argv==6||result.argv==4){
		x+=k+1;
		while (x[0]==' '||x[0]=='\t') x++;
		if (strstr(x,"\n")==NULL){
			memset(result.error,0,sizeof result.error);
			if (result.argv==2||result.argv==3) strcat(result.error,"Username not found");
			else if (result.argv==6) strcat(result.error,"Filename not found");
			else strcat(result.error,"Message not found");
			result.argv=-1;

			return result;
		}
		k=strstr(x,"\n")-x;
		if (k==0){
			memset(result.error,0,sizeof result.error);
			if (result.argv==2||result.argv==3) strcat(result.error,"Username not found");
			else if (result.argv==6) strcat(result.error,"Filename not found");
			else strcat(result.error,"Message not found");
			result.argv=-1;

			return result;
		}
		x[k]=0;
		strcpy(result.argc[1],x);
	}

	return result;
}
