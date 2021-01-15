#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    unsigned int len = 255;
    char text[len];
    char mostUsed[len];
    char words[100][len];
    char bufer[100][len];
    char chart[100][len];

    int one, two, three;

    int count = 0;
    int temp = 0;
    int wordsNum = 1;
    int spaceNum = 1;
    int SpaceCount = -1;
    int signsSymbols = 0;


    printf("Enter the string\n");
    scanf(" %[^\n]s", text);
   
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == ' ')||(text[i] == ',' && text[i+1] == ' ')||(text[i] == '.'))
        {
            spaceNum++;
            SpaceCount++;
        }
        if (text[i] >= '0' && text[i] <= '9')
        {
            signsSymbols++;
            printf("%c .", text[i]);
        }
        
        
        
    }
    for ( one = 0, two = 0, three = 0; two < strlen(text); two++){
        if ((text[two] == ' ')||(text[two] == ',')||(text[two] == '.'))  
        {    
            words[one][three] = '\0';
            one++;
            three = 0;
        }
        else
        {
         words[one][three++] = text[two];   
        }
    }
    three = 0;

    for (one = 0;one <= spaceNum; one++)
    {
        for (two = 0;two <= spaceNum; two++)
        {
            if (one == two)
            {
                strcpy(bufer[three], words[one]);
                three++;
                wordsNum++;
 
                break;
            }
            else
            {
                if (strcmp(bufer[two], words[one]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    /**/
    for (one = 0 ; one < wordsNum; one++) 
    {
        for (two = 0;two <= spaceNum; two++)
        {
            if (strcmp(bufer[one], words[two]) == 0)
                count++;
            
        }
        if (count > temp)
        {
            temp = count;
            strcpy(mostUsed, bufer[one]);
            
            
            
        }
        count = 0;

    }

    //uslovie 2
    printf("\n number of words = %d\n", wordsNum);

    if (temp > 1)
    {
    printf(" most common word = %s => %d times\n", mostUsed, temp);
    }
    //uslovie 3
    printf(" total number of characters = %ld \n", strlen(text) - SpaceCount);
    printf(" number of letters = %ld \n", strlen(text) - (SpaceCount + signsSymbols));
    printf(" empty spaces = %d \n", SpaceCount);
    printf(" signs and symbols = %d\n", signsSymbols);
}
