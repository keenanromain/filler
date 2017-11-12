/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 13:59:23 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

long long int	border(int row, int col, t_fil *f)
{
	if (row == 0 || col == 0 || row == f->last_r || col == f->last_c)
		return (-200000000000);
	return (1);
}

t_fil			*set_map(t_fil *f)
{
	int			row;
	int			col;

	row = -1;
	while (++row <= f->last_r)
	{
		col = -1;
		while (++col <= f->last_c)
			f->map[row][col] = border(row, col, f);
	}
	return (f);
}

t_fil			*init_map(t_fil *f)
{
	int			row;

	f->map = malloc(sizeof(long long int *) * (f->n_rows + 100));
	ft_bzero(f->map, f->n_rows + 100);
	row = -1;
	while (++row < (f->n_rows + 100))
		f->map[row] = ft_memalloc(sizeof(long long) * (f->n_cols + 100));
	f->last_r = f->n_rows + 1;
	f->last_c = f->n_cols + 1;
	f->mid_r = f->n_rows & 1 ? f->last_r / 2 : f->last_r / 2 + 1;
	f->mid_c = f->n_cols & 1 ? f->last_c / 2 : f->last_c / 2 + 1;
	f->opp_min = -200000000000;
	f->me_max = f->map[f->mid_r][f->mid_c] + 1;
	return (f);
}

t_fil			*set_struct(char *line)
{
	t_fil		*f;
	char		**tab;

	f = ft_memalloc(sizeof(t_fil));
	f->opp = (ft_strstr(line, "p1")) ? 'X' : 'O';
	f->me = f->opp == 'X' ? 'O' : 'X';
	f->opp_num = f->opp == 'O' ? 1 : 2;
	f->me_num = f->me == 'O' ? 1 : 2;
	ft_strdel(&line);
	line = get_right_line("Plateau");
	tab = ft_strsplit(line, ' ');
	f->n_rows = ft_atoi(tab[1]);
	f->n_cols = ft_atoi(tab[2]);
	ft_strdel(&line);
	ft_strdel(tab);
	return (init_map(f));
}
