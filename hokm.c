#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
#include <string.h>
int getRandomsNumber(int, int);
int divideCard();
void shuffleCard();
int showGame();
int showCard();
int showCardPal();
int showCardFoe();
int showCardMe();


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
{
  char data1;
  shuffleCard();
  int endCard=0;
  if(levelDivideCard==0)
  {
    endCard=5;
  }
    else if(levelDivideCard==1)
    {
      endCard=13;
    }

    for(int x=0;x<endCard;x++)//divide five card between players
    {

    strcpy(foe1Card[x],cardCopy[x]);
    strcpy(foe2Card[x],cardCopy[x+5]);
    strcpy(palCard[x],cardCopy[x+10]);
    strcpy(meCard[x],cardCopy[x+15]);
    }
}

void shuffleCard()
{
  srand(time(0));//for set new number for rand()
  int randLoc1,randLoc2;
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

  //for (int x = 0; x < 52; x++)
  //{
    //printf("%s  %d , ",cardCopy[x],x+1 );
  //} 
}


/*This is the section for displaying the game*/
int showGame()
{
  showCard();

}

int showCard()
{
  showCardPal();
  showCardFoe();
  showCardMe();
}

int showCardPal()
{
  int endCard=0;

  if(levelDivideCard==0)
  {
    endCard=5;
  }
    else if(levelDivideCard==1)
    {
      endCard=13;
    }

    /* This section: Set the location of the cards*/
    printf("\t\t\t\t\t\t  card Pal \n\n ");
    printf("\t\t\t\t\t");

    for (int i = 0; i <endCard; i++)
    {
      printf(" %s ",palCard[i]);
    }
    printf("\n");//for delete % in end of print and ture location foeCard 1,2

}

int showCardFoe()
{
  int endCard=0;

  if(levelDivideCard==0)
  {
    endCard=5;
  }
    else if(levelDivideCard==1)
    {
      endCard=13;
    }
    /* This section: Set the location of the cards*/
    printf("\n\n");
    printf("\t\t\t  card Foe 1 \t\t\t\t\t card Foe 2 \n\n ");
    printf("\t\t");

    for (int i = 0; i <endCard; i++)
    {
      printf(" %s ",foe1Card[i]);
    }

    printf("\t\t\t");//for set card on center window shell
    for (int x = 0; x <endCard; x++)
    {
      printf(" %s ",foe2Card[x]);
    }
    printf("\n");//for delete % in end of print

}

int showCardMe()
{
  int endCard=0;

  if(levelDivideCard==0)
  {
    endCard=5;
  }
    else if(levelDivideCard==1)
    {
      endCard=13;
    }

    /* This section: Set the location of the cards*/
    printf("\n\n");
    printf("\t\t\t\t\t\t  card me \n\n ");
    printf("\t\t\t\t\t");

    for (int i = 0; i <endCard; i++)
    {
      printf(" %s ",meCard[i]);
    }
    printf("\n");//for delete % in end of print and ture location foeCard 1,2

}




int getRandomsNumber(int low, int up)
{
   return rand()% (up+low+1)+low;
}



int main(int argc, char const *argv[])
{
  divideCard();
  showGame();
  return 0;
}
