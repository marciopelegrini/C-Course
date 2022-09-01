#include <stdio.h>

int main() {
    char nome[50];
    printf("Digite seu nome: ");
    gets(nome);

    printf("Hello, %s\n", nome);
    return 0;
}
