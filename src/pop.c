/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 22:34:11 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	pop_shape(t_fil *f)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < f->shape_h)
	{
		get_next_line(0, &line);
		j = -1;
		while (++j < f->shape_w)
			f->shape[i][j] = line[j];
		ft_strdel(&line);
	}
}

int		alloc_shape(t_fil *f)
{
	int		i;
	char	*line;
	char	**tab;

	line = get_right_line("Piece");
	tab = ft_strsplit(line, ' ');
	f->shape_h = ft_atoi(tab[1]);
	f->shape_w = ft_atoi(tab[2]);
	if (!(f->shape = (char **)malloc(sizeof(char *) * f->shape_h)))
		return (-1);
	i = -1;
	while (++i < f->shape_h)
		if (!(f->shape[i] = (char *)malloc(sizeof(char) * f->shape_w)))
			return (-1);
	ft_strdel(&line);
	ft_strdel(tab);
	return (1);
}

void	pop_map(t_fil *f)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = -1;
	while (++i < f->map_h)
	{
		get_next_line(0, &line);
		tab = ft_strsplit(line, ' ');
		j = -1;
		while (++j < f->map_w)
			f->map[i][j] = tab[1][j];
		ft_strdel(&line);
		ft_strdel(tab);
	}
}

int		alloc_map(t_fil *f)
{
	int		i;
	char	*line;
	char	**tab;

	line = get_right_line("Plateau");
	tab = ft_strsplit(line, ' ');
	f->map_h = ft_atoi(tab[1]);
	f->map_w = ft_atoi(tab[2]);
	if (!(f->map = (char **)malloc(sizeof(char *) * f->map_h)))
		return (-1);
	i = -1;
	while (++i < f->map_h)
		if (!(f->map[i] = (char *)malloc(sizeof(char) * f->map_w)))
			return (-1);
	ft_strdel(&line);
	ft_strdel(tab);
	return (1);
}

long long int	**alloc_heat(t_fil *f)
{
	int i;
	long long int **heat;

	if (!(heat = (long long int **)malloc(sizeof(long long int *) * f->map_h)))
		return ((void *)0);
	i = -1;
	while (++i < f->map_h)
	{
		if (!(heat[i] = (long long int *)malloc(sizeof(long long int) * f->map_w)))
			return ((void *)0);
		ft_bzero(heat[i], f->map_h);
	}
	return (heat);
}
