void c(char *x){
	char cmd[100];
	sprintf(cmd,"rm -f %s.his",x);
	system(cmd);
}
