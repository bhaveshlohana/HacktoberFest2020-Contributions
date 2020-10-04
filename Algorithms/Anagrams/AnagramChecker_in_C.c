#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char first_word[500];
    char second_word[500];
    int wd1;
    int wd2;
    printf ("Enter the first word here\n");
    scanf ("%s", first_word);

    printf ("Enter the second word here\n");
    scanf ("%s", second_word);

    wd1 = strlen (first_word);
    wd2 = strlen (second_word);

    if (wd1 != wd2){
        printf ("%s and %s is not an Anagram", first_word, second_word);
    }
    else {
        printf ("%s and %s is an Anagram", first_word, second_word);
    }
}
