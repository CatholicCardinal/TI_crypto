// Railway fence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

int length(char* sentence)
{
    int num = 0;

    for (int i = 0; sentence[i] != 0 ; i++)
    {
        num++;
       /* if (sentence[i]==' ')
        {
            num--;
        }*/
    }
    
    return num;
}

void encryption(int key, char* sentence)
{
    char result[100] = { 0 };
    char table[100][100] = { 0 };

    int x = 0, y = 0, n = 0, len, period;

    len = length(sentence);
    for ( n = 0; n < len;)
    {
        for ( period = 0; (period < key)&&(n < len); period++, y++, x++, n++)
        {
            if (sentence[n] == ' ')
            {
                n++;
            }
            table[y][x] = sentence[n];
        }

        for (period = key-1, y-=2; (period > 1) && (n < len); period--, y--, x++, n++)
        {
            if (sentence[n] == ' ')
            {
                n++;
            }
            table[y][x] = sentence[n];
        }
    }
  
    printf("\nYou result:");
    FILE* file = fopen("file.txt", "w");

    for (int j = 0; j < 100; j++)
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
}



int main()
{
    int key;
    char sentence[100] = { 0 }, result[100] = { 0 };
    char* p;

    printf("Welcom to cryptography_program(railway fence)\n\n");
    printf("\nEnter sentence for encryption:");
    gets_s(sentence);

    printf("\nEnter you key:");
    scanf("%d", &key);
    
    encryption(key, sentence);

}
