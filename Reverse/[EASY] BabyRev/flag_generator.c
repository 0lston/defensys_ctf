#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(int a, int index) {
    // performs "random" encryption
    return (a + 96) ^ index;
}

int main(void) {
    char user_input[128];
    char* flag = "DEFENSYS{tw0_0p3r2t10ns_15_s1mple_t0_r3v3rs3}";
    int flag_len = strlen(flag);

    for (int i = 0; i < flag_len; i++) {
        printf("%d, ", encrypt(flag[i], i));
    }

    return 0;
}