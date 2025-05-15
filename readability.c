#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);


    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

 
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }

    return 0;
}


int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_words(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]) || text[i + 1] == '\0')
        {
            count++;
        }
    }
    return count;
}


int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
