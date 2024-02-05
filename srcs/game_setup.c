#include "tetris.h"

static void init_colors(void);

/*
	initscr() スクリーンを初期化
	noecho() 入力された文字を表示しない
	curs_set(0) カーソルを非表示
	timeout(1) getch()の待ち時間を1msに設定
	keypad(stdscr, TRUE) キーボードからの入力を受け付ける
	srand(time(NULL)) 乱数の初期化
*/
void	init_game(void)
{
	initscr();
	noecho();
	curs_set(0);
	timeout(1);
	keypad(stdscr, TRUE);
	srand(time(NULL));
	init_time();
	init_colors();
}

static void init_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

void	end_game(t_tetris *tetris)
{
	endwin();
	print_table(GAME_OVER, tetris, tetris->score);
}
