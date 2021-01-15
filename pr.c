#include <stdio.h>
#include <string.h>
 
#define LEN 255
#define TRUE 1
#define FALSE 0

int percentage(int _a, int _b){
    return _a * (100/_b);
}

int getWords(char *_base, char _target[20][15])
{
	int n=0,j=0;
	
	for(int i=0;TRUE;i++)
	{
		if(_base[i]!=' '){
			_target[n][j++]=_base[i];
		}
		else{
			_target[n][j++]='\0';
			n++;
			j=0;
		}
		if(_base[i]=='\0')
		    break;
	}
	return n + 1;
	
}

int mostUsedWord( char _target[20][15], int _count, char _word[15]){
    int n = 0;
    int temp = 0;
    char arr[20][15];

    //TODO da premahna vtoriq arrei
    for (int x=0 ; x < 20; x++)
    {
        for (int y=0 ; y < 15; y++)
        {
            arr[x][y] = _target[x][y];
        }
    }

    for (int i = 0; i < _count; i++)
    {
        for (int j = 0; j < _count; j++)
        {
            if (strcmp(_target[i], arr[j]) == 0)
            {
                temp++;
            }
        }
        if (temp > n)
        {
            n = temp;
            strcpy(_word, _target[i]);
        }
        temp = 0;
    }
    return n;
}

int newArr(char _target[20][15], char _b[20][15],char _word[15], int _size){
    char tempWord[15];
    int procenti[5];

    int temp = 0;
    int n = 0;

    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < strlen(_target[i]); j++)
        {
            if(strcmp(_target[i], _word) != 0)
            {
                _b[i][j] = _target[i][j];
            } 
        }
    }
    n = mostUsedWord(_b,_size -1,tempWord);

    
    return percentage(n, _size - 1);
}

int spliter(char _buffer[20][15], int _size){
    char temp[20][15];
    char arr[20][15];
    char tempword[] = "error";

    int one[20];
    int bool = 0;
    for (int i = 0; i < _size; i++)
    {
        one[i] = 0;
    }
    

    for (int x=0 ; x < 20; x++)
    {
        for (int y=0 ; y < 15; y++)
        {
            arr[x][y] = _buffer[x][y];
        }
    }

    for (int i = 0; i < _size; i++)
    {   
        for (int j = 0; j < _size; j++)
        {
            if ((strcmp(arr[i], _buffer[j]) == 0) && (strcmp(arr[i], tempword) != 0))
            {
                strcpy(temp[i], arr[i]);
                for (int t = 0; t < _size; t++)
                {
                    if (strcmp(arr[t], temp[i]) == 0)
                    {
                        strcpy(arr[t], tempword);
                    }
                    
                }
                
            }
         
        }
        
    }

    for (int i=0 ; i < 20; i++)
    {
        for (int j=0 ; j < 15; j++)
        {
            if (strcmp(temp[i], _buffer[j]));
            {
                one[i]++;
            }
            
        }
    }

    for (int i = 0; i <= _size; i++)
    {
        printf("%d\n", one[i]);
    }
}
int test(char _target[20][15], int _count, char _word[15]){
    int n = 0;
    int temp = 0;
    char arr[20][15];

    //TODO da premahna vtoriq arrei
    for (int x=0 ; x < 20; x++)
    {
        for (int y=0 ; y < 15; y++)
        {
            arr[x][y] = _target[x][y];
        }
    }

    for (int i = 0; i < _count; i++)
    {
        for (int j = 0; j < _count; j++)
        {
            if (strcmp(_target[i], arr[j]) == 0)
            {
                temp++;
            }
        }
        if (temp > n)
        {
            n = temp;
            strcpy(_word, _target[i]);
        }
        temp = 0;
    }
    return n;
}

int chart(int _one, int _two, int _three, int _four){

    int check = _one / 10;

    printf("%d  %d  %d  %d\n", _one, _two, _three, _four);
    for (int i = 0; i < check; i++)
    {
	    if (_one >= 0)
        {
            printf("|   ");
        }
        if (_two >= 0)
        {
            printf("|   ");
        }        
        if (_three >= 0)
        {
            printf("|   ");
        }
        if (_four >= 0)
        {
            printf("|   ");
        }
            
            
        
        printf("\n");
        _one = _one -10;
        _two = _two -10;
        _three = _three -10;
        _four = _four -10;
    }
    
	
	return 0;
}

int main()
{   
    char str[LEN];
    char word[15];
    char buffer[20][15];
    char sec[20][15];
    int percents[5];

    int t = 0;
    int symbols = 0;
    int space = 0;
    int signs = 0;
    int num = 0;
    int wordNum = 0;
    int mostUsed = 0;

    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;

    printf("Enter the string\n");
    scanf(" %[^\n]s", str);


    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            space++;
        }else
        {
            symbols++;
        }
        
        if(str[i] >= 33 && str[i] <= 64)
        {
            signs++;
        }
        else if (str[i] >= 91 && str[i] <= 96)
        {
            signs++;
        }
        else if (str[i] >= 123 && str[i] <= 126)
        {
            signs++;
        }
        
        if (str[i] >= 48 && str[i] <= 57)
        {
            num++;
        }
    }
    wordNum = getWords(str, buffer);
    mostUsed = mostUsedWord(buffer, wordNum, word);
    
    
    one = percentage(mostUsed, wordNum);
    two = newArr(buffer,sec , word, wordNum);
    //three = newArr(sec,,);
    //uslovie 1
    chart(one, two, 4, 5);
     
    
    
    
    //uslovie 2
    printf("\n number of words = %d\n", wordNum);
    if (mostUsed > 1)
    {
        printf(" most common word = %s => %d times\n", word, mostUsed);
    }
    //uslovie 3
    printf(" total number of characters = %d \n", symbols);
    printf(" number of letters = %d \n", symbols - (space + signs));
    printf(" empty spaces = %d \n", space);
    printf(" signs and symbols = %d\n", signs - num);
    printf(" numbers = %d\n", num);


    //printf("%d  \n", percentage(mostUsed, wordNum));
    //printf("%d  \n", newArr(buffer, sec, word, wordNum));
    //printf("%ls", newArr(buffer, word, wordNum));

    spliter(buffer, wordNum);
    /*
    for (int i = 0; i <= wordNum; i++)
    {
        printf("%s\n", buffer[i]);
    }
    */
    return 0;
}