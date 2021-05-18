#include<stdio.h>
#include<stdlib.h>

#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


char square[10] = {'\0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };     // Represents the realtime status of each square of the board


void createBoard();     // build the Board in each iteration
int isWin();    // Check for possible Win combinations;     if Win return 1, otherwise return 0
int isDraw();   // if Draw return 1, otherwise return 0
int checkResult();  // Checks the result at every iteration. Returns: 1, if Won;      0, if Draw;      -1, if game in Progress
int placeMark(int , char , int );   // put the mark at the desired posn, if it is available, and return 1. Otherwise return 0


int main()
{
    printf("***************Welcome to Multiplayer Tic Tac Toe***************\n");
    
    int player=1;     //  player = 1 or player = 2
    
    char mark;      //  Player 1 => X;      Player 2 => O
    
    int i;          //  used to keep track of the progress of the game ie if the game has already Won/ Draw/ Still in progress
    i=checkResult();

    int pos;        //  Store the desired insert position of the User
    
    while(i == -1)      //  Iterates as long as game is Still in progress
    {
       
        createBoard();
        
        mark = (player == 1) ? 'X' : 'O' ;
        
        printf(BOLDWHITE"Player %d; enter your desired position : ", player);
        scanf("%d", &pos);
        printf(BOLDBLACK"__________________________________________________________________________________________\n");
        
        
        placeMark(player, mark, pos);
        
        
        i=checkResult();
        
        player = (player%2 == 1) ? 2 : 1 ;      // ALternates the value of player between 1 & 2 each time
        
    }
    
    createBoard();
    
    if(i==1)        // Game Won either by 1 or 2 
    {
        player = player = (player%2 == 1) ? 2 : 1 ;     // Correct the already alternated value
        
        printf(BOLDGREEN"\n*************************************\n");
        printf("\n!!!!!!!!!! Player %d Won !!!!!!!!!!\n", player);
        printf("*************************************\n");
    }
    
    else
    {
        printf(BOLDRED"\n*************************************\n");
        printf("            Game Draw !\n");
        printf("*************************************\n");
    }
    
    return 0;
}


void createBoard()
{
    printf(BOLDYELLOW "Player 1 : X\nPlayer 2 : O\n\n");
    
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", square[1], square[2], square[3]);
    printf("        |        |        \n");
    printf("__________________________\n");
    
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", square[4], square[5], square[6]);
    printf("        |        |        \n");
    printf("__________________________\n");
    
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", square[7], square[8], square[9]);
    printf("        |        |        \n");
    
}

int isWin()      // Check for possible Win combinations;     if Win return 1, otherwise return 0
{
    if (square[1] == square[2] && square[2] == square[3])  
		return 1;
    else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else 
	    return 0;
}

int isDraw()     // if Draw return 1, otherwise return 0
{
    //  if Empty square is found then game should continue
    
    if((square[1] == '1')||(square[2] == '2')||(square[3] == '3')||(square[4] == '4')||(square[5] == '5')||(square[6] == '6')||(square[7] == '7')||(square[8] == '8')||(square[9] == '9'))     
        return 0;
    
    //  if no Empty square is found then Draw
    else
        return 1;
}


int checkResult()       // Returns: 1, if Won;      0, if Draw;      -1, if game in Progress
{
    if(isWin())
        return 1;
        
    else if(isDraw())
        return 0;
        
    else
        return -1;
}

int placeMark(int player, char mark, int pos)   // put the mark at the desired posn, if it is available, and return 1  // Otherwise return 0
{
    if(pos == 1 && square[1] == '1')
		square[1] = mark;
	else if(pos == 2 && square[2] == '2')
		square[2] = mark;
	else if(pos == 3 && square[3] == '3')
		square[3] = mark;
	else if(pos == 4 && square[4] == '4')
		square[4] = mark;
	else if(pos == 5 && square[5] == '5')
		square[5] = mark;
	else if(pos == 6 && square[6] == '6')
	    square[6] = mark;
	else if(pos == 7 && square[7] == '7')
	   square[7] = mark;
	else if(pos == 8 && square[8] == '8')
		square[8] = mark;
	else if(pos == 9 && square[9] == '9')
		square[9] = mark;
	else 
	    return 0;
	    
	return 1;
}



























