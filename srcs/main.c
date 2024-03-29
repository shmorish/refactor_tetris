#include "tetris.h"

int	main(void)
{
	t_tetris	*tetris;

	tetris = init_struct();
	init_game();
	run_tetris_game(tetris);
	end_game(tetris);
	destroy_struct(tetris);
	return (0);
}

#ifdef DEBUG

__attribute__((destructor)) void end(void)
{
	system("leaks -q tetris > /dev/stderr");
}

#endif
