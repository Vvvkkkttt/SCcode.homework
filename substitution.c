#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_valid_key(string key);
char substitute_char(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        printf("%c", substitute_char(c, key));
    }
    printf("\n");

    return 0;
}
bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}
char substitute_char(char c, string key)
{
    if (isalpha(c))
    {
        bool is_upper = isupper(c);
        int index = tolower(c) - 'a';
        char substitution = key[index];
        return is_upper ? toupper(substitution) : tolower(substitution);
    }
    return c;
}
