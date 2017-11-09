/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 23:49:24 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			print_move(int y, int x, int done, t_fil *f, t_heat *h)
{
	ft_printf("%d %d\n", y, x);
	if (done)
	{
		dump_shape(f);
		dump_map(f);
		dump_heat(h);
		return (0);
	}
	return (1);
}

int			play_game(t_fil *f)
{
	t_heat	h;
	long long int	**heat;
	char	*line;

	ft_memset(&h, sizeof(t_heat), 0);
	if (!(heat = alloc_heat(f)))
		return (throw_error(1));
	h.map = heat;
	while ((line = get_right_line("01234")))
	{
		pop_map(f);
		if (!alloc_shape(f))
			return (throw_error(1));
		pop_shape(f);
		if (!make_move(f, &h))
			break ;
		dump_shape(f);
		ft_strdel(&line);
	}
	return (print_move(0, 0, 1, f, &h));
}

char		*get_right_line(char *s)
{
	char	*line;

	while (get_next_line(0, &line) > -1)
	{
		if (ft_strstr(line, s))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int			throw_error(int errno)
{
	if (errno)
	{
		ft_putstr_fd(MSG1, 2);
		ft_putstr_fd(MSG2, 2);
	}
	else
	{
		ft_putstr_fd(MSG3, 2);
		ft_putstr_fd(MSG4, 2);
	}
	return (-1);
}

int			main(int ac, char **av)
{
	t_fil	f;
	char	*line;

	if (ft_strcmp(av[0], "./filler") == 0 && ac == 1) // this check isn't working
		return (throw_error(0));
	f.my_char = 'O';
	line = get_right_line("$$$");
	if (!(ft_strstr(line, "p1")))
		f.my_char = 'X';
	ft_strdel(&line);
	return (alloc_map(&f) ? play_game(&f) : throw_error(1));
}