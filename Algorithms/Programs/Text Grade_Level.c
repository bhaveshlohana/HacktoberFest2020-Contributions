#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
    float letter_counter = 0;
    float word_counter = 1;
    float sentence_counter = 0;
    float grade_level;
    int grade_leveltwo;
    float tmp;
    string text = get_string("Text:");
    int characters = strlen(text);
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_counter += 1;
        }

        if (isspace(text[i]))
        {
            word_counter += 1;
        }

        if (text[i] == 46)
        {
            sentence_counter += 1;
        }

        if (text[i] == 33)
        {
            sentence_counter += 1;
        }
        if (text[i] == 63)
        {
            sentence_counter += 1;
        }
    }
    tmp = word_counter / 100;
    float L = letter_counter / tmp;
    float S = sentence_counter / tmp;
    grade_level = (0.0588 * L - 0.296 * S - 15.8);

    grade_leveltwo = roundf(grade_level);

    if (grade_leveltwo > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_leveltwo < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_leveltwo);
    }
}
