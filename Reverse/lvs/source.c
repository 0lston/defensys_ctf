#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int keys[36] = { 11, 23, 87, 93, 35, 98,
             36, 84, 66, 78, 21, 34,
             97, 92, 69, 45, 43, 64,
             29, 15, 14, 26, 23, 38,
             94, 80, 64, 44, 66, 68,
             87, 67, 21, 78, 14, 10 };
void die(char *msg){
	puts(msg);
	exit(-1);
}
int flag[21] = {4, 88, 73, 75, 84, 68, 127, 13, 43, 113, 90, 118, 40, 62, 39, 85, 34, 111, 109, 42, 106}; 
int fail(char *svtr, int TNTL){
	puts("checking failed!");
	int s,l,e;s = 18-1;l = TNTL-1,e = 36;
	int ok=1;
	for(int i = 0;i != l;i++){
		//s = (s == 35) ? 0 : s++;
		// printf("[l=%d] checking %d if is %d xored by %d : [%d ^ %d]\n", i, (int)svtr[i], (flag[i]^keys[s]), keys[s], flag[i], keys[s]);
		if((int)svtr[i] == (flag[i]^keys[s])) ok;
		else break;	
		//s = (s == 35) ? 0 : s++;
		if(s == 35) s = 0;
		else s++;
	}	

	return 6;
}


int main(int c, char *a[]){
	if(c < 2) die("hahaha la");

	size_t len = strlen(a[1]);
	if(len != 1234) die("hahaha la");

	char *pass = &a[1][1000];
	a[1][1021] = '\0';

	printf("pass : %s, len = %d\n", pass, strlen(pass));
	if(fail(pass, strlen(pass))) die("hahaha la");
	else die("hahaha la");

	return;
}
