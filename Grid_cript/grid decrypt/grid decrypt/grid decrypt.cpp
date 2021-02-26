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
    char result[16] = { 0 };
    char table[4][4] = { 0 };

    int x = 0, y = 0, i = 0, k = 0, j = 0;

    for (int j1 = 0, k1=0; j1 < n; j1++)
    {
        for (int i1 = 0; i1 < n; i1++,k1++)
        {
            table[j1][i1] = sentence[k1];
        }
    }

 //   table[0][0] = sentence[0];
    result[0] = table[0][0];
    for (i = n - 1, j = 1, k++; j < n; i--, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        result[k]= table[j][i];
    }

  //  table[0][n - 1] = sentence[k];
    result[k] = table[0][n-1];
    for (i = 0, j = 1, k++; j < n; i++, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        result[k] = table[j][i];
    }

    result[k] = table[n-1][n-1];
    //table[n - 1][n - 1] = sentence[k];
    for (i = n - 2, j = 0, k++; i >= 0; i--, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        result[k] = table[j][i];
    }

    //table[n - 1][0] = sentence[k];
    result[k] = table[n-1][0];
    for (i = 1, j = 0, k++; i < n; i++, k++, j++)
    {
        if (sentence[k] == ' ')
        {
            k++;
        }
        result[k]= table[j][i];
    }


    FILE* file = fopen("file.txt", "w");


    for (int i = 0; i < n*n; i++)
    {
        if (result[i] != 0)
        {
            fprintf(file, "%c", result[i]);
        }
    }
    

    fclose(file);
    printf("\nYou result:Done");
}



int main()
{
    char sentence[100] = { 'h','e','a','o','w','b','f','e','c','o','l','g','d','l','r','d' };
    char* p;

    printf("Welcom to cryptography_program(railway fence)\n\n");
    //printf("\nEnter sentence for encryption:");
    //gets_s(sentence);

    //printf("\nEnter you key:");
    //gets_s(key);

    encryption(sentence);

}
