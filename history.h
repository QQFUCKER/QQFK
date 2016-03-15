void h(char *x){
	char cmd[50],filename[50];
	sprintf(cmd,"cat -n %s.his",x);
	sprintf(filename,"%s.his",x);
	FILE *fp=fopen(filename,"r");
	if (fp==NULL) {
		printf("No history found\n");
		return ;
	}
	fclose(fp);
	system(cmd);
}
