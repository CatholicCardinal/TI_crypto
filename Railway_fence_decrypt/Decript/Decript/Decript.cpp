#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

int length(char* sentence)
{
    int num = 0;

    for (int i = 0; sentence[i] != 0; i++)
    {
        num++;
        /* if (sentence[i]==' ')
         {
             num--;
         }*/
    }

    return num;
}

void decryption(int key, char* sentence)
{
    char result[100] = { 0 };
    char table[100][100] = { 0 };

    int x = 0, y = 0, n = 0, i = 0, len, period, k, j;

    len = length(sentence);
    
    for ( i = 0, n = 0; (2*i*(key-1)<=len); i++, n++)
    {
        table[0][2 * n * (key - 1)] = sentence[n];
    }
    
    int space1 = 2 * 1 * (key - 1) - 1, space2 = 1;
    if (space1>2)
    {
        space1 -= 2;
    }

    for ( k = 1, j = 1; k < key-1; i++,j++,space1-=2, space2+=2,k++)
    {
        int i = k;
        table[j][k] = sentence[n];
        n++;
        for (int step = 0, bol = 0; step  <= len; step++)
        {
            if (bol==0)
            {
                i += space1+1;
                if (i >= len)
                {
                    break;
                }
                table[j][i] = sentence[n];
                n++;
                bol = 1;
            }
            else
            {
                i += space2+1;
                if (i>=len)
                {
                    break;
                }
                table[j][i] = sentence[n];
                n++;
                bol = 0;
            }
            
        }
    }

    for ( i = 0 ;(2 * i * (key - 1) <= len); i++, n++)
    {
        table[j][k+(2 * i *(key - 1))] = sentence[n];
    }
    

    printf("\nYou result:Done");
    FILE* file = fopen("file.txt", "w");
    for (n = 0; n < len;)
    {
        for (period = 0; (period < key) && (n < len)& (table[y][x] != 0); period++, y++, x++, n++)
        {
            fprintf(file, "%c", table[y][x]);
        }

        for (period = key - 1, y -= 2; (period > 1) && (n < len) && (table[y][x] != 0); period--, y--, x++, n++)
        {
            fprintf(file, "%c", table[y][x]);
        }
    }
    fclose(file);
}



int main()
{
    int key;
    char sentence[100] = { 0 }, result[100] = { 0 };

    printf("Welcom to cryptography_program(railway fence)\n\n");
    printf("\nEnter sentence for decryption:");
    gets_s(sentence);

    printf("\nEnter you key:");
    scanf("%d", &key);

    decryption(key, sentence);

}
