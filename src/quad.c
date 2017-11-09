/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 23:33:39 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int		fill_q1(t_heat ***h, int num)
{
	int row;
	int col;

	row = -1;
	while (++row <= (**h)->mid_row)
	{
		col = -1;
		while (++col <= (**h)->mid_col)
			(**h)->map[row][col] = num;
	}
	return (1);
}

static int		fill_q2(t_heat ***h, int num)
{
	int row;
	int col;

	row = -1;
	while (++row <= (**h)->mid_row)
	{
		col = (**h)->mid_col - 1;
		while (++col < (**h)->last_col)
			(**h)->map[row][col] = num;
	}
	return (1);
}

static int		fill_q3(t_heat ***h, int num)
{
	int row;
	int col;

	row = (**h)->mid_row - 1;
	while (++row < (**h)->last_row)
	{
		col = -1;
		while (++col <= (**h)->mid_col)
			(**h)->map[row][col] = num;
	}
	return (1);
}

static int		fill_q4(t_heat ***h, int num)
{
	int row;
	int col;

	row = (**h)->mid_row - 1;
	while (++row < (**h)->last_row)
	{
		col = (**h)->mid_col -1;
		while (++col < (**h)->last_col)
			(**h)->map[row][col] = num;
	}
	return (1);
}

void	fill_quads(t_heat **h)
{
	int i;

	i = 5;
	while (--i)
	{
		best_quad(&h);
		if ((*h)->best_q == (*h)->q1 && fill_q1(&h, i))
			(*h)->q1 = 0;
		else if ((*h)->best_q == (*h)->q2 && fill_q2(&h, i))
			(*h)->q2 = 0;
		else if ((*h)->best_q == (*h)->q3 && fill_q3(&h, i))
			(*h)->q3 = 0;
		else if ((*h)->best_q == (*h)->q4 && fill_q4(&h, i))
			(*h)->q4 = 0;
	}
}
