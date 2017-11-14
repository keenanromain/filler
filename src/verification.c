/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 21:48:04 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			verify_valid(t_fil *f, int map_x, int map_y)
{
	int	touches;
	int	p_x;
	int	p_y;
	int	tmp;

	touches = 0;
	tmp = map_y;
	p_x = -1;
	while (++p_x < f->piece_r)
	{
		map_y = tmp - 1;
		p_y = -1;
		while (++p_y < f->piece_c && ++map_y)
		{
			if (f->map[map_x][map_y] < 0 && f->piece[p_x][p_y] == f->me_max)
				return (0);
			if (f->map[map_x][map_y] == f->me_max)
				if (f->piece[p_x][p_y] == f->me_max)
					touches++;
		}
		map_x++;
	}
	return (touches == 1 ? 1 : 0);
}

long long	verify_ideal(t_fil *f, int map_x, int map_y)
{
	int				p_x;
	int				p_y;
	long long int	ideal;
	int				tmp;

	ideal = 0;
	tmp = map_y;
	p_x = -1;
	while (++p_x < f->piece_r)
	{
		map_y = tmp - 1;
		p_y = -1;
		while (++p_y < f->piece_c && ++map_y)
		{
			if (f->piece[p_x][p_y] == f->me_max)
				ideal += f->map[map_x][map_y];
		}
		map_x++;
	}
	return (ideal);
}
