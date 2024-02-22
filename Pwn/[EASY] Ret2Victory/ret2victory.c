#include<stdio.h>

void init()
{
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    setvbuf(stderr,0,2,0);
}

void victory()
{
	system("cat flag.txt");
}


int main()
{
	char buf[10];
	init();
	printf("Can u return to victory?\n");
	gets(buf);

	return 0;
}
