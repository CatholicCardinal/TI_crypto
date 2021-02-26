#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

int length(char* sentence)
{
    int num = 0;

    for (int i = 0; sentence[i] != '0'; i++)
    {
        num++;
    }

    return num;
}

void encryption(char* key, char* sentence)
{
    char result[100] = { 0 };
    char table[100][100] = { 0 };
    int line[100] = { -1 };
    int x = 0, y = 0, n = 0, len, period, len_sentence;

    len = length(key);
    for (int i = 0, j = 0; i < len; i++, j++)
    {
        table[0][j] = key[i];
    }

    for (int i = 0; i < len; i++)
    {
        line[i] = int(table[0][i]);
    }

    len_sentence = length(sentence);
    for (int j = 1, k = 0; j < 100; j++)
    {
        if (k >= len_sentence)
        {
            break;
        }
        for (int i = 0; i < len; i++, k++)
        {
            if (k >= len_sentence)
            {
                break;
            }
            if (sentence[k] == ' ')
            {
                k++;
            }
            table[j][i] = sentence[k];

        }
    }


    for (int i, max, maxnum, j = 0, st = 0; j < len; j++)
    {
        for (i = 0, max = 200, maxnum = 0; (i < len); i++)
        {
            if ((max > line[i]) && (line[i] != 0))
            {
                max = line[i];
                maxnum = i;
            }
        }
        line[maxnum] = 0;
        for (int j1 = 1; (j1 < 100) && (table[j1][maxnum] != 0); j1++, st++)
        {
            table[j1][maxnum] = sentence[st];
        }
    }

    FILE* file = fopen("file.txt", "w");

    for (int j = 1; j < 100; j++)
    {
        for (int i = 0; i < 100; i++)
        {
            if (table[j][i] != 0)
            {
                fprintf(file, "%c", table[j][i]);

            }
        }
    }

    fclose(file);
    printf("\nYou result:Done");
}



int main()
{
    char key[100] = { 'w','e','l','l','c','o','m','e','0' };
    char sentence[100] = { 'y','e','o','o','r','g','h','d','d','a','w','s','t','i','a','t','o','e','0' };
    char* p;

    printf("Welcom to cryptography_program(railway fence)\n\n");
    //printf("\nEnter sentence for encryption:");
    //gets_s(sentence);

    //printf("\nEnter you key:");
    //gets_s(key);

    encryption(key, sentence);

}