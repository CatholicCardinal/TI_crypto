#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

#define n 4

int length(char* sentence)
{
    int num = 0;

    for (int i = 0; sentence[i] != '0'; i++)
    {
        num++;
    }

    return num;
}



void encryption(char* sentence)
{
    char result[100] = { 0 };
    char table[4][4] = { 0 };

    int x = 0, y = 0, i = 0, k = 0, j = 0;

    table[0][0] = sentence[0];
    for (i=n-1,j=1,k++; j < n; i--,k++,j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        table[j][i] = sentence[k];
    }

    table[0][n-1] = sentence[k];
    for (i = 0, j = 1, k++; j < n; i++, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        table[j][i] = sentence[k];
    }

    table[n-1][n-1] = sentence[k];
    for (i = n-2, j =0 , k++; i>=0  ; i--, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        table[j][i] = sentence[k];
    }

    table[n - 1][0] = sentence[k];
    for (i = 1, j = 0, k++; i <n; i++, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        table[j][i] = sentence[k];
    }
    

    FILE* file = fopen("file.txt", "w");

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
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
    char sentence[100] = { 'h','e','l','l','o','w','o','r','d','a','b','c','d','e','f','g' };
    char* p;

    printf("Welcom to cryptography_program(railway fence)\n\n");
    //printf("\nEnter sentence for encryption:");
    //gets_s(sentence);

    //printf("\nEnter you key:");
    //gets_s(key);

    encryption(sentence);

}