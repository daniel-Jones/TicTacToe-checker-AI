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

/*
 *  board checks 
 * these will return the count of occurances of PLAYER
 */
int vertical_check(char (*board)[ROWS][COLUMNS], char player);
int horizontal_check(char (*board)[ROWS][COLUMNS], char player); 
int diagonal_check_ltr(char (*board)[ROWS][COLUMNS], char player); /* left to right check */
int diagonal_check_rtl(char (*board)[ROWS][COLUMNS], char player); /* right to left check */

/* copy board function, copies contents of board1 to board2 */
void copy_board(char (*board1)[ROWS][COLUMNS], char (*board2)[ROWS][COLUMNS]);

int main(int argc, char *argv[])
{
	Grid board = {CROSS, FREECELL, FREECELL,
		FREECELL, CROSS, FREECELL,
		FREECELL, FREECELL, CROSS};	
	Grid test_board;
	copy_board(&board, &test_board);
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
	if (vertical_check(board, player) == ROWS)
		return TRUE;
	if (horizontal_check(board, player) == COLUMNS)
		return TRUE;
	if (diagonal_check_ltr(board, player) == ROWS)
		return TRUE;
	if (diagonal_check_rtl(board, player) == ROWS)
		return TRUE;
	return FALSE;
}

int vertical_check(char (*board)[ROWS][COLUMNS], char player)
{
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
				return vc;
		}
	}
	return vc;
}

int horizontal_check(char (*board)[ROWS][COLUMNS], char player)
{
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
				return hc;
		}
	}
	return hc;
}

int diagonal_check_ltr(char (*board)[ROWS][COLUMNS], char player)
{
	int dc;
	/* diagonal check, left to right */
	for (int x = 0; x < COLUMNS; x++)
	{
		dc = 0;
		for (int i = 0; i < ROWS; i++)
		{
			if ((*board)[i][i] == player)
				dc++;
			if (dc == ROWS)
				return dc;
		}
	}
	return dc;
}

int diagonal_check_rtl(char (*board)[ROWS][COLUMNS], char player)
{
	/* diagonal check, right to left */
	int dc = 0;
	for (int x = 0; x < COLUMNS; x++)
	{
		dc = 0;
		for (int i = ROWS; i > 0; i--)
		{
			if ((*board)[x][x] == player)
				dc++;
			if (dc == ROWS)
				return dc;
		}
	}
	return dc;
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

void copy_board(char (*board1)[ROWS][COLUMNS], char (*board2)[ROWS][COLUMNS])
{
	/* copies content of board1 to board 2 */
	for (int x = 0; x < COLUMNS; x++)
	{
		for (int i = 0; i < ROWS; i++)
		{
			(*board2)[x][i] = (*board1)[x][i];
		}
	}
}
