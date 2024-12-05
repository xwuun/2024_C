//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------S
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
   int i ;
   int cnt = 0;
   for(i=0;i<N_PLAYER;i++)
   {
   	if (player_status[i] == PLAYERSTATUS_END)
   		cnt++;
   }
   return cnt;
}
int getWinner(void) {
    int i;
    int winner = -1;
    int max_coin = -1;
    int min_position = N_BOARD;

    for (i = 0; i < N_PLAYER; i++) {
        if (player_status[i] == PLAYERSTATUS_LIVE || player_status[i] == PLAYERSTATUS_END) {
            if (player_coin[i] > max_coin) {
                max_coin = player_coin[i];
                winner = i;
                min_position = player_position[i];
            } else if (player_coin[i] == max_coin) {
                if (player_position[i] < min_position) {
                    winner = i;
                    min_position = player_position[i];
                }
            }
        }
    }
    return winner;
}



// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;
	int gameAlreadyEnded = 0;
// ----- EX. 1 : Preparation------------
    srand((time(NULL)));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;
            continue;
        }
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        
        
 		// step 2-3. moving
		dieResult = rolldie(); 
		printf("Die result: %d, %s moved to %d!\n", dieResult, player_name[turn], player_position[turn] + dieResult);

		player_position[turn] += dieResult; 
	if (player_position[turn] >= N_BOARD) {
    	player_position[turn] = N_BOARD - 1; 
    	player_status[turn] = PLAYERSTATUS_END;
	}



		// step 2-4. coin
		coinResult = board_getBoardCoin(player_position[turn]);
   		if (coinResult > 0) {
        	player_coin[turn] += coinResult;
        	printf("%s collected %d coin(s)!\n", player_name[turn], coinResult);
    		}

	// step 2-5. end process
		if (player_position[turn] == N_BOARD - 1) {
        	player_status[turn] = PLAYERSTATUS_END;
        	printf("%s has reached the end!\n", player_name[turn]);
    	}

		turn = (turn + 1) % N_PLAYER;


		if (turn == 0 && gameAlreadyEnded == 0) { 
        	int shark_pos = board_stepShark(); 
        	checkDie(); 
    	}

    	if (game_end() == 1 && gameAlreadyEnded == 0) { 
        	gameAlreadyEnded = 1; 
        	int winner = getWinner();
        	int alive_players = getAlivePlayer();

        	printf("\nGAME END!!\n");
        	printf("%d players are alive!\n", alive_players);
        	if (winner != -1) {
            	printf("The winner is %s with %d coins!\n", player_name[winner], player_coin[winner]);
        	} else {
            	printf("No winner! All players are dead.\n");
        	}
    	}
} while (game_end() == 0);


// ----- EX. 6 : game end ------------

if (gameAlreadyEnded == 0) {
    gameAlreadyEnded = 1;
    int winner = getWinner();
    int alive_players = getAlivePlayer();

    printf("\nGAME END!!\n");
    printf("%d players are alive!\n", alive_players);
    if (winner != -1) {
        printf("The winner is %s with %d coins!\n", player_name[winner], player_coin[winner]);
    } else {
        printf("No winner! All players are dead.\n");
    }

}
    
    //step 3. game end process

    
// ----- EX. 2 : structuring ------------

    return 0;
}
