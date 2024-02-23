#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(int a, int index) {
    // performs "random" encryption
    return (a + 96) ^ index;
}

int main(void) {
    char userInput[128];
    printf("Hello! Welcome to DEFENSYS. Please enter the flag.\n");
    int encryptedFlag[] = {164, 164, 164, 166, 170, 182, 191, 180, 211, 221, 221, 155, 179, 157, 222, 156, 194, 131, 198, 130, 132, 219, 197, 168, 137, 140, 165, 200, 141, 208, 206, 211, 229, 158, 246, 179, 155, 247, 181, 241, 187, 251, 249, 184, 241};
    size_t encryptedFlag_size = sizeof(encryptedFlag) / sizeof(int);
    
    fgets(userInput, 128, stdin);
    if (strlen(userInput) - 1 != encryptedFlag_size) {
        printf("Flag wrong. Try again.");
        return 1;
    } else {
        printf("Good Job! Your flag is the correct size.\n");
        printf("let's now proceed to the flag check itself...\n");
        for (int j = 0; j < strlen(userInput) - 1; j++) {
            char user_char, test_char;
            test_char = encryptedFlag[j];
            user_char = encrypt(userInput[j], j);

            if (user_char != test_char) {
                printf("Flag check failed at index: %d", j);
                return 1;
            }
        }

        printf("Success! Go Submit the flag!!!\n");
    }

    return 0;
}