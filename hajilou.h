#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
float inputNumber;
float getNumberConfine(int low,int hi)
{
  printf(" please insert true number  the number is %d <= input number >= %d  \n \n ",low,hi);
  do
  {
    scanf("%f",&inputNumber);
    if(inputNumber>=low & inputNumber<=hi)
    {
    return inputNumber;
    }
    printf("***error***   your number not true   ***error*** \n please insert true number  the number is %d <= input number >= %d  \n \n ",low,hi);
  }  while (inputNumber<=low | inputNumber>=hi);
}

float getNumber()
{
  scanf("%f",&inputNumber);
  return inputNumber;
}

int getRandomsNumber(int low, int up)
  {
    return (rand() %(up - low + 1)) + low;
  }
int searchInArrayString2D(int countArray,int lengthChar,char arr[][lengthChar],char search[])
{
   int i = 0;
   int n = 0;
   int m = 0;
   int countCharEqual=0;
   int ok = 0;
   int lenSearch = strlen(search);      // contains the length of search string
   int lenArr=0;
   char deilam=',';
   if(lenSearch<3 || lenSearch>4)
   {
     return 0;
   }
   for (int a = 0; a <= countArray; a++)
    {
      lenArr=strlen(arr[a]);
      if(lenArr==lenSearch)// len K.1 != len K.14   . If this is not  line, due to the next condition: A.1 is equal to A.14 *
      {
      while (i<lenSearch)
      {
        if (arr[a][i]==search[m] )
        {
          i++;
          m++;
          countCharEqual++;
        }
          else
          {
            break;
          }
    }
    if(countCharEqual==lenSearch)
    {
      return 1;
    }
      else if (countCharEqual!=lenSearch)
      {
        i=m=countCharEqual=0;
      }
   }
 }
 return 0;
}

