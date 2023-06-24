#include <stdio.h>
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2


void initGameBoard(int gameBoard[6][7])
{ int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            gameBoard[i][j]= EMPTY ;
        }
    }
}

void printGameBoard(int gameBoard[6][7]) {
int i,j;
for (i=0; i<6; i++) {
    for (j=0; j<8; j++){

     if(gameBoard[i][j]==EMPTY){
     printf ("| ");
     }

     else if(gameBoard[i][j]==CIRCLE){
     if(j==7){
      printf ("| ");
     }
     else{
     printf ("|O");
     }}

     else if(gameBoard[i][j]==CROSS){
     if(j==7){
       printf ("| ");
     }
     else{
     printf ("|X");
     }}

     }
     printf("\n");

  }
printf(" 1 2 3 4 5 6 7 ");

}
int hasWinner(int gameBoard[6][7],int player_number){
int i,j;
//horizontal
  for(j=0;j<4;j++){
    for(i=0;i<6;i++){
      if (gameBoard[i][j]==player_number && gameBoard[i][j+1]==player_number && gameBoard[i][j+2]==player_number && gameBoard[i][j+3]==player_number)
      {
        return 1;
      }
    }
  }
//vertical
  for(i=0;i<3;i++)
  {
    for(j=0;j<=6;j++){
      if (gameBoard[i][j]==player_number && gameBoard[i+1][j]==player_number && gameBoard[i+2][j]==player_number && gameBoard[i+3][j]==player_number)
      {
        return 1;
      }
    }
  }
//go down
  for(i=3;i<6;i++)
  {
    for(j=3;j<7;j++){
      if (gameBoard[i][j]==player_number && gameBoard[i-1][j-1]==player_number && gameBoard[i-2][j-2]==player_number && gameBoard[i-3][j-3]==player_number)
      {
        return 1;
      }
    }
  }

//go up
  for(i=3;i<6;i++)
  {
    for(j=0;j<4;j++){
      if (gameBoard[i][j]==player_number && gameBoard[i-1][j+1]==player_number && gameBoard[i-2][j+2]==player_number && gameBoard[i-3][j+3]==player_number)
      {
        return 1;
      }
    }
  }

  return 0;
}

void placeMark(int gameBoard[6][7],int mark,int input){
int i;
int full=0;

for (i=0;i<6;i++){

if(gameBoard[i][input-1]==EMPTY)
  {
    if(i==5)
    {

    gameBoard[i][input-1]=mark;

    break;
    }

    else
    {
    continue;
    }
  }

else
  {
    gameBoard[i-1][input-1]=mark;
    break;
  }
}
}

int columnFull(int gameBoard[6][7],int input){
  int i;
  for (i=0;i<6;i++)
  {

    if(gameBoard[i][input-1]==EMPTY)
    {
    continue;
    }

    else
    {
    break;
    }
  }
if (i==0)
{
  return 1;
}
else{
  return 0;
}
}


void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {
int i,j;
int input;
scanf("%d",&input);

while ((input>7)||(input<1)){
  printf("Input out of range. Please input again: ");
  scanf("%d",&input);
}

while(columnFull(gameBoard,input)>0)
{
      printf("Column is full. Please input again:\n");
      scanf("%d",&input);
      while ((input>7)||(input<1)){
      printf("Input out of range. Please input again: ");
      scanf("%d",&input);
}

}

placeMark(gameBoard,mark,input);

}

void randommove(int gameBoard[6][7]){
int i,j;
int count=0;
int tmp;
  for(i=5;i>=0;i--){
    for(j=6;j>=0;j--){
      if (gameBoard[i][j]==EMPTY)
      {
        if(count==0)
        {
          tmp=j;
          count=1;
        }
        else
        {
          if(j>tmp)
          {
            tmp=j;
          }
        }
      }
      else{
        continue;
      }
    }
    if(count>0){
      break;
    }
  }
  gameBoard[i][tmp]=CROSS;
}

int winnermove(int gameBoard[6][7]){
  int win=0;
  int i,j;
  int tmp;
  for(int j=0;j<=6;j++)
  {
    for(int i=5;i>=0;i--)
    {
      if(gameBoard[i][j]==EMPTY)
      {
        gameBoard[i][j]=CROSS;
        if((gameBoard[i+1][j]!=EMPTY)&&(hasWinner(gameBoard,CROSS)==1))
        {
          gameBoard[i][j]=CROSS;
          win=1;
        }
        else{
          gameBoard[i][j]=EMPTY;
        }
      }
      if(win==1){
        break;
      }
    }
  }

  if(win==1){
    return 1;
  }
  else{
    return 0;
  }

}

int blockplayermove(int gameBoard[6][7]){
  int win=0;
  int i,j;
  int tmp;
  for(int j=0;j<=6;j++)
  {
    for(int i=5;i>=0;i--)
    {
      if(gameBoard[i][j]==EMPTY)
      {
        gameBoard[i][j]=CIRCLE;
        if((gameBoard[i+1][j]!=EMPTY)&&(hasWinner(gameBoard,CIRCLE)==1))
        {
          gameBoard[i][j]=CROSS;
          win=1;
        }
        else{
          gameBoard[i][j]=EMPTY;
        }
      }
      if(win==1){
        break;
      }
    }
  }

  if(win==1){
    return 1;
  }
  else{
    return 0;
  }
}

void placemarkByComputerPlayer(int gameBoard[6][7])

{ if(winnermove(gameBoard)==0){

  if((winnermove(gameBoard)==0)&&(blockplayermove(gameBoard)==0))
    {
  randommove(gameBoard);
    }
}


}

int isFull(int gameBoard[6][7])
{
  int i,j;
  for (i=0; i<6; i++)
  {
    for (j=0; j<7; j++){
      if (gameBoard[i][j]==0)
      {
        return 0;
        break;
      }
      else{
        if((i==5)&&(j==6))
        {
          printf("\nDraw game.");
          return 1;
          break;
        }
        continue;
      }
      }
  }
  return 0;
}
int main(void){

int gameBoard[6][7];
int currentPlayer;
int gameContinue;
int numOfHumanPlayers;

initGameBoard(gameBoard);
currentPlayer = 1;
gameContinue = 1;

printf("Enter the number of human players [1-2]:\n");
scanf("%d", &numOfHumanPlayers);
printGameBoard(gameBoard);

if (numOfHumanPlayers==2){

while(gameContinue>0){

printf("\nPlayer 1's turn:\n");
placeMarkByHumanPlayer(gameBoard, CIRCLE);
printGameBoard(gameBoard);
hasWinner(gameBoard,CIRCLE);
if (hasWinner(gameBoard,CIRCLE)==1)
{
  printf("\nCongratulations! Player 1 wins!");
  gameContinue=0;
  break;
}

printf("\nPlayer 2's turn:\n");
placeMarkByHumanPlayer(gameBoard, CROSS);
printGameBoard(gameBoard);
hasWinner(gameBoard,CROSS);
if (hasWinner(gameBoard,CROSS)==1)
{
  printf("\nCongratulations! Player 2 wins!");
  gameContinue=0;
  break;
}

else
{
  gameContinue=1;
}

if (isFull(gameBoard)==0)
{
  gameContinue=1;
}
else
{
  gameContinue=0;
}

}
}

else{

while(gameContinue>0){

printf("\nPlayer 1's turn:\n");
placeMarkByHumanPlayer(gameBoard, CIRCLE);
printGameBoard(gameBoard);
hasWinner(gameBoard,CIRCLE);
if (hasWinner(gameBoard,CIRCLE)==1)
{
  printf("\nCongratulations! Player 1 wins!");
  gameContinue=0;
  break;
}

printf("\nComputer's turn:\n");
placemarkByComputerPlayer(gameBoard);
printGameBoard(gameBoard);
hasWinner(gameBoard,CROSS);
if (hasWinner(gameBoard,CROSS)==1)
{
  printf("\nCongratulations! Computer wins!");
  gameContinue=0;
  break;
}
else
{
  gameContinue=1;
}

if (isFull(gameBoard)==0)
{
  gameContinue=1;
}
else
{
  gameContinue=0;
}

}

}

return 0;
}
