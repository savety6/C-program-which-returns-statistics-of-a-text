#include <stdio.h>
#include <string.h>

#define TRUE 1


float percentage(int _a, int _b){
    return _a * (100/_b);
}

int getWords(char *_base, char _target[50][15])
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

void chart(char _target[1000]){
    
	int cnt[1000]={0}; 
    int freq[1000]={0};
	int dup[1000]={0};
	int i=0,j=0,t=0;
    int len = 0, chek = 0, temp = 0, temp2 = 0;
	
	
	float perc[1000]={0};
	//
	while(TRUE)
	{
		if(_target[i]==' ' || _target[i]=='\0')
		{
			if(_target[i]=='\0')
			{
				if(len>0)
				{
					cnt[j++]=len;
					len=0;
				}
				break;
			}
			cnt[j++]=len;
			len=0;
		}
		else
		{
			len++;
		}		
		i++;
	}
	for ( i = 0; i < j; i++)
	{
		dup[i] = cnt[i];
	}
	
    for ( i = 0; i < j; i++)
    {
        for ( t = i + 1; t < j; t++)
        {
             if (cnt[i] == cnt[t])
			 {
				 cnt[t] = 888;
			 }
        }
    }
    
    for ( i = 0; i < j; i++)
	{
		if (cnt[i] == 888)
		{
			continue;
		}else
		{
			freq[i] = cnt[i];
			temp2++;
		}
			
	}

//podrejda po golemina
	for (i = 0; i < j; ++i) 
    {
        for (t = i + 1; t < j; ++t) 
        {
            if (freq[i] < freq[t]) 
            {
                temp = freq[i];
                freq[i] = freq[t];
                freq[t] = temp;
            }
        }
    }
	
	//izchislqva procentite
	for ( i = 0; i < temp2; i++)
    {
        for ( t = 0; t < j; t++)
		{
			if (freq[i] == dup[t])
			{
				perc[i]++;
			}	
		}
    }

	for ( i = 0; i < temp2; i++)
	{
		perc[i] = percentage(perc[i], j);
	}
	
	//printirane 
	for ( i = 0; i < temp2; i++)
	{
		printf("%d\t", freq[i]);
	}
	printf("\n");
	for ( i = 0; i < temp2; i++)
	{
		printf("%g\t", perc[i]);
	}

	//grafika
	chek = 100;
	printf("\n");
	for ( i = 0; i < chek; i++)
	{
		if (perc[0] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
		
        if (perc[1] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}        
        if (perc[2] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
        if (perc[3] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
		if (perc[4] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
		if (perc[5] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
		if (perc[6] > 0)
        {
            printf("|\t");
        }else
		{
			printf(" \t");
		}
            
		   
        
        printf("\n");
        perc[0] = perc[0] -1;
        perc[1] = perc[1] -1;
        perc[2] = perc[2] -1;
        perc[3] = perc[3] -1;
		perc[4] = perc[4] -1;
		perc[5] = perc[5] -1;
		perc[6] = perc[6] -1;
        if (perc[0] > 0 && perc[1] > 0 && perc[2] > 0 && perc[3] > 0 && perc[4] > 0 && perc[5] > 0 && perc[6] > 0)
		{
			break;
		}
	}
    
}

void stats(char _target[1000]){
	int space = 0;
	int symbols = 0;
	int signs = 0;
	int num = 0;
	int letters = 0;

	for (int i = 0; i < strlen(_target); i++)
    {
        if (_target[i] == ' ')
        {
            space++;
        }else
        {
            symbols++;
        }

		if(_target[i] >= 65 && _target[i] <= 90)
        {
            letters++;
        }
        else if (_target[i] >= 97 && _target[i] <= 122)
        {
            letters++;
        }
        
        
        if(_target[i] >= 33 && _target[i] <= 64)
        {
            signs++;
        }
        else if (_target[i] >= 91 && _target[i] <= 96)
        {
            signs++;
        }
        else if (_target[i] >= 123 && _target[i] <= 126)
        {
            signs++;
        }
        
        if (_target[i] >= 48 && _target[i] <= 57)
        {
            num++;
        }
    }

	printf(" total number of characters = %d \n", symbols);
    printf(" number of letters = %d \n", letters);
    printf(" empty spaces = %d \n", space);
    printf(" signs and symbols = %d\n", signs - num);
    printf(" numbers = %d\n", num);
}


int main()
{
    char str[10000] = {0};
    char buffer[50][15];
	char word[15];
    
    int wordNum = 0;
	int mostUsed = 0;


    printf("Enter the string: ");
    scanf(" %[^\n]s", str);

    wordNum = getWords(str, buffer);
	mostUsed = mostUsedWord(buffer, wordNum, word);

	//uslovie 1
    chart(str);

	//uslovie 2
	printf("\n number of words = %d\n", wordNum);
	if (mostUsed > 1)
    {
        printf(" most common word = %s => %d times\n", word, mostUsed);
    }
    
	//uslovie 3
	stats(str);

	printf("%s", str);
	return 0;
}
