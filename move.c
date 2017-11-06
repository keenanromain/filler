#include "filler.h"

int	check_piece(t_fil *f, int y_i, int x_i)
{
	int	intersect;
	int	y;
	int	x;
	int	x_c;

	intersect = 0;
	y = 0;
	while (y < f->shape_h && y_i < f->map_h)
	{
		x = 0;
		x_c = x_i;
		while (x < f->shape_w && x_c < f->map_w)
		{
			if (f->shape[y][x] == '*' && f->map[y_i][x_c] != '.')
				intersect++;
			if (intersect == 2)
				return (0);
			x++;
			x_c++;
		}
		y++;
		y_i++;
	}
	return (1);
}

int	place_piece(t_fil *f, int y_i, int x_i)
{
	int	y;
	int	x;
	int	x_c;
	int	y_c;

	y = 0;
	while (y < f->shape_h)
	{
		x = 0;
		while (x < f->shape_w)
		{
			if (f->shape[y][x] == '*')
			{
				x_c = x_i - x;
				y_c = y_i - y;
				if (x_c >= 0 && y_c >= 0 && x_c + f->shape_w - 1 < f->map_w &&
					y_c + f->shape_h - 1 < f->map_h &&
					check_piece(f, y_c, x_c))
					return (print_move(y_i - y, x_i - x, 0, f));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	make_move(t_fil *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->map_h)
	{
		j = -1;
		while (++j < f->map_w)
			if (f->map[i][j] == f->my_char && place_piece(f, i, j))
				return (1);
	}
	return (0);
}
