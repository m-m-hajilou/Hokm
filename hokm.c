#include<stdio.h>
#include <stdlib.h>
#include<time.h>

char card [53][4]={"D.1","D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13",
"G.1","G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13",
"P.1","P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13",
"k.1","K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13"};

char cardCopy [53][4]={"D.1","D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13",
"G.1","G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13",
"P.1","P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13",
"k.1","K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13"};
char foe1Card[13][4];
char foe2Card[13][4];
char palCard[13][4];
char meCard[13][4];

int divideCard()
{
  srand(time());
  int j;
  for(int i=0;i<53;i++)
  {
    j=getRandomsNumber(0,53);
    cardCopy[i]=card[j];
    

  }
}

int getRandomsNumber(int low, int up)
{
   return rand()% (up+low+1)+low;
}

int main(int argc, char const *argv[])
{

    srand(time());
    int randomnumber=0+rand()%6;
    printf("%d\n",randomnumber );
  return 0;
}
