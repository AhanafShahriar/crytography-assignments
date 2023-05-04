#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_key(char *key, int length) {
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *message, char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        message[i] = (message[i] + key[i]) % 256;
    }
}

void decrypt(char *message, char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        message[i] = (message[i] - key[i] + 256) % 256;
    }
}

int main() {
    char message[1000], key[1000];
    int length, i;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    length = strlen(message) - 1;
    message[length] = '\0';

    generate_key(key, length);

    printf("Message:     %s\n", message);
    printf("Key:         ");
    for (i = 0; i < length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    encrypt(message, key, length);
    printf("Ciphertext:  ");
    for (i = 0; i < length; i++) {
        printf("%d ", message[i]);
    }
    printf("\n");

    decrypt(message, key, length);
    printf("Plaintext:   %s\n", message);

    return 0;
}
