#include <stdio.h>

int main() {
    // Given flag
    char flag[] = "DEFENSYS{r3v_7_mas73r}";

    // Perform equations
    int result1 = flag[18] * flag[7] & flag[12] ^ flag[2];
    int result2 = flag[1] % flag[14] - flag[21] % flag[15];             
    int result3 = flag[10] + flag[4] * flag[11] - flag[20];          
    int result4 = flag[19] + flag[12] * flag[0] ^ flag[16];             
    int result5 = flag[9] ^ flag[13] * flag[8] & flag[16];              
    int result6 = flag[3] * flag[17] + flag[5] + flag[6];                 
    int result7 = flag[21] * flag[2] ^ flag[3] ^ flag[19];  
    int result8 = flag[11] ^ flag[20] * flag[1] + flag[6];
    int result9 = flag[7] + flag[5] - flag[18] & flag[9];
    int result10 = flag[12] * flag[8] - flag[10] + flag[4];
    int result11 = flag[16] ^ flag[17] * flag[13] + flag[14];
    int result12 = flag[0] * flag[15] + flag[3];
    int result13 = flag[13] + flag[18] * flag[2] & flag[5] ^ flag[10];
    int result14 = flag[0] % flag[12] - flag[19] % flag[7];
    int result15 = flag[14] + flag[21] * flag[16] - flag[8];
    int result16 = flag[3] + flag[17] * flag[9] ^ flag[11];
    int result17 = flag[15] ^ flag[4] * flag[20] & flag[1];
    int result18 = flag[6] * flag[12] + flag[19] + flag[2];
    int result19 = flag[7] * flag[5] ^ flag[10] ^ flag[0];
    int result20 = flag[21] ^ flag[13] * flag[15] + flag[11];
    int result21 = flag[16] + flag[20] - flag[3] & flag[9];
    int result22 = flag[18] * flag[1] - flag[4] + flag[14];
    int result23 = flag[8] ^ flag[6] * flag[17] + flag[12];
    int result24 = flag[11] * flag[2] + flag[15];


    // Print equations and results
    printf("Result 1 = %d\n", result1);
    printf("Result 2 = %d\n", result2);
    printf("Result 3 = %d\n", result3);
    printf("Result 4 = %d\n", result4);
    printf("Result 5 = %d\n", result5);
    printf("Result 6 = %d\n", result6);
    printf("Result 7 = %d\n", result7);
    printf("Result 8 = %d\n", result8);
    printf("Result 9 = %d\n", result9);
    printf("Result 10 = %d\n", result10);
    printf("Result 11 = %d\n", result11);
    printf("Result 12 = %d\n", result12);
    printf("Result 13 = %d\n", result13);
    printf("Result 14 = %d\n", result14);
    printf("Result 15 = %d\n", result15);
    printf("Result 16 = %d\n", result16);
    printf("Result 17 = %d\n", result17);
    printf("Result 18 = %d\n", result18);
    printf("Result 19 = %d\n", result19);
    printf("Result 20 = %d\n", result20);
    printf("Result 21 = %d\n", result21);
    printf("Result 22 = %d\n", result22);
    printf("Result 23 = %d\n", result23);
    printf("Result 24 = %d\n", result24);

    return 0;
}
