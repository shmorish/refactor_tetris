#include "tetris.h"

typedef struct s_struct
{
	char	**array;
	int		size;
}			t_mino;

static const t_mino Tetromino[MINO_TYPES] =
{
	{
		// S mino
		.array = (char *[]) {
			(char []){0, 4, 4},
			(char []){4, 4, 0},
			(char []){0, 0, 0}
		},
		.size = 3
	},
	{
		// Z mino
		.array = (char *[]) {
			(char []){2, 2, 0},
			(char []){0, 2, 2},
			(char []){0, 0, 0}
		},
		.size = 3
	},
	{
		// T mino
		.array = (char *[]) {
			(char []){0, 3, 0},
			(char []){3, 3, 3},
			(char []){0, 0, 0}
		},
		.size = 3
	},
	{
		// J mino
		.array = (char *[]) {
			(char []){4, 0, 0},
			(char []){4, 4, 4},
			(char []){0, 0, 0}
		},
		.size = 3
	},
	{
		// L mino
		.array = (char *[]) {
			(char []){0, 0, 5},
			(char []){5, 5, 5},
			(char []){0, 0, 0}
		},
		.size = 3
	},
	{
		// O mino
		.array = (char *[]) {
			(char []){6, 6},
			(char []){6, 6}
		},
		.size = 2
	},
	{
		// I mino
		.array = (char *[]) {
			(char []){0, 0, 0, 0},
			(char []){7, 7, 7, 7},
			(char []){0, 0, 0, 0},
			(char []){0, 0, 0, 0}
		},
		.size = 4
	}
};

void	generate_mino(t_tetris *tetris)
{
	int	mino_index;

	mino_index = rand() % MINO_TYPES;
	tetris->mino_size = Tetromino[mino_index].size;
	tetris->mino_data = mino_dup(Tetromino[mino_index].array, tetris->mino_size);
	tetris->current_row = 0;
	tetris->current_col = rand() % (COLUMNS - tetris->mino_size + 1);
}
