#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ROWS 3
#define COLUMNS 3
#define FREECELL ' '
#define NOUGHT 'O'
#define CROSS 'X'

typedef char Grid[ROWS][COLUMNS];

int is_won(char (*board)[ROWS][COLUMNS], char player);
void print_board(char (*board)[ROWS][COLUMNS]);

int main(int argc, char *argv[])
{
	   Grid board = {NOUGHT, CROSS, CROSS,
			CROSS,  FREECELL, CROSS,
			CROSS, NOUGHT, NOUGHT};	
	print_board(&board);
	if (is_won(&board, NOUGHT))
		printf("Noughts won.\n");
	else if (is_won(&board, CROSS))
		printf("Crosses won.\n");
	else
		printf("No winners.\n");
	return 0;
}

int is_won(char (*board)[ROWS][COLUMNS], char player)
{
	/* here we see if the board has been won by the given player
	 * how:
	 * check horizontal
	 * check vertical
	 * check diagonal
	 */
	int hc;
	/* horizontal check */
	for (int x = 0; x < ROWS; x++)
	{
		hc = 0;
		for (int i = 0; i < COLUMNS; i++)
		{
			if ((*board)[x][i] == player)
				hc++;
		if (hc == COLUMNS)
			return TRUE;
		}
	}
	int vc;
	/* vertical check */
	for (int x = 0; x < COLUMNS; x++)
	{
		vc = 0;
		for (int i = 0; i < ROWS; i++)
		{
			if ((*board)[i][x] == player)
				vc++;
			if (vc == ROWS)
				return TRUE;
		}
	}
	int dc;
	/* diagonal check */
	for (int x = 0; x < COLUMNS; x++)
	{
		dc = 0;
		for (int i = 0; i < ROWS; i++)
		{
			if ((*board)[i][i] == player)
				dc++;
			if (dc == ROWS)
				return TRUE;
		}
	}
	return FALSE;
}

void print_board(char (*board)[ROWS][COLUMNS])
{
	for (int x = 0; x < COLUMNS; x++)
	{
		for (int i = 0; i < ROWS; i++)
		{
			printf("%c", (*board)[x][i]);
		}
		printf("\n");
	}
}
