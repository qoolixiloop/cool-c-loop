#include <stdio.h>

void reverse(char word[], char reverseString[]) {
    int i;
    int wordLength;

    wordLength = 0;    
    while(word[wordLength] != '\0')
        wordLength++;
    for (i = 0; word[i] != '\0'; i++)
        reverseString[wordLength - i - 1] = word[i];
    reverseString[wordLength] = '\0';
}

void main() {
    int maxstrlen = 100;
    char strA[maxstrlen];
    char reverseString[maxstrlen];

    printf("Type a string: ");
    scanf("%[^\n]s", strA);

    reverse(strA, reverseString);
    printf("Reverse string: %s\n", reverseString);
}

// Linux, Mac: gcc task1.c -o task1; ./task1
// Windows: gcc task1.c -o task1; task1
