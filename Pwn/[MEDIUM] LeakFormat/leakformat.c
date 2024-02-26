#include <stdio.h>
#include <string.h>

void init()
{
    setvbuf(stdout,0,2,0);
    setvbuf(stdin,0,2,0);
    setvbuf(stderr,0,2,0);
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main(int argc, char *argv[]){
  init();
  char *secret = "DEFENSYS{leak_thr0ugh_f0rm2t_5tr1ng_vuln3rab1l11ty}";
  char input[128];

  while(1) {
    puts("try to leak the flag if you can : ");
    fgets(input, sizeof(input), stdin);
    printf("Result : ");
    printf(input);
  }
}