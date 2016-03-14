int login(char * x){
	FILE *fp=fopen(".location.conf","r");
	if (fp==NULL) return 0;
	else {
		fscanf(fp,"%s",x);
		return 1;
		fclose(fp);
	}
}
