#include <stdio.h>
#include <string.h>

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
    vuln();
}