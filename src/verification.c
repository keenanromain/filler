/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 13:59:32 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int					verify_possible(t_fil *f, int map_r, int map_c)
{
	int				touches;
	int				x;
	int				y;
	int				tmp;

	touches = 0;
	tmp = map_c;
	x = -1;
	while (++x < f->piece_r)
	{
		map_c = tmp - 1;
		y = -1;
		while (++y < f->piece_c && ++map_c)
		{
			if (f->map[map_r][map_c] < 0 && f->piece[x][y] == f->me_max)
				return (0);
			if (f->map[map_r][map_c] == f->me_max)
				if (f->piece[x][y] == f->me_max)
					touches++;
		}
		map_r++;
	}
	return (touches == 1 ? 1 : 0);
}

long long			verify_value(t_fil *f, int map_row, int map_col)
{
	int				piece_row;
	int				piece_col;
	long long int	heat;
	int				col_start;

	piece_row = 0;
	heat = 0;
	col_start = map_col;
	piece_row = -1;
	while (++piece_row < f->piece_r)
	{
		map_col = col_start;
		piece_col = -1;
		while (++piece_col < f->piece_c)
		{
			if (f->piece[piece_row][piece_col] == f->me_max)
				heat += f->map[map_row][map_col];
			map_col += 1;
		}
		map_row += 1;
	}
	return (heat);
}
