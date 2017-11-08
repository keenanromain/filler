/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/10/15 19:52:22 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	dump_shape(t_fil *f)
{
	int	i;

	i = -1;
	if (!f->shape)
		return ;
	while (++i < f->shape_h)
		ft_strdel(&f->shape[i]);
	ft_strdel(f->shape);
}

void	dump_map(t_fil *f)
{
	int	i;

	i = -1;
	if (!f->map)
		return ;
	while (++i < f->map_h)
		ft_strdel(&f->map[i]);
	ft_strdel(f->map);
}
