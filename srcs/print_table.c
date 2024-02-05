#include "tetris.h"

static int	switch_print(const bool situation, const char * restrict format, ...)
{
	int		result = 0;
	va_list	args;

	va_start(args, format);
	if (situation == GAME_ON)
		result = vwprintw(stdscr, format, args);
	else if (situation == GAME_OVER)
		result = vprintf(format, args);
	va_end(args);
	return (result);
}

static void	print_title(void)
{
	int	space_len_until_title;

	space_len_until_title = COLUMNS - strlen(GAME_TITLE) / 2 - 1;
	clear();
	for (int i = 0; i < space_len_until_title; i++)
		switch_print(GAME_ON, " ");
	switch_print(GAME_ON, "%s\n", GAME_TITLE);
}

static void	switch_color(const char c)
{
	if (c == 0)
		attron(COLOR_PAIR(8));
	else
		attron(COLOR_PAIR(c));
}

static void	end_color(void)
{
	attroff(COLOR_PAIR(0));
}

static void print_table_with_falling_mino(const bool situation, const t_tetris *tetris, int score, char **empty_map_with_mino)
{
	for (int row_i = 0; row_i < ROWS; row_i++)
	{
		for (int col_i = 0; col_i < COLUMNS; col_i++)
		{
			switch_color(tetris->table[row_i][col_i] + empty_map_with_mino[row_i][col_i]);
			switch_print(situation, "%c ", (tetris->table[row_i][col_i] || empty_map_with_mino[row_i][col_i]) ? MAP_FULL : MAP_EMPTY);
			end_color();
		}
		switch_print(situation, "\n");
	}
	if (situation == GAME_OVER)
		switch_print(situation, "\nGame over!\n");
	switch_print(situation, "\nScore: %lu\n", score);
}

static char	**store_mino(const t_tetris *tetris, int row, int col)
{
	char	**empty_map_with_mino;

	empty_map_with_mino = init_table();
	put_mino_data_to_table(empty_map_with_mino, (const char **)tetris->mino_data, \
		row, col, tetris->mino_size);
	return (empty_map_with_mino);
}

void	print_table(const bool situation, const t_tetris *tetris, int score)
{
	char	**empty_map_with_mino;

	empty_map_with_mino = store_mino(tetris, tetris->current_row, tetris->current_col);
	if (situation == GAME_ON)
		print_title();
	print_table_with_falling_mino(situation, tetris, score, empty_map_with_mino);
	free_array(empty_map_with_mino);
}
