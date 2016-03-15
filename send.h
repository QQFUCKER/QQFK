void send(char *username,char *lockname,char*filename){
	FILE *fpp=fopen(filename,"r");
	if (fpp==NULL){
		printf("error, not found \"%s\"\n",filename);
		return ;
	}
	else fclose(fpp);

	struct tm *timeinfo;
	time_t nowtime;
	time(&nowtime);
	timeinfo=localtime(&nowtime);
	int YEAR=timeinfo->tm_year+1900,MONTH=timeinfo->tm_mon+1,DAY=timeinfo->tm_mday,HOUR=timeinfo->tm_hour,MIN=timeinfo->tm_min,SEC=timeinfo->tm_sec;

	char goalname[100],cmd[100],upfilename[100];
	sprintf(goalname,"%s/%04d%02d%02d%02d%02d%02d/%s/%05d.link",lockname,YEAR,MONTH,DAY,HOUR,MIN,SEC,username,flag%100000);
	sprintf(upfilename,"%s/%04d%02d%02d%02d%02d%02d/%s/%05d/%s",lockname,YEAR,MONTH,DAY,HOUR,MIN,SEC,username,flag%100000,filename);
	FILE *fp=fopen("link.tmp","w");
	fprintf(fp,"%s",upfilename);
	fclose(fp);

	++flag;
	sprintf(cmd,"./qshell fput %s %s link.tmp",BK,goalname);
	system(cmd);
	sprintf(cmd,"./qshell fput %s %s %s",BK,upfilename,filename);
	system(cmd);
	system("rm -f link.tmp");
	return ;
}
