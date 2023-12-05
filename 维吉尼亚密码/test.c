#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void vigenereEncrypt(char *plaintext, char *keyword);
void vigenereDecrypt(char *ciphertext, char *keyword);

int main() {
    char input[MAX_SIZE];
    char keyword[MAX_SIZE];

    printf("请输入明文或密文: ");
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("请输入关键字: ");
    fgets(keyword, MAX_SIZE, stdin);

    keyword[strcspn(keyword, "\n")] = '\0';

    printf("\n加密结果: ");
    vigenereEncrypt(input, keyword);

    printf("\n解密结果: ");
    vigenereDecrypt(input, keyword);

    return 0;
}

void vigenereEncrypt(char *plaintext, char *keyword) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keywordLen = strlen(keyword);

    for (i = 0, j = 0; i < plaintextLen; ++i) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int key = tolower(keyword[j % keywordLen]) - 'a';

            plaintext[i] = base + (plaintext[i] - base + key) % 26;

            ++j;
        }
    }

    printf("%s\n", plaintext);
}

void vigenereDecrypt(char *ciphertext, char *keyword) {
    int i, j;
    int ciphertextLen = strlen(ciphertext);
    int keywordLen = strlen(keyword);

    for (i = 0, j = 0; i < ciphertextLen; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            int key = tolower(keyword[j % keywordLen]) - 'a';

            ciphertext[i] = base + (ciphertext[i] - base - key + 26) % 26;

            ++j;
        }
    }

    printf("%s\n", ciphertext);
}
