#include <cstdio>
#include <windows.h>

using namespace std;

//functions
int starting_page();
int game();
int endgame();

//variables
int innings = 1;
int top_bottom = 0;//innings top bottom //Top:0 Bottom:1
int key = 0;
int score[2] = { 0 };
int pitch[2] = { 0 };
int total_strike[2] = { 0 };
int total_ball[2] = { 0 };
int batter_strike = 0;
int batter_ball = 0;
int inning_out = 0;
int temp = 0;

int main() 
{
	starting_page();
	return 0;
}

int starting_page()
{
	system("cls");
	printf(" _______ _______ _______ ______   _______   _______ __   __ _______ _______ _______ \n");
	printf("|       |       |       |    _ | |       | |       |  | |  |       |       |       |\n");
	printf("|  _____|       |   _   |   | || |    ___| |  _____|  |_|  |    ___|    ___|_     _|\n");
	printf("| |_____|       |  | |  |   |_||_|   |___  | |_____|       |   |___|   |___  |   |  \n");
	printf("|_____  |      _|  |_|  |    __  |    ___| |_____  |       |    ___|    ___| |   |  \n");
	printf(" _____| |     |_|       |   |  | |   |___   _____| |   _   |   |___|   |___  |   |  \n");
	printf("|_______|_______|_______|___|  |_|_______| |_______|__| |__|_______|_______| |___|  \n");

	printf("\n[1]Start New Game\n");
	
	printf("\nEnter the number: ");
	scanf_s("%d", &key);
	switch (key) 
	{
		case 1:
			game();
			break;
		default:
			starting_page();
	}
	return 0;
}

int game()
{
	if (top_bottom == 0 && innings > 9)
	{
		if (score[0] != score[1])
		{
			endgame();
		}
	}
	system("cls");
	printf(" _______ _______ _______ _______ _______ _______ ___     ___     \n");
	printf("|  _    |   _   |       |       |  _    |   _   |   |   |   |    \n");
	printf("| |_|   |  |_|  |  _____|    ___| |_|   |  |_|  |   |   |   |    \n");
	printf("|       |       | |_____|   |___|       |       |   |   |   |    \n");
	printf("|  _   ||       |_____  |    ___|  _   ||       |   |___|   |___ \n");
	printf("| |_|   |   _   |_____| |   |___| |_|   |   _   |       |       |\n");
	printf("|_______|__| |__|_______|_______|_______|__| |__|_______|_______|\n");
	printf("\nHOME: %d\n", score[1]);
	printf("AWAY: %d\n", score[0]);

	if (top_bottom == 0)
		printf("Top of %d inning\n", innings);
	else if (top_bottom == 1)
		printf("Bottom of %d inning\n", innings);

	printf("Total Pitch: %d   Total Strike: %d   Total Ball: %d\n", pitch[top_bottom], total_strike[top_bottom], total_ball[top_bottom]);
	printf("Strike: %d   Ball:%d   Out:%d\n\n\n", batter_strike, batter_ball, inning_out);
	printf("[1]Strike\n");
	printf("[2]Ball\n");
	printf("[3]Hit\n");
	printf("[4]Out\n");
	printf("[5]Add Score\n");
	printf("\nEnter the key:");
	scanf_s("%d", &key);
	switch (key)
	{
		case 1:
			pitch[top_bottom]++;
			total_strike[top_bottom]++;
			batter_strike++;
			if (batter_strike == 3) {
				inning_out++;
				batter_strike = 0;
			}
			if (inning_out == 3)
			{
				batter_ball = 0;
				batter_strike = 0;
				inning_out = 0;
				if (top_bottom == 0)
				{
					top_bottom++;
				}
				else if (top_bottom == 1)
				{
					top_bottom--;
					innings++;
				}
			}
			break;
		case 2:
			pitch[top_bottom]++;
			total_ball[top_bottom]++;
			batter_ball++;
			if (batter_ball == 4) {
				batter_strike = 0;
				batter_ball = 0;
			}
			if (inning_out == 3)
			{
				batter_ball = 0;
				batter_strike = 0;
				inning_out = 0;
				if (top_bottom == 0)
				{
					top_bottom++;
				}
				else if (top_bottom == 1)
				{
					top_bottom--;
					innings++;
				}
			}
			break;
		case 3:
			pitch[top_bottom]++;
			total_strike[top_bottom]++;
			batter_strike = 0;
			batter_ball = 0;
			if (inning_out == 3)
			{
				batter_ball = 0;
				batter_strike = 0;
				inning_out = 0;
				if (top_bottom == 0)
				{
					top_bottom++;
				}
				else if (top_bottom == 1)
				{
					top_bottom--;
					innings++;
				}
			}
			break;
		case 4:
			pitch[top_bottom]++;
			inning_out++;
			batter_ball = 0;
			batter_strike = 0;
			total_strike[top_bottom]++;
			if (inning_out == 3)
			{
				batter_ball = 0;
				batter_strike = 0;
				inning_out = 0;
				if (top_bottom == 0)
				{
					top_bottom++;
				}
				else if (top_bottom == 1)
				{
					top_bottom--;
					innings++;
				}
			}
			break;
		case 5:
			printf("Add Score: ");
			scanf_s("%d", &temp);
			score[top_bottom] += temp;
			temp = 0;
			if (inning_out == 3)
			{
				batter_ball = 0;
				batter_strike = 0;
				inning_out = 0;
				innings++;
				if (top_bottom == 0)
				{
					top_bottom++;
				}
				else if (top_bottom == 1)
				{
					top_bottom--;
				}
			}
			break;
	}
	game();
	return 0;
}

int endgame()
{
	system("cls");
	printf(" _______ _______ __   __ _______   _______ __    _ ______  \n");
	printf("|       |   _   |  |_|  |       | |       |  |  | |      | \n");
	printf("|    ___|  |_|  |       |    ___| |    ___|   |_| |  _    |\n");
	printf("|   | __|       |       |   |___  |   |___|       | | |   |\n");
	printf("|   ||  |       |       |    ___| |    ___|  _    | |_|   |\n");
	printf("|   |_| |   _   | ||_|| |   |___  |   |___| | |   |       |\n");
	printf("|_______|__| |__|_|   |_|_______| |_______|_|  |__|______| \n");
	printf("\nHOME: %d\n", score[1]);
	printf("AWAY: %d\n", score[0]);
	printf("Home total pitch: %d Strike: %d Ball: %d\n", pitch[1], total_strike[1], total_ball[1]);
	printf("Away total pitch: %d Strike: %d Ball: %d", pitch[0], total_strike[0], total_ball[0]);
	return 0;
}