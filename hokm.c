  #include<stdio.h>
  #include<stdlib.h>
  #include<time.h>
  #include<limits.h>
  #include<string.h>
  #include"hajilou.h"


  int gameManagement();
  int divideCard();
  void shuffleCard();
  int showGame();
  int showCardAndScoure();
  int showCardMeAndScoure();
  int showCardFoe2AndScoure();
  int showCardPalAndScoure();
  int showCardFoe1AndScoure();
  void determiningRuler();
  int determiningRulWithMe();
  int determiningRul();
  int cardSeparatorAndRank(char[]);
  int determiningPointStartCard();
  int cardTypeCounter(int*,int*,int*,int*,int,char (*)[]);
  int determiningRulByCountNumberCard(char(*)[5]);
  int determiningRulByCalculateTotalCardRank(char(*)[5]);
  int determiningRulByCountCardOrTotalRank(char(*)[5] );
  int howDownCardInStartGameAndIncreaseDownCardInGame();
  int minusMinusNumberDownCard();
  int addScoreWinPlayr(int);//سلام احتمالاب باید حذف شود
  int insertCardToCardCenter(char*);// And  this card is  down  then removed from the player's cards by decreaseCardPlayer()
  int decreaseCardPlayer();// read above comment
  int increaserIndexCardShowCenter();
  int getCardUser(int,int,char (*)[]);
  int whoGetCardMax();
  int convertIntToChar(int);
  int charToint(char []);
  int increaserNumberDownCardInCenter();
  int increaserScoreWiner();
  int determiningFinalWinner();
  int playerCardDowns();
  int artificialIntelligenceCardDown(int,int,char(*)[]);
  int increaseIndexInsertCardCenter();
  int increaserLevelGame();
  int isdownCardPlayerEqualZero();
  int emptyTempForShowCardInCenter();
  int determingingNumberOfCardsAreDivided();
  int variableEmptyer();




  int levelGame=0;//for  determinging is ruler (level =1) , determinging is rul (level =2),divivide card (level =3),determinging Downer card(level =4),player downing card (level=5)



  char card [52][5]={"D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13","D.14",
  "G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13","G.14",
  "P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13","P.14",
  "K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13","K.14"};

  char cardCopy [52][5]={"D.2","D.3","D.4","D.5","D.6","D.7","D.8","D.9","D.10","D.11","D.12","D.13","D.14",
  "G.2","G.3","G.4","G.5","G.6","G.7","G.8","G.9","G.10","G.11","G.12","G.13","G.14",
  "P.2","P.3","P.4","P.5","P.6","P.7","P.8","P.9","P.10","P.11","P.12","P.13","P.14",
  "K.2","K.3","K.4","K.5","K.6","K.7","K.8","K.9","K.10","K.11","K.12","K.13","K.14"};

  char cardCenter[4][5];//Includes cards that down with  player
  int indexInsertCardCenter=0;
  int indexCardShowCenter=0;

  char tempForShowCardMe[5];//for show card center player if that is not downer card
  char tempForShowCardFoe2[5];
  char tempForShowCardPal[5];
  char tempForShowCardFoe1[5];

  char foe1Card[13][5];
  char foe2Card[13][5];
  char palCard[13][5];
  char meCard[13][5];
  char rul[5];

  char cardUser[1][5];//Contains card player Me
  char cardMax[4][5];//Whoever owns this card is the winner

  char intToChar[5];

  int ruler;//To determine who starts the game and sets the rules of the game.The number can be between 1 and 4(1=me,2=foe2,3=pal,4=foe1)
  enum player{Me=1,Foe2,Pal,Foe1};

  int levelDivideCard=0;//if level = 0   then divide 5 card to all player for select hokm with king and if level =1 divide 13 card to all player and  level =2 means divide all card
  int numberOfCardsAreDivid=0;

  int downerCard;//To determine who starts the game for down card .At first the game. It is equal to the ruler.The number can be between 1 and 4(1=me,2=foe2,3=pal,4=foe1)
  int numberDownCard=13;//To determine the number of cards down players. The number can be between 1 and 13(Number of player cards)
  int numberDownCardInCenter=0;//To determine the number of cards down in center for win.in Start each game starts at zero The number can be between 1 and 4(Number of player cards)


  int pointStartCardRuler1=0;//me
  int pointStartCardRuler2=13;//foe2
  int pointStartCardRuler3=26;//pal
  int pointStartCardRuler4=39;//foe1

  int scoreWinMe=0;//To determine how much the player has win the game. The number can be between 0 and 7
  int scoreWinFoe2=0;
  int scoreWinPal=0;
  int scoreWinFoe1=0;

  int scoreFoe=0;//sum score foe 1+foe 2
  int scoreWe=0;// sum score me + pal
  char finalWinner[4];

  int isDownCardMe=0;
  int isDownCardFoe2=0;
  int isDownCardPal=0;
  int isDownCardFoe1=0;


  int gameManagement()
  {
    int a;
    srand(time(0));
    determiningRuler();
    ruler=1;
    increaserLevelGame();
    printf("Ruler = %d\n",ruler );
    showGame();
    //delay(1);
    shuffleCard();
    divideCard();
    showGame();
    //delay(1);
    determiningRul();
    printf("Rul = %s\n",rul );
    increaserLevelGame();
    showGame();
    //delay(1);
    divideCard();
    increaserLevelGame();
    showGame();
    //delay(1);
    while(scoreWe < 7 && scoreFoe < 7 )
    {
      indexCardShowCenter=indexInsertCardCenter=numberDownCardInCenter=0;
      emptyTempForShowCardInCenter();//Nothing serious. just for show.
      isdownCardPlayerEqualZero();//Nothing serious. just for show.
      for (int i = 0; i < 4; i++)
      {
        levelGame=3;//because in loop level is ture(0<level<6)

        howDownCardInStartGameAndIncreaseDownCardInGame();//defult in firt == ruler
        increaserLevelGame();
        showGame();
        //delay(1);
        playerCardDowns();
        increaserLevelGame();
        showGame();
        //delay(1);
        increaserNumberDownCardInCenter();
        whoGetCardMax();
        //delay(1);
      }
      minusMinusNumberDownCard();//*مکانش  انتهای هر پایین گذاشتن 4 برگه شود
      increaserScoreWiner();//
      showGame();
      //delay(1);
    //  break;
     a=indexCardShowCenter;
     int ab=indexCardShowCenter;
    }
    determiningFinalWinner();
  }

  int determiningRulWithMe()
  {
    int ok=0;
    char temp[5];
    while (ok!=1)
    {
      scanf(" %5[^\n]%*c",temp );
      printf("\n" );
      if(strlen(temp)==1)
      {

      switch (temp[0])
      {
        case 'D':
        {
          strcpy(rul,"D");
          //rul[0]='D';
          ok=1;
          break;
        }
        case 'G':
        {
          rul[0]='G';
          ok=1;
          break;
        }
        case 'P':
        {
          rul[0]='P';
          ok=1;
          break;
        }
        case 'K':
        {
          rul[0]='K';
          ok=1;
          break;
        }
        default:
        {
          printf(" is not ture *Please try enter true RUL (true RUL: D || P || K || G)(*upper word*)*\n" );
          break;
        }

      }
    }
      else
      {
        printf(" is not ture LENGHT *Please try enter true RUL (true RUL: D || P || K || G)(*upper word*)*\n" );
      }
    }
    return 1;
  }

  void determiningRuler()//diffreny to determiningRul
  {
    int temp=getRandomsNumber(1,4);
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
  char *orginalCard;
  int  determiningRul()
  {
    int pointStartCard=0;
    pointStartCard = determiningPointStartCard();
    switch (ruler)
    {
      case Me:
      {
        determiningRulWithMe();
        return 1;
      }
      case Foe2:
      {
        determiningRulByCountCardOrTotalRank(foe2Card);
      //  printf("rul******= %s\n", rul);
        return 1;
      }
      case Pal:
      {
        determiningRulByCountCardOrTotalRank(palCard);
      //  printf("rul******= %s\n", rul);
        return 1;
      }
      case Foe1:
      {
        determiningRulByCountCardOrTotalRank(foe1Card);
        //printf("rul******= %s\n", rul);
        return 1;
      }
      default :
      {
        return 102;
      }
    }
  }

  int determiningRulByCountCardOrTotalRank(char arr[][5])
  { int pointStartCard=0;
    if(determiningRulByCountNumberCard(arr)==0)// Determine the number of cards. If not, then the verdict will be determined by the total rank of the cards
    {
      determiningRulByCalculateTotalCardRank(arr);
      return 1;
    }
    return 0;
  }

  int determiningRulByCountNumberCard(char arr [][5])
  {
    int d,g,p,k;//To count card types
    d=g=p=k=0;
    cardTypeCounter(&d,&g,&p,&k,5,arr);
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

int determiningRulByCalculateTotalCardRank(char arr [][5])
{

    char tempCard[5];
    char tempRank[5];

    int tempscore=0;//for change string to int
    int maxScore=0;
    int totalCardRankD , totalCardRankG , totalCardRankP , totalCardRankK ;//to collect card score.Which  by comparing the score of the  card  is determined rule
    totalCardRankD=totalCardRankG=totalCardRankP=totalCardRankK=0;

  for (int i=0; i < 5; i++)
  {
    strcpy(tempCard,arr [i]);
    cardSeparatorAndRank(tempCard);
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
//        printf(" totalCardRankD= %d\n",totalCardRankD);
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
        //printf(" totalCardRankG= %d\n",totalCardRankG);
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
    //    printf(" totalCardRankP= %d\n",totalCardRankP);
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
    //    printf(" totalCardRankK= %d\n",totalCardRankK);
        break;
      }
      default:
      {
        return 102;
        break;
      }

    }
  }
//  printf("rul end %s\n",rul );


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

 int cardTypeCounter(int *d,int *g,int *p,int *k,int length,char arr [][length])
 {
   int tempD,tempG,tempP,tempK;
   tempD=tempG=tempP=tempK=0;
   char tempCard[5],tempRank[5];

   for (size_t i =0; i < 5 ; i++)
    {
      strcpy(tempCard,arr[i]);
      cardSeparatorAndRank(tempCard );

      switch (*orginalCard)
      {
        case 'D':
        {
          *d+=1;
        //  printf("%d*d\n",*d);
          break;
        }

        case 'G':
        {
          *g+=1;
        //  printf("%d*g\n",*g);
          break;
        }

        case 'P':
        {
          *p+=1;
        //  printf("%d*p\n",*p);
          break;
        }

        case 'K':
        {
          *k+=1;
      //    printf("%d*k\n",*k);
          break;
        }
        default:
        {
          return 102;
          break;
        }

      }
    }
    return 1;
 }

 int cardSeparatorAndRank(char cards [5])  // d.1 ===>  d  ,   1
 {
   char *tempCard=cards;//for strcpy(*neded to pointer,)
   char deilam[]=".";
   orginalCard = strtok(tempCard, deilam);
   orginalRank = strtok(NULL, deilam);
   return 0;
 }



  int divideCard()
  {
    determingingNumberOfCardsAreDivided();
   for(int x=0;x<numberOfCardsAreDivid;x++)//divide five card between players
      {

      strcpy(meCard[x],cardCopy[(pointStartCardRuler1 + x)]);
      strcpy(foe2Card[x],cardCopy[(pointStartCardRuler2 + x)]);
      strcpy(palCard[x],cardCopy[(pointStartCardRuler3 + x)]);
      strcpy(foe1Card[x],cardCopy[(pointStartCardRuler4 + x)]);
      }
      levelDivideCard++;
      return 1;
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

//    for (int x = 0; x < 52; x++)
    {
      //printf("%s  %d \n",cardCopy[x],x+1 );
    }
  }

  int howDownCardInStartGameAndIncreaseDownCardInGame()
  {
    if(numberDownCard==13 && numberDownCardInCenter==0)//mean now game is start
    {
      downerCard=ruler;
      return 1;
    }
      else if (numberDownCardInCenter<4)
      {
        if(downerCard>0 && downerCard<4)
        {
          downerCard++;
        }
          else if ( downerCard==4) {
            downerCard=1;
            return 1;
          }
      }
      else if(numberDownCardInCenter==4)
      {
        downerCard=charToint(cardMax[0]);
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
    int a= indexInsertCardCenter;
      strcpy(cardCenter[indexInsertCardCenter],cardPlayer);
      increaseIndexInsertCardCenter();
      return 1;
  }

  int decreaseCardPlayer()
  {
    switch (downerCard)
    {
      case Me:
      {
        removeStringInArray(numberDownCard,5,meCard,cardCenter[indexInsertCardCenter-1]);//int removeStringInArray(int numberOfString,int maxSringSize,char  array[numberOfString][maxSringSize], char *string(for search in array) )
        break;
      }

    }
  }

  int increaserIndexCardShowCenter()
  {
    int temp=indexCardShowCenter;
    if(indexCardShowCenter>=0  && indexCardShowCenter<4)
    {
      indexCardShowCenter++;
      if(indexCardShowCenter==4)
      {
        indexCardShowCenter=0;
      }
      temp=indexCardShowCenter;
      return 1;
    }
    return 102;
  }

  int getCardUser(int numberHomeArray,int lengthArray,char arraySearch [][lengthArray] )//**-*-* after numberHomeArray=numberDownCard*-*-*-
  {
    char wordSearch[1][5];
    int trueInput=0;
    while(trueInput==0)
    {
    scanf(" %5[^\n]%*c",wordSearch[0] );
    printf("\n" );
    if(searchInArrayString2D(numberHomeArray,lengthArray,arraySearch,wordSearch[0])==1)// in hajilou .h: numberhomesarray , length homes array . array , word search
    {
      strcpy(*cardUser,*wordSearch);
      trueInput=1;
      return 1;
    }
      else
      {
        printf("%s is not ture because no choose from your cards  or  enter not true card (true card: Capital lettersDOT2to14(example:D.2))*\n",*wordSearch );
      }
    }
    return 102;
  }
  int max;//for save value when repet cakk whoGetCardMax()
  int test;
  int whoGetCardMax()
  {
    char baseCard[5];//first card is down with card downer. That other players should follow as this card But If possible
    char temp[5];//because cardSeparatorAndRank changes valuse. and this is temp that if valuses change not problem
    strcpy(temp,cardCenter[0]);
    cardSeparatorAndRank(temp);
    int a=numberDownCardInCenter;
    strcpy(baseCard,orginalCard);

      if(indexInsertCardCenter==0)// because indexInsertCardCenter-1 =-1 and this is error for cardSeparatorAndRank(cardCenter(-1))
      {
        strcpy(temp,cardCenter[3]);
      }
        else if (indexInsertCardCenter>0)
        {
          strcpy(temp,cardCenter[indexInsertCardCenter-1]);
        }
      cardSeparatorAndRank(temp);
      convertIntToChar(downerCard);//out put in intToChar


    if(numberDownCardInCenter==1)
    {
      strcpy(cardMax[0],intToChar);
      strcpy(cardMax[1],orginalCard);//because array start an 0  but downerCard statrt an 1
      strcpy(cardMax[2],orginalRank);
      max=charToint(orginalRank);
      printf("in first max card = %s\n", intToChar);
      return 1;
    }
      else if (numberDownCardInCenter > 0 && strcmp(baseCard,rul)==0 && strcmp (orginalCard,rul)==0)//strcmp if is true then return 0
      {
        if (max < charToint(orginalRank))
        {
          strcpy(cardMax[0],intToChar);//numbers player
          strcpy(cardMax[1],orginalCard);//because array start an 0  but downerCard statrt an 1
          strcpy(cardMax[2],orginalRank);
          max=charToint(orginalRank);
          printf("in two card is hokm and base is hokm max card = %s\n", intToChar);
          //delay(1);
          return 1;
        }
      }
      else if (numberDownCardInCenter > 0 && strcmp(baseCard,rul)!=0 && strcmp(orginalCard,rul)!=0 && strcmp(orginalCard,baseCard)==0 )
      {
        if (max < charToint(orginalRank))
        {
          strcpy(cardMax[0],intToChar);
          strcpy(cardMax[1],orginalCard);//because array start an 0  but downerCard statrt an 1
          strcpy(cardMax[2],orginalRank);
          max=charToint(orginalRank);
          printf("in two card nist hokm and base nist hokm max card = %s\n", intToChar);
          //delay(1);
          return 1;
        }
      }
      else if (numberDownCardInCenter > 0 && strcmp(baseCard,rul)!=0 && strcmp(orginalCard,rul)==0)
      {
      int   stest=numberDownCardInCenter;
        strcpy(cardMax[0],intToChar);
        strcpy(cardMax[1],orginalCard);//because array start an 0  but downerCard statrt an 1
        strcpy(cardMax[2],orginalRank);
        max=charToint(orginalRank);
        for (int  i = numberDownCardInCenter - 2; i > 0; i--) {
          strcpy(temp,cardCenter[i]);
          cardSeparatorAndRank(temp);
          char test[5];
          if (strcmp(orginalCard,rul)==0 )
          if( max < charToint(orginalRank))
          {
            stest=21;
            convertIntToChar(i+1);//out put in intToChar
            strcpy(cardMax[0],intToChar);
            strcpy(cardMax[1],orginalCard);//because array start an 0  but downerCard statrt an 1
            strcpy(cardMax[2],orginalRank);
            max=charToint(orginalRank);
            printf("in two card is hokm and base nist hokm max card = %s\n", intToChar);
            //delay(1);
            return 1;
          }
        }
      }
      return 102;

  }

  int convertIntToChar(int number)
  {
    sprintf(intToChar,"%d",number);
  }

  int charToint(char arr[])
  {
    int number;
    const char *strPoint=arr;
    sscanf(strPoint,"%d",&number);
    return number;
  }

  int increaserNumberDownCardInCenter()
  {
    if (numberDownCardInCenter>= 0 && numberDownCardInCenter<4)
    {
      numberDownCardInCenter++;
      return 1;
    }
      else if (numberDownCardInCenter==4)
      {
        numberDownCardInCenter=1;
        return 1;
      }
    return 102;
  }

  int increaserScoreWiner()
  {
    int n=charToint(cardMax[0]);
    switch (n)
    {
      case Me:
      {
        scoreWinMe++;
        scoreWe++;
        break;
      }
      case Foe2:
      {
        scoreWinFoe2++;
        scoreFoe++;
        break;
      }
      case Pal:
      {
        scoreWinPal++;
        scoreWe++;
        break;
      }
      case Foe1:
      {
        scoreWinFoe1++;
        scoreFoe++;
        break;
      }
      default:
      {
        return 102;
      }
    }
    return 1;
  }

  int determiningFinalWinner()
  {
    if(scoreWe==7)
    {
      strcpy(finalWinner,"Me");
    }
      else if(scoreFoe==7)
        {
          strcpy(finalWinner,"Foe");
        }
   }

   int playerCardDowns()
   {
     switch (downerCard)
     {
       case Me:
       {
         getCardUser(numberDownCard,5,meCard);
         char temp[5];
         strcpy(temp,cardUser[0]);
         insertCardToCardCenter(cardUser[0]);
         removeStringInArray(numberDownCard,5,meCard,cardUser[0]);
         isDownCardMe=1;
         break;
       }
       case Foe2:
       {
         artificialIntelligenceCardDown(numberDownCard,5,foe2Card);
         isDownCardFoe2=1;
         break;
       }
       case Pal:
       {
        artificialIntelligenceCardDown(numberDownCard,5,palCard);

         isDownCardPal=1;
         break;
       }
       case Foe1:
       {
         artificialIntelligenceCardDown(numberDownCard,5,foe1Card);

         isDownCardFoe1=1;
         break;
       }
       default:
       {
         return 102;
       }
     }
     return 1;
   }

   int artificialIntelligenceCardDown(int lengthArray,int maxSringSize,char arr [lengthArray][maxSringSize])
   {
     insertCardToCardCenter(arr[0]);
     removeStringInArray(lengthArray,maxSringSize,arr,arr[0]);
   }

   int increaseIndexInsertCardCenter()
   {
     if(indexInsertCardCenter>=0  && indexInsertCardCenter<4)
     {
       indexInsertCardCenter++;
       return 1;
     }

       else if(indexInsertCardCenter==4)
       {
         indexInsertCardCenter=0;
         return 1;
       }

     return 102;
   }

   int increaserLevelGame()
   {
     levelGame++;
     return 1;
   }

   int isdownCardPlayerEqualZero()
   {
     isDownCardMe=0;
     isDownCardFoe2=0;
     isDownCardPal=0;
     isDownCardFoe1=0;
   }

   int emptyTempForShowCardInCenter()
   {
      tempForShowCardMe[0]='\0';
      tempForShowCardFoe2[0]='\0';
      tempForShowCardPal[0]='\0';
      tempForShowCardFoe1[0]='\0';

   }
   int determingingNumberOfCardsAreDivided()
   {
     if (levelDivideCard==0)
     {
       numberOfCardsAreDivid=5;
       return 1;
     }
       else if (levelDivideCard==1)
       {
         numberOfCardsAreDivid=13;
         return 1;
       }
     return 102;
   }



  /*This is the section for displaying the game*/
  int showGame()
  {
    system("clear");
    printf("rul = %s\n",rul );
    printf("ruler = %d \n",ruler  );
    printf("downerCard = %d \n",downerCard  );

    showCardAndScoure();

  }

  int showCardAndScoure()
  {
    printf("\n" );


        showCardMeAndScoure();
        showCardFoe2AndScoure();
        showCardPalAndScoure();
        showCardFoe1AndScoure();


  }

  int showCardMeAndScoure()
  {
    printf("Me Card:\t" );
    for (int  i = 0; i <numberOfCardsAreDivid; i++) {
      printf("%s ",meCard[i] );
    }
    printf("\tScore Win Me :  %d",scoreWinMe );
    if( levelGame== 5 &&isDownCardMe==1)
    {
      int a=indexCardShowCenter;
      strcpy(tempForShowCardMe,cardCenter[indexCardShowCenter]);
      increaserIndexCardShowCenter();
      int ab=indexCardShowCenter;
      isDownCardMe=0;
    }
    printf("\t\t%s",tempForShowCardMe );
    printf("\n");
    printf("\n");
  }

  int showCardFoe2AndScoure()
  {
    printf("Foe2 Card:\t" );
    for (int  i = 0; i <numberOfCardsAreDivid; i++) {
      printf("%s ",foe2Card[i] );
    }
    printf("\tScore Win Foe2 :  %d",scoreWinFoe2 );
    if( levelGame== 5 &&isDownCardFoe2==1 )
    {
      int a=indexCardShowCenter;
      strcpy(tempForShowCardFoe2,cardCenter[indexCardShowCenter]);
      increaserIndexCardShowCenter();
      int ab=indexCardShowCenter;
      isDownCardFoe2=0;
    }
    printf("\t\t%s",tempForShowCardFoe2 );
    printf("\n");
    printf("\n");
  }

  int showCardPalAndScoure()
  {
    char temp [5];
    printf("Pal Card:\t" );
    for (int  i = 0; i <numberOfCardsAreDivid; i++) {
      strcpy(temp,palCard[i]);
      printf("%s ",palCard[i] );
    }
    printf("\tScore Win Pal :  %d",scoreWinPal );
    if( levelGame== 5 &&isDownCardPal==1)
    {
      int a=indexCardShowCenter;
      strcpy(tempForShowCardPal,cardCenter[indexCardShowCenter]);
      increaserIndexCardShowCenter();
      int ab=indexCardShowCenter;
      isDownCardPal=0;
    }
    printf("\t\t%s",tempForShowCardPal );
    printf("\n");
    printf("\n");
  }

  int showCardFoe1AndScoure()
  {
    printf("Foe1 Card:\t" );
    for (int  i = 0; i <numberOfCardsAreDivid; i++) {
      printf("%s ",foe1Card[i] );
    }
    printf("\tScore Win Foe1 :  %d",scoreWinFoe1 );
    if( levelGame== 5 &&isDownCardFoe1==1)
    {
      int a=indexCardShowCenter;
      strcpy(tempForShowCardFoe1,cardCenter[indexCardShowCenter]);
      increaserIndexCardShowCenter();
      int ab=indexCardShowCenter;
      isDownCardFoe1=0;
    }
    printf("\t\t%s",tempForShowCardFoe1 );
    printf("\n");
    printf("\n");
  }

  int main(int argc, char const *argv[])
  {
    gameManagement();
    return 0;
  }
