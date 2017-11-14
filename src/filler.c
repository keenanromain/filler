/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 21:52:11 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static char		*get_right_line(char *str)
{
	char	*line;

	while (get_next_line(0, &line) > -1)
	{
		if (ft_strstr(line, str))
			return (line);
	}
	return (NULL);
}

int				update_map(t_fil *f, char *line)
{
	int		row;
	int		col;

	row = -1;
	if (f->turn > 1)
		get_next_line(0, &line);
	while (row < f->n_rows)
	{
		get_next_line(0, &line);
		col = -1;
		while (line[++col])
		{
			if (line[col] == f->opp || line[col] == ft_tolower(f->opp))
				f->map[row + 1][col - 3] = f->opp_min;
			else if (line[col] == f->me || line[col] == ft_tolower(f->me))
				f->map[row + 1][col - 3] = f->me_max;
		}
		row++;
	}
	return (1);
}

void			init_map(t_fil *f)
{
	int		row;
	int		col;

	col = 0;
	f->map = malloc(sizeof(long long int *) * (f->n_rows + 100));
	ft_bzero(f->map, f->n_rows + 100);
	row = -1;
	while (++row < (f->n_rows + 100))
		f->map[row] = ft_memalloc(sizeof(long long) * (f->n_cols + 100));
	f->last_r = f->n_rows + 1;
	f->last_c = f->n_cols + 1;
	f->mid_r = f->n_rows & 1 ? f->last_r / 2 : f->last_r / 2 + 1;
	f->mid_c = f->n_cols & 1 ? f->last_c / 2 : f->last_c / 2 + 1;
	heat_fill(f);
	f->opp_min = -200000000000;
	f->me_max = f->map[f->mid_r][f->mid_c] + 1;
}

t_fil			*setup_map(char **line)
{
	t_fil	*f;
	char	**tab;

	f = ft_memalloc(sizeof(t_fil));
	f->turn = 1;
	f->opp = (ft_strstr(*line, "p1")) ? 'X' : 'O';
	f->me = f->opp == 'X' ? 'O' : 'X';
	f->opp_num = f->opp == 'O' ? 1 : 2;
	f->me_num = f->me == 'O' ? 1 : 2;
	*line = get_right_line("Plateau");
	tab = ft_strsplit(*line, ' ');
	f->n_rows = ft_atoi(tab[1]);
	f->n_cols = ft_atoi(tab[2]);
	init_map(f);
	return (f);
}

int				main(void)
{
	t_fil	*f;
	char	*line;
	int		i;

	line = get_right_line("$$$");
	f = setup_map(&line);
	while (update_map(f, line))
	{
		get_next_line(0, &line);
		init_piece(&line, f);
		config_piece(line, f);
		place_piece(f);
		reset_piece(f);
	}
	i = -1;
	if (f->map)
	{
		while (++i < (f->n_rows))
			free(f->map[i]);
		free(f->map);
	}
	return (0);
}
