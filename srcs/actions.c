#include "tetris.h"

static void	rotate(t_tetris *tetris, int size)
{
	t_tetris	*tmp;
	int			opposite_index;

	tmp = dup_mino_data(tetris);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			opposite_index = size - 1 - j;
			tetris->mino_data[i][j] = tmp->mino_data[opposite_index][i];
		}
	}
	destroy_struct(tmp);
}

void	rotate_mino(t_tetris *tetris, t_tetris *tmp)
{
	rotate(tmp, tetris->mino_size);
	if (can_mino_move(tmp, tmp->mino_data))
		rotate(tetris, tetris->mino_size);
}

void	move_mino(t_tetris *tetris, t_tetris *tmp, int direction)
{
	tmp->current_col += direction;
	if (can_mino_move(tmp, tmp->mino_data))
		tetris->current_col += direction;
}

static void	update_table(t_tetris *tetris)
{
	int	height_index;
	int	width_index;
	int updated_row;
	int updated_col;

	height_index = 0;
	while (height_index < tetris->mino_size)
	{
		width_index = 0;
		while (width_index < tetris->mino_size)
		{
			updated_row = tetris->current_row + height_index;
			updated_col = tetris->current_col + width_index;
			if (tetris->mino_data[height_index][width_index])
				tetris->table[updated_row][updated_col] = tetris->mino_data[height_index][width_index];
			width_index++;
		}
		height_index++;
	}
}

static void	generate_new_mino(t_tetris *tetris)
{
	free_array(tetris->mino_data);
	tetris->mino_data = NULL;
	generate_mino(tetris);
}

void	move_down(t_tetris *tetris, t_tetris *tmp)
{
	tmp->current_row++;
	if (can_mino_move(tmp, tmp->mino_data))
	{
		tetris->current_row++;
	}
	else
	{
		update_table(tetris);
		tetris->score += clear_mino(tetris);
		generate_new_mino(tetris);
		if (!can_mino_move(tetris, tetris->mino_data))
		{
			tetris->game_on = false;
		}
	}
}
