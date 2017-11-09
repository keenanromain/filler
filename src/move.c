/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 23:41:47 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
/*
static int	check_shape(t_fil *f, int i_y, int j_x, int touches)
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

static int	check_bounds(t_fil *f, int i_y, int j_x)
{
	return ((i_y >= 0 && j_x >= 0 && i_y + f->shape_h - 1  < f->map_h \
			&& j_x + f->shape_w - 1  < f->map_w) ? 1 : 0);
}

static int	place_naive(t_fil *f, int i, int j)
{
	int		y;
	int		x;

	y = -1;
	while (++y < f->shape_h)
	{
		x = -1;
		while (++x < f->shape_w)
			if (f->shape[y][x] == '*')
				if (check_bounds(f, i - y, j - x))
					if (check_shape(f, i - y, j - x, 0))
						return (print_move(i - y, j - x, 0, f, NULL));
	}
	return (0);
}
*/
int			make_move(t_fil *f, t_heat *h)
{
	//int		i;
	//int		j;

	if (start_heat(f, h)) //perhaps have an && bzero(h) to clean the struct prior to re-using
		return (1);
	//i = -1;
	//while (++i < f->map_h)
	//{
	//	j = -1;
	//	while (++j < f->map_w)
	//		if (f->map[i][j] == f->my_char)
	//			if (place_naive(f, i, j))
	//				return (1);
	//}
	return (0);
}
