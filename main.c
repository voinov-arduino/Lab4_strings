#include <stdio.h>
#include <string.h>

int hasSymmetricPair(char *word) {
    int length = strlen(word);
    
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - i - 1]) {
            return 0;
        }
    }

    return 1; 
}

void processString(char *input) {
    int length = strlen(input);
    int currentIndex = 0;

    for (int i = 0; i < length; ++i) {
        while (i < length && input[i] == ' ') {
            ++i;
        }

        while (i < length && input[i] != ' ') {
            input[currentIndex++] = input[i++];
        }

        if (i < length) {
            input[currentIndex++] = ' ';
        }
    }

    input[currentIndex] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL) {
        if (hasSymmetricPair(token)) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    printf("Result: ");
    processString(input);

    return 0;
}
