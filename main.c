//Name: Ben Alaluf   ID: 314231762
//Ex1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//We will set the maximum amount of the sentence
//And we will create two functions for the benefit of the program
#define LEN 510

void howManyWords(char *);

void howManyLetters(char *);

//In Main we receive the input and send the input to our two functions, if the user chooses to exit the program in Main this is done.
int main() {
    char words[LEN];
    printf("============ Welcome to the program ============\n");
    while (1) {
        printf("Please enter the sentences:\n");
        fgets(words, LEN, stdin);
        if (strcmp(words, "exit\n") == 0) {
            return 0;
        }
        howManyWords(words);
        howManyLetters(words);
    }

}

//Receive the input and run it as follows:
//Count the letters in a sentence until you reach a space or there is no continuation so we can know when the word ends, and so we will keep the number of words.
void howManyWords(char *sentences) {
    int i;
    int counterOfWords = 0;
    int counterOfLetters = 0;
    for (i = 0; i < strlen(sentences); i++) {
        if (sentences[i] != '\n' && sentences[i] != '\0' && sentences[i] != ' ') {
            counterOfLetters++;
        }
        if (sentences[i] == ' ' || sentences[i] == '\n') {
            if (counterOfLetters > 0) {
                counterOfWords++;
                counterOfLetters = 0;
            }
        }
    }
    printf("%d words\n", counterOfWords);
}
//Receive the input and turn it on as follows:
//We will count the letters to the space and if we have reached the space we will know that the word is over and a new word starts, we will save the word and check that it is really saved and then we will send it for printing and so it will be done until the end of the sentence

void howManyLetters(char *sentences) {
    int i;
    int counterOfLetters = 0;
    char *data;
    for (i = 0; i < strlen(sentences); i++) {
        if (sentences[i] != '\n' && sentences[i] != '\0' && sentences[i] != ' ') {
            counterOfLetters++;
        }
        if (sentences[i] == ' ' || sentences[i] == '\n') {
            if (counterOfLetters > 0) {
                data = (char *) malloc(counterOfLetters * sizeof(char));
                if (data == NULL) {
                    printf("Error!!\nType of problem: Allocation of memory");
                    exit(1);
                }
                strncpy(data, &sentences[i - counterOfLetters], counterOfLetters);
                printf("%s:%d\n", data, counterOfLetters);
                data = NULL;
                free(data);
                counterOfLetters = 0;
            }
        }
    }
}