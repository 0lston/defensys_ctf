#include <stdio.h>
#include <string.h>

void init()
{
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    setvbuf(stderr,0,2,0);
}

void victory() {
    system("cat flag.txt");
}

void vuln() {
    char buffer[64];

    puts("this time i've added a stack protector you ain't getting victory this time :");
    gets(buffer);
    printf(buffer);

    puts("\nGood luck with your BOF attack :");
    gets(buffer);
}

int main() {
	init();
    vuln();
}