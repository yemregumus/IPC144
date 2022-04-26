/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Yunus Gumus
	ID     : 150331197
	Email  : ygumus@myseneca.ca
	Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_PATH_LENGTH 70
#define MULTIPLY_GAME_PATH 5
#define MIN_GAME_PATH 10
#define MAX_GAME_PATH 70

struct PlayerInfo
{
	int lives;
	char symbol;
	int treasuresFound;
	char positionHistory[MAX_PATH_LENGTH];
};

struct GameInfo
{
	int movesLeft;
	int pathLength;
	int bombs[MAX_PATH_LENGTH];
	int treasures[MAX_PATH_LENGTH];
};

int main(void)
{
	int flag = 1, i;
	struct PlayerInfo player;
	struct GameInfo game;
	char symbol;
	int lives;
	int path_length;
	int maxMoves, nextMove = 0;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");
	printf("\nPLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &symbol);
	player.symbol = symbol;
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &lives);
		if (lives >= 1 && lives <= 10)
		{
			player.lives = lives;
			flag = 0;
		}
		else
			printf("     Must be between 1 and 10!\n");
	} while (flag);
	player.treasuresFound = 0;
	printf("Player configuration set-up is complete\n");



	printf("\nGAME Configuration\n");
	printf("------------------\n");
	flag = 1;
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &path_length);
		if (path_length % MULTIPLY_GAME_PATH == 0 && path_length >= MIN_GAME_PATH && path_length <= MAX_GAME_PATH)
		{
			game.pathLength = path_length;
			flag = 0;
		}
		else
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
	} while (flag);
	for (i = 0; i < game.pathLength; i++)
		player.positionHistory[i] = '-';



	flag = 1;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &maxMoves);
		if (maxMoves >= 3 && maxMoves <= 15)
		{
			game.movesLeft = maxMoves;
			flag = 0;
		}
		else
			printf("    Value must be between 3 and 15\n");
	} while (flag);



	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
		scanf("%d %d %d %d %d", &game.bombs[(5 * i)], &game.bombs[(5 * i) + 1], &game.bombs[(5 * i) + 2], &game.bombs[(5 * i) + 3], &game.bombs[(5 * i) + 4]);
	}
	printf("BOMB placement set\n");



	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
	for (i = 0; i < (game.pathLength / 5); i++)
	{
		printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
		scanf("%d %d %d %d %d", &game.treasures[(5 * i)], &game.treasures[(5 * i) + 1], &game.treasures[(5 * i) + 2], &game.treasures[(5 * i) + 3], &game.treasures[(5 * i) + 4]);
	}
	printf("TREASURE placement set\n");



	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.symbol);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\nGame:\n");
	printf("   Path Length: %d\n", game.pathLength);
	printf("   Bombs      : ");
	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.treasures[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");



	do
	{
		if (nextMove > 0)
		{
			printf("  ");
			for (i = 1; i <= game.pathLength; i++)
			{
				if (i == nextMove)
					printf("%c", player.symbol);
				else
					printf(" ");
			}
			printf("\n");
		}
		else
			printf("\n");



		printf("  ");
		for (i = 0; i < game.pathLength; i++)
			printf("%c", player.positionHistory[i]);
		printf("\n");



		printf("  ");
		for (i = 1; i <= game.pathLength; i++)
		{
			if (i % 10 == 0)
				printf("%d", i / 10);
			else
				printf("|");
		}
		printf("\n");



		printf("  ");
		for (i = 1; i <= game.pathLength; i++)
			printf("%d", i % 10);



		printf("\n+---------------------------------------------------+\n");
		printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n", player.lives, player.treasuresFound, game.movesLeft);
		printf("+---------------------------------------------------+\n");



		flag = 1;
		do
		{
			printf("Next Move [1-%d]: ", game.pathLength);
			scanf("%d", &nextMove);
			if (nextMove >= 1 && nextMove <= game.pathLength)
				flag = 0;
			else
				printf("  Out of Range!!!\n");
		} while (flag);



		if (player.positionHistory[nextMove - 1] == '&' || player.positionHistory[nextMove - 1] == '!' || player.positionHistory[nextMove - 1] == '$' || player.positionHistory[nextMove - 1] == '.')
			printf("\n===============> Dope! You've been here before!\n\n");
		else if (game.bombs[nextMove - 1] > 0 && game.treasures[nextMove - 1] > 0)
		{
			printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			player.positionHistory[nextMove - 1] = '&';
			game.movesLeft--;
			player.lives--;
			player.treasuresFound++;
		}
		else if (game.bombs[nextMove - 1] > 0)
		{
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
			player.positionHistory[nextMove - 1] = '!';
			game.movesLeft--;
			player.lives--;
		}
		else if (game.treasures[nextMove - 1] > 0)
		{
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			player.positionHistory[nextMove - 1] = '$';
			game.movesLeft--;
			player.treasuresFound++;
		}
		else
		{
			printf("\n===============> [.] ...Nothing found here... [.]\n\n");
			player.positionHistory[nextMove - 1] = '.';
			game.movesLeft--;
		}
	} while (player.lives > 0 && game.movesLeft > 0);



	if (player.lives == 0)
		printf("No more LIVES remaining!\n\n");
	if (game.movesLeft == 0)
		printf("No more MOVES remaining!\n\n");



	printf("  ");
	for (i = 1; i <= game.pathLength; i++)
	{
		if (i == nextMove)
			printf("%c", player.symbol);
		else
			printf(" ");
	}
	printf("\n");



	printf("  ");
	for (i = 0; i < game.pathLength; i++)
		printf("%c", player.positionHistory[i]);
	printf("\n");



	printf("  ");
	for (i = 1; i <= game.pathLength; i++)
	{
		if (i % 10 == 0)
			printf("%d", i / 10);
		else
			printf("|");
	}
	printf("\n");



	printf("  ");
	for (i = 1; i <= game.pathLength; i++)
		printf("%d", i % 10);



	printf("\n+---------------------------------------------------+\n");
	printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n", player.lives, player.treasuresFound, game.movesLeft);
	printf("+---------------------------------------------------+\n");



	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");
	printf("\nYou should play again and try to beat your score!");
	return 0;
}