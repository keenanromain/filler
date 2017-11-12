/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 13:58:54 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

char		*get_right_line(char *str)
{
	char	*line;

	while (get_next_line(0, &line) > -1)
	{
		if (ft_strstr(line, str))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int			update_map(t_fil *f)
{
	int		row;
	int		col;
	char	*line;

	row = -2;
	while (++row < f->n_rows)
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
		ft_strdel(&line);
	}
	return (1);
}

int			main(void)
{
	char	*line;
	t_fil	*f;

	line = get_right_line("$$$");
	f = set_struct(line);
	flow_tl(flow_tr(flow_bl(flow_br(set_map(f)))));
	while (update_map(f))
	{
		init_piece(f);
		config_piece(f);
		place_piece(f);
		ft_printf("%d %d\n", f->best_r - 1, f->best_c - 1);
		clean_piece(f);
		get_next_line(0, &line);
	}
	return (0);
}
