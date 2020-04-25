#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
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

int divideCard()
{
  shuffleCard();
  if(levelDivideCard==1)
  {
    for(int x=0;x<5;x++)//divide five card between players
    {
    foe1Card[x][5]=cardCopy[x][5];
    foe2Card[x][5]=cardCopy[x+5][5];
    palCard[x][5]=cardCopy[x+10][5];
    meCard[x][5]=cardCopy[x+15 ][5];

    }
    int j=0;
    for(int y=0;y<5;y++)//divide five card between players
    {
      printf(" foe1Card  * %s  %d\n",foe1Card[y] ,++j);
      printf(" foe2Card  * %s  %d\n",foe2Card[y] ,++j);
      printf(" palCard   * %s  %d\n",palCard[y] ,++j);
      printf(" meCard    * %s  %d\n",meCard[y] ,++j);

    }
  }

}

void shuffleCard()
{
  srand(time(0));//for set new number for rand()
  int j,randLoc1,randLoc2;
  char changeCard1;
  char changeCard2;

    for(int i=0;i<52;i++)
    {
      randLoc1=getRandomsNumber(0,50);
      randLoc2=getRandomsNumber(0,50);

      changeCard1=cardCopy[randLoc1][5];
      changeCard2=cardCopy[randLoc2][5];

      cardCopy[randLoc1][5]=changeCard2;
      cardCopy[randLoc2][5]=changeCard1;
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
