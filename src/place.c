#include "../inc/filler.h"

void	set_multipliers(t_heat **h)
{
	int	row;
	int	col;

	row = -1;
	while (++row < (*h)->last_row)
	{
		col = -1;
		while (++col < (*h)->last_col)
		{
			if (col >= (*h)->mid_col / 2 && col <= (*h)->mid_col / 2 + (*h)->mid_col && \
			row >= (*h)->mid_row / 2  && row <= (*h)->mid_row / 2 + (*h)->mid_row)
				(*h)->map[row][col] *= 10;
		//	if (enemy_nearby(f, h, col, row, 5))
		//		h->map[row][col] *= 8;
		//	else if (enemy_nearby(f, h, col, row, 10))
		//		h->map[row][col] *= 5;
		}
	}
}

static int	legit_move(t_fil *f, int i_y, int j_x, int touches)
{
	int		y;
	int		x;
	int		a;
	int		b;

	y = -1;
	a = i_y - 1;
	while (++y < f->shape_h && ++a < f->map_h)
	{
		x = -1;
		b = j_x - 1;
		while (++x < f->shape_w && ++b < f->map_w)
			if (f->shape[y][x] == '*' && f->map[a][b] != '.')
				if (++touches > 1)
					return (0);
	}
	return (1);
}


int		place_heat(t_fil *f, t_heat **h)
{
	int x;
	int y;
	long long int pos;
	long long int best;

	x = -1;
	pos = 0;
	best = 0;
	while (++x < (*h)->last_row)
	{
		y = -1;
		while (++y < (*h)->last_col)
		{
			if (legit_move(f, x, y, 0)) //where I am probably having a problem
			{
				pos = (*h)->map[x][y];
				if (MAX(pos, best) != best)
				{
					(*h)->best_y = y;
					(*h)->best_x = x;
					best = pos;
				}
			}
		}
	}
	if (best == 0)
		return (0);
	return (print_move((*h)->best_y, (*h)->best_x, 0, f, *h));
}
