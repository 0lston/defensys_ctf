#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char flag[50];

    // Get flag input from user
    printf("Enter the flag: ");
    fgets(flag, sizeof(flag), stdin);
    flag[strcspn(flag, "\n")] = '\0'; // Remove newline character

    if (strlen(flag) != 22) {
        printf("Flag length is not correct.\n");
        return 0;
    }

    // Check conditions
    if (flag[18] * flag[7] & flag[12] ^ flag[2] == 19 &&
        flag[1] % flag[14] - flag[21] % flag[15] == 53 &&
        flag[10] + flag[4] * flag[11] - flag[20] == 9141 &&
        flag[19] + flag[12] * flag[0] ^ flag[16] == 6414 &&
        flag[9] ^ flag[13] * flag[8] & flag[16] == 19 &&
        flag[3] * flag[17] + flag[5] + flag[6] == 8107&&
        flag[21] * flag[2] ^ flag[3] ^ flag[19] == 8792 &&
        flag[11] ^ flag[20] * flag[1] + flag[6] == 8037 &&
        flag[7] + flag[5] - flag[18] ^ flag[9] == 29 &&
        flag[12] * flag[8] - flag[10] + flag[4] == 11712 &&
        flag[16] ^ flag[17] * flag[13] + flag[14] == 6517 &&
        flag[0] * flag[15] + flag[3] == 7481 &&
        flag[13] + flag[18] * flag[2] & flag[5] ^ flag[10] == 114 &&
        flag[0] % flag[12] - flag[19] % flag[7] == 17 &&
        flag[14] + flag[21] * flag[16] - flag[8] == 12097 &&
        flag[3] + flag[17] * flag[9] ^ flag[11] == 13069 &&
        flag[15] ^ flag[4] * flag[20] & flag[1] == 105 &&
        flag[6] * flag[12] + flag[19] + flag[2] == 8576 &&
        flag[7] * flag[5] ^ flag[10] ^ flag[0] == 6814 &&
        flag[21] ^ flag[13] * flag[15] + flag[11] == 6044 &&
        flag[16] + flag[20] - flag[3] ^ flag[9] == 252 &&
        flag[18] * flag[1] - flag[4] + flag[14] == 3812 &&
        flag[8] ^ flag[6] * flag[17] + flag[12] == 10273 &&
        flag[11] * flag[2] + flag[15] == 8369) {
        printf("Congratulations! Your flag is correct.\n");
    } else {
        printf("Sorry, your flag is incorrect.\n");
    }

    return 0;
}