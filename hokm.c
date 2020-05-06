  #include<stdio.h>
  #include <stdlib.h>
  #include<time.h>
  #include<limits.h>
  #include <string.h>
  #include "hajilou.h"

  int gameManagement();
  int divideCard();
  void shuffleCard();
  int showGame();
  int showCard();
  int showCardPal();
  int showCardFoeAndCradCenterFoe2PalFoe1();
  int showCardMe();
  void determiningRuler();
  int determiningRul();
  int cardSeparatorAndRank(char*,char*);
  int determiningPointStartCard();
  int cardTypeCounter(int*,int*,int*,int*,int);
  int determiningRulByCountNumberCard(int);
  int calculateTotalCardRank(int);
  int determiningRulByCountCardOrTotalRank(int );
  int howDownCard();
  int minusMinusNumberDownCard();
  int addScoreWinPlayr(int);
  int insertCardToCardCenter(char*);
  int increaserIndexShowCardCenter();

  char card [52][5]={"D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13","D.14",
  "G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13","G.14",
  "P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13","P.14",
  "K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13","K.14"};

  char cardCopy [52][5]={"D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13","D.14",
  "G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13","G.14",
  "P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13","P.14",
  "K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13","K.14"};

  char cardCenter[4][5];//Includes cards that down with  player
  int indexCardCenter=0;
  int indexCardShowCenter=0;

  char foe1Card[13][5];
  char foe2Card[13][5];
  char palCard[13][5];
  char meCard[13][5];
  char rul[5];

  int ruler;//To determine who starts the game and sets the rules of the game.The number can be between 1 and 4(1=me,2=foe2,3=pal,4=foe1)
  enum player{Me=1,Foe2,Pal,Foe1};

  int levelDivideCard=0;//for select hokm by king

  int downerCard;//To determine who starts the game for down card .At first the game. It is equal to the ruler.The number can be between 1 and 4(1=me,2=foe2,3=pal,4=foe1)
  int numberDownCard=13;//To determine the number of cards down. The number can be between 1 and 13(Number of player cards)

  int scoreFoe=0;//sum score foe 1+foe 2
  int scoreWe=0;// sum score me + pal

  int pointStartCardRuler1=0;//me
  int pointStartCardRuler2=13;//foe2
  int pointStartCardRuler3=26;//pal
  int pointStartCardRuler4=39;//foe1

  int scoreWinMe=0;//To determine how much the player has win the game. The number can be between 0 and 7
  int scoreWinFoe2=0;
  int scoreWinPal=0;
  int scoreWinFoe1=0;

  int gameManagement()
  {
    if(levelDivideCard==0)
    {
      divideCard();
    }

    while(scoreWinMe!=7 ||scoreWinFoe2!=7 ||scoreWinPal!=7 ||scoreWinFoe1!=7 )
    {
      if(levelDivideCard==1)
      {
        divideCard();
      }
      determiningRuler();
      ruler=Me;// after delete just for test *-*-*-*
      determiningRul();
      howDownCard();
      showGame();
      if(downerCard==Me)
      {

      }


      minusMinusNumberDownCard();//*مکانش  انتهای هر پایین گذاشتن 4 برگه شود
    }
  }

  void determiningRuler()//diffreny to determiningRul
  {
    int temp=getRandomsNumber(1,4);
    printf("ruler = %d\n",temp );
    switch (temp) {
      case 1:
      {
        ruler= Me;
        break;
      }
      case 2:
      {
        ruler= Foe2;
        break;
      }
      case 3:
      {
        ruler= Pal;
        break;
      }
      case 4:
      {
        ruler= Foe1;
        break;
      }
      default:
      {
        break;
      }
    }
  }

  char *orginalRank;//When rankCard  returned. The result was a mistake and I didn't know how to fix it

  int determiningRul()
  {
    int pointStartCard=0;
    pointStartCard = determiningPointStartCard();

    determiningRulByCountCardOrTotalRank(pointStartCard);
    printf("rul= %s\n", rul);
  }

  int determiningRulByCountCardOrTotalRank(int pointStartCard)
  {
    if(determiningRulByCountNumberCard(pointStartCard)==0)// Determine the number of cards. If not, then the verdict will be determined by the total rank of the cards
    {
      calculateTotalCardRank(pointStartCard);
    }
    return 0;
  }

  int determiningRulByCountNumberCard(int pointStartCard)
  {
    int d,g,p,k;//To count card types
    d=g=p=k=0;
    cardTypeCounter(&d,&g,&p,&k,pointStartCard);
    if(d>2 ||g>2 ||p>2 ||k>2)
    {
      if(d>2)
      {
        rul[0]='D';
      }
      else if(g>2)
      {
        rul[0]='G';
      }
      else if(p>2)
      {
        rul[0]='P';
      }
      else if(k>2)
      {
        rul[0]='K';
      }
      return 1;
    }
    else if (d<2 ||g<2 ||p<2 ||k<2)
    {
      return 0;
    }
  }

int calculateTotalCardRank(int pointStartCard)
{

    char tempCard[5];
    char tempRank[5];

    int tempscore=0;//for change string to int
    int maxScore=0;
    int totalCardRankD , totalCardRankG , totalCardRankP , totalCardRankK ;//to collect card score.Which  by comparing the score of the  card  is determined rule
    totalCardRankD=totalCardRankG=totalCardRankP=totalCardRankK=0;

  for (int i=pointStartCard; i <(pointStartCard+5); i++)
  {
    strcpy(tempCard,cardCopy[i]);
    cardSeparatorAndRank(&tempCard[0] ,&tempRank[0]);
    switch (tempCard[0])
    {
      case 'D':
      {
        sscanf(orginalRank,"%d",&tempscore);
        totalCardRankD+=tempscore;
        if(maxScore<totalCardRankD)
        {
          maxScore=totalCardRankD;
          rul[0]='D';
        }
        printf(" totalCardRankD= %d\n",totalCardRankD);
        break;
      }

      case 'G':
      {
        sscanf(orginalRank,"%d",&tempscore);
        totalCardRankG+=tempscore;
        if(maxScore<totalCardRankG)
        {
          maxScore=totalCardRankG;
          rul[0]='G';
        }
        printf(" totalCardRankG= %d\n",totalCardRankG);
        break;
      }

      case 'P':
      {
        sscanf(orginalRank,"%d",&tempscore);
        totalCardRankP+=tempscore;
        if(maxScore<totalCardRankP)
        {
          maxScore=totalCardRankP;
          rul[0]='P';
        }
        printf(" totalCardRankP= %d\n",totalCardRankP);
        break;
      }

      case 'K':
      {
        sscanf(orginalRank,"%d",&tempscore);
        totalCardRankK+=tempscore;
        if(maxScore<totalCardRankK)
        {
          maxScore=totalCardRankK;
          rul[0]='K';
        }
        printf(" totalCardRankK= %d\n",totalCardRankK);
        break;
      }
      default:
      {
        return 102;
        break;
      }

    }
  }
  printf("rul end %s\n",rul );


}

int determiningPointStartCard()
  {
    switch(ruler)
    {
      case 1:
      {
        return pointStartCardRuler1;
        break;
      }

      case 2:
      {
        return pointStartCardRuler2;
        break;
      }

      case 3:
      {
        return pointStartCardRuler3;
        break;
      }

      case 4:
      {
        return pointStartCardRuler4;
        break;
      }
      default:
      {
      return 102;
      break;
    }
  }
 }

 int cardTypeCounter(int *d,int *g,int *p,int *k,int pointStartCard)
 {
   int tempD,tempG,tempP,tempK;
   tempD=tempG=tempP=tempK=0;
   char tempCard[5],tempRank[5];

   for (size_t i =pointStartCard; i < pointStartCard+5 ; i++)
    {
      strcpy(tempCard,cardCopy[i]);
      cardSeparatorAndRank(&tempCard[0] ,&tempRank[0]);

      switch (tempCard[0])
      {
        case 'D':
        {
          *d+=1;
          printf("%d*d\n",*d);
          break;
        }

        case 'G':
        {
          *g+=1;
          printf("%d*g\n",*g);
          break;
        }

        case 'P':
        {
          *p+=1;
          printf("%d*p\n",*p);
          break;
        }

        case 'K':
        {
          *k+=1;
          printf("%d*k\n",*k);
          break;
        }
        default:
        {
          return 102;
          break;
        }

      }
    }
    return 0;
 }

 int cardSeparatorAndRank(char *cards,char *rank)  // d.1 ===>  d  ,   1
 {
   char *tempCard;
   char deilam[]=".";
   tempCard= strtok(cards, deilam);
   rank = strtok(NULL, deilam);
   cards=tempCard;
   orginalRank=rank;//**
   return 0;
 }



  int divideCard()
  {
    char data1;
    shuffleCard();
    int endCard=0;
    if(levelDivideCard==0)
    {
      endCard=5;
      levelDivideCard++;
    }
      else if(levelDivideCard==1)
      {
        endCard=13;
      }

      for(int x=0;x<endCard;x++)//divide five card between players
      {

      strcpy(meCard[x],cardCopy[(pointStartCardRuler1 + x)]);
      strcpy(foe2Card[x],cardCopy[(pointStartCardRuler2 + x)]);
      strcpy(palCard[x],cardCopy[(pointStartCardRuler3 + x)]);
      strcpy(foe1Card[x],cardCopy[(pointStartCardRuler4 + x)]);
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
      randLoc1=getRandomsNumber(0,51);
      randLoc2=getRandomsNumber(0,51);
      strcpy(temp1,cardCopy[randLoc1]);
      strcpy(temp2,cardCopy[randLoc2]);
      strcpy(cardCopy[randLoc1],temp2);
      strcpy(cardCopy[randLoc2],temp1);
    }

    for (int x = 0; x < 52; x++)
    {
      printf("%s  %d \n",cardCopy[x],x+1 );
    }
  }

  int howDownCard()
  {
    if(numberDownCard==13)
    {
      downerCard=ruler;
      return 1;
    }
      else if(downerCard>0 && downerCard<4)
      {
        downerCard++;
        return 1;
      }
      else if(downerCard==4)
      {
        downerCard=1;
        return 1;
      }
    return 102;

  }

  int minusMinusNumberDownCard()
  {
    numberDownCard--;
    return 1;
  }

  int addScoreWinPlayr(int player)
  {
    switch (player)
    {
      case Me:
      {
        scoreWinMe++;
        break;
      }
      case Foe2:
      {
        scoreWinFoe2++;
        break;
      }
      case Pal:
      {
        scoreWinPal++;
        break;
      }
      case Foe1:
      {
        scoreWinFoe1++;
        break;
      }
      default:
      {
        return 102;
        break;
      }
    }
  }

  int insertCardToCardCenter(char *cardPlayer)
  {
    if(indexCardCenter>=0  && indexCardCenter<4)
    {
      strcpy(cardCenter[indexCardCenter],cardPlayer);
      indexCardCenter++;
      return 1;
    }
    else if(indexCardCenter>4)
    {
      indexCardCenter=0;
      return 1;
    }
    return 102;
  }

  int increaserIndexShowCardCenter()
  {
    int temp=indexCardCenter;
    if(indexCardShowCenter>=0  && indexCardShowCenter<4)
    {
      indexCardShowCenter++;
      return 1;
    }
    else if(indexCardCenter>4)
    {
      indexCardShowCenter=0;
      return 1;
    }
    return 102;
  }



  /*This is the section for displaying the game*/
  int showGame()
  {
    showCard();

  }

  int showCard()
  {
    showCardPal();
    showCardFoeAndCradCenterFoe2PalFoe1();
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
      printf("\t\t\t\t\t\t      card Pal \n\n ");
      printf("\t\t\t\t\t     ");

      for (int i = 0; i <endCard; i++)
      {
        printf(" %s ",palCard[i]);
      }
      printf("\n\n");
      printf("\t\t\t\t\t\t     Score Win: %d  ",scoreWinPal);
      printf("\n");//for delete % in end of print and ture location foeCard 1,2

  }

  int showCardFoeAndCradCenterFoe2PalFoe1()
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
      printf("\n\n\n\n");
      printf("\t\tcard Foe 1  \t\t\t\t%s\t\t\t\tcard Foe 2 \n ",cardCenter[indexCardShowCenter]);
      increaserIndexShowCardCenter();
      printf("\n");
      printf("\t");

      for (int i = 0; i <endCard; i++)
      {
        printf(" %s ",foe1Card[i]);
      }

      printf("\t\t %s",cardCenter[indexCardShowCenter]);//for set card foe2 on center window shell
      increaserIndexShowCardCenter();
      printf("\t\t%s\t\t",cardCenter[indexCardShowCenter]);
      increaserIndexShowCardCenter();
      for (int x = 0; x <endCard; x++)
      {
        printf(" %s ",foe2Card[x]);
      }
      printf("\n\n");
      printf("\t\tScore Win: %d   \t\t\t\t%s\t\t\t\t Score Win: %d \n\n ",scoreWinFoe1,cardCenter[indexCardShowCenter],scoreWinFoe2);
      increaserIndexShowCardCenter();
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
      printf("\t\t\t\t\t\t       card me \n\n ");
      printf("\t\t\t\t\t      ");

      for (int i = 0; i <endCard; i++)
      {
        printf(" %s ",meCard[i]);
      }
      printf("\n\n");
      printf("\t\t\t\t\t             Score Win: %d \n\n ",scoreWinMe);
      printf("\n");

  }

  int main(int argc, char const *argv[])
  {
    gameManagement();
    return 0;
  }
