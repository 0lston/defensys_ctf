#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void halt(char *msg) {puts(msg);exit(0);}
int global_KEY = 43219001;

/*
 * complete the flag as single var 
 * test flag : flag{0deadbeef0}
 * */

int c5,c6,c7,c8,c9,c10;
void setup(int m){
	if(m != 0) return;
	c7 = 43219029;
	c10 = 43218950;
	c9 = 43219038;
}

c6 = 43219039;
c5 = 43219037;
void not_valid_flag(){
	puts("invalid flag ¯\\_(ツ)_/¯");
	exit(12907535);
}
void dont_verify_the_input(char *input, int c1, int c2, int c3, int c4){
	printf("hmmm %s?\n", input);
	int v=0;
	for(int i=0;;i++) {
		if(i > strlen(input)) halt("its a valid flag!");
		if(v==10) break;
		if( (input[i] == '{') ||
		    (input[i] == 'D') ||
		    (input[i] == 'S') ||
		    (input[i] == 'E') ||
     		    (input[i] == 'F') ||
		    (input[i] == '}') ||
		    (input[i] == 'Y') ||
		    (input[i] == 'N') ) { v++; } 		    
	}


	int b=10-2;
	int k = global_KEY;

	if((input[b+3] == (c3 ^ k)) &&
	   (input[b+5] == (c5 ^ k)) &&
	   (input[b+4] == (c4 ^ k)) &&
	   (input[b+1] == (c1 ^ k)) &&
	   (input[b+9] == (c9 ^ k)) &&
	   (input[b+10] == (c10 ^ k)) &&
	   (input[b+2] == (c2 ^ k)) &&
	   (input[b+6] == (c6 ^ k)) &&
	   (input[b+8] == (c8 ^ k)) &&
	   (input[b+7] == (c7 ^ k))) { not_valid_flag(); }
	else halt("perfect flag!");
}

int main(int c, char *a[]){
	setup(1);
	int c1,c2,c3,c4;
	c3 = 43219036;
	c1 = 43218953;
	c8 = 43218957;
	setup(0);
	c4 = 43218957;
	c2 = 43219037;
	setup(17);
	dont_verify_the_input(a[1], c1, c2, c3, c4);
}
