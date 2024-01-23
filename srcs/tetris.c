#include <libc.h>

typedef struct s_tetris
{
	char **map;
	int row;
	int col;
}	t_tetris;

t_tetris *init_tetris(void)
{
	t_tetris *tetris;

	tetris->map = init_map();

	return	tetris;
}

int do_tetris(t_tetris *tetris)
{
	int final_score;

	final_score = 0;
	while (1)
	{
		print_map(tetris->map);
		move_tetris(tetris);
	}
	return (final_score);
}

int main(void)
{
	t_tetris *tetris;
	int final_score;

	/* 初期化する
	・開始時間を取得する
	・空盤面を生成する
	*/
	tetris = init_tetris();

	/* ゲームを実行する
	繰り返す
	{
		・マップを表示させる
		・入力（WASD）を受け付ける
		・入力をもとにコマンドを実行する
		・時間経過でものを落とす
	}
	*/
	final_score = do_tetris(tetris);

	/* ゲームを終了する */
	end_tetris(tetris, final_score);
}