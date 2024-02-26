#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

int main() {
  init();
  char code[1024];
  printf("Enter shellcode: ");
  fgets(code, sizeof(code), stdin);
  void (*shellcode)() = (void (*)())code;
  shellcode();
  return 0;
}