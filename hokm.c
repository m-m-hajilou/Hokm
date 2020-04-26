#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
#include <string.h>
int getRandomsNumber(int, int);
int divideCard();
void shuffleCard();


char card [52][5]={"D.1","D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13",
"G.1","G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13",
"P.1","P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13",
"k.1","K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13"};

char cardCopy [52][5]={"D.1","D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13",
"G.1","G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13",
"P.1","P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13",
"k.1","K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13"};

char foe1Card[13][5];
char foe2Card[13][5];
char palCard[13][5];
char meCard[13][5];

int levelDivideCard=0;//for select hokm by king

int scoreFoe=0;//sum score foe 1+foe 2
int scoreWe=0;// sum score me + pal

char players[4]={'A','B','C','D'};

int divideCard()
{ char data1;
  shuffleCard();
  if(levelDivideCard==0)
  {
    for(int x=0;x<5;x++)//divide five card between players
    {

    strcpy(foe1Card[x],cardCopy[x]);
    strcpy(foe2Card[x],cardCopy[x+5]);
    strcpy(palCard[x],cardCopy[x+10]);
    strcpy(meCard[x],cardCopy[x+15]);
    }
  }

}

void shuffleCard()
{
  srand(time(0));//for set new number for rand()
  int j,randLoc1,randLoc2;
  char changeCard1;
  char changeCard2;
  char temp1[5],temp2[5];

    for(int i=0;i<100;i++)//In each card ring, the location changes randomly (in the test: 100 rings were good)
    {
      randLoc1=getRandomsNumber(0,50);
      randLoc2=getRandomsNumber(0,50);

      strcpy(temp1,cardCopy[randLoc1]);
      strcpy(temp2,cardCopy[randLoc2]);
      strcpy(cardCopy[randLoc1],temp2);
      strcpy(cardCopy[randLoc2],temp1);
      }

  for(int i=0;i<52;i++)
  {
    printf("%s  %d\n",cardCopy[i],i );
  }
}

int copyArraye()
{

}

int getRandomsNumber(int low, int up)
{
   return rand()% (up+low+1)+low;
}

int main(int argc, char const *argv[])
{
  divideCard();
  return 0;
}
