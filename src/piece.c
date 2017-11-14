/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 22:10:35 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	init_piece(char **line, t_fil *f)
{
	int	i;
	int	row;

	i = 6;
	f->piece_r = ft_atoi(&line[0][i]);
	i += ft_digitnum(f->piece_r) + 1;
	f->piece_c = ft_atoi(&line[0][i]);
	f->piece = malloc(sizeof(long long *) * f->piece_r);
	ft_bzero(f->piece, f->piece_r);
	row = -1;
	while (++row < f->piece_r)
		f->piece[row] = ft_memalloc(sizeof(long long) * f->piece_c);
}

void	config_piece(char *line, t_fil *f)
{
	int row;
	int i;

	row = -1;
	while (++row < f->piece_r)
	{
		get_next_line(0, &line);
		i = -1;
		while (line[++i])
		{
			if (line[i] == '.')
				f->piece[row][i] = 0;
			else
				f->piece[row][i] = f->me_max;
		}
	}
}

void	place_piece(t_fil *f)
{
	int				map_x;
	int				map_y;
	long long int	poss;
	long long int	best;

	poss = 0;
	best = 0;
	map_x = -1;
	while (++map_x < f->last_r)
	{
		map_y = -1;
		while (++map_y < f->last_c)
		{
			if (verify_valid(f, map_x, map_y))
				poss = verify_ideal(f, map_x, map_y);
			if (MAX_2(poss, best) != best)
			{
				f->best_r = map_x;
				f->best_c = map_y;
				best = poss;
			}
		}
	}
	ft_printf("%d %d\n", f->best_r - 1, f->best_c - 1);
}

void	reset_piece(t_fil *f)
{
	int	i;

	i = -1;
	if (f->piece)
	{
		while (++i < f->piece_r)
			free(f->piece[i]);
		f->best_r = 0;
		f->best_c = 0;
		free(f->piece);
	}
	f->turn++;
}
