/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 13:59:10 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void				init_piece(t_fil *f)
{
	int				row;
	char			*line;
	char			**tab;

	line = get_right_line("Piece");
	tab = ft_strsplit(line, ' ');
	f->piece_r = ft_atoi(tab[1]);
	f->piece_c = ft_atoi(tab[2]);
	ft_strdel(&line);
	ft_strdel(tab);
	f->piece = malloc(sizeof(long long *) * f->piece_r);
	ft_bzero(f->piece, f->piece_r);
	row = -1;
	while (++row < f->piece_r)
		f->piece[row] = ft_memalloc(sizeof(long long) * f->piece_c);
}

void				config_piece(t_fil *f)
{
	int				row;
	int				i;
	char			*line;

	row = -1;
	while (++row < f->piece_r)
	{
		i = -1;
		get_next_line(0, &line);
		while (line[++i])
			f->piece[row][i] = line[i] == '.' ? 0 : f->me_max;
		ft_strdel(&line);
	}
}

void				place_piece(t_fil *f)
{
	int				row;
	int				col;
	long long int	poss;
	long long		best;

	poss = 0;
	best = 0;
	row = -1;
	while (++row < f->last_r)
	{
		col = -1;
		while (++col < f->last_c)
		{
			if (verify_possible(f, row, col))
				poss = verify_value(f, row, col);
			if (MAX_2(poss, best) != best)
			{
				f->best_r = row;
				f->best_c = col;
				best = poss;
			}
		}
	}
}

void				clean_piece(t_fil *f)
{
	int				i;

	i = -1;
	if (f->piece)
	{
		while (++i < f->piece_r)
			free(f->piece[i]);
		f->best_r = 0;
		f->best_c = 0;
		free(f->piece);
	}
}
