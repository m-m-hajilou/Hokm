#include<stdio.h>
#include <time.h>
#include <stdlib.h>
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
