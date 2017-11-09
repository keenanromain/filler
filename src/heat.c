/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 23:36:03 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		max_quad(t_heat ***h)
{
	int max;

	max = MAX((**h)->q1, (**h)->q2);
	max = MAX(max, (**h)->q3);
	max = MAX(max, (**h)->q4);
	return (max);
}

void	best_quad(t_heat ***h)
{
	int max;

	max= max_quad(h);
	if (max == (**h)->q1)
		(**h)->best_q = 1;
	else if (max == (**h)->q2)
		(**h)->best_q = 2;
	else if (max == (**h)->q3)
		(**h)->best_q = 3;
	else
		(**h)->best_q = 4;
}

static void	count_empty(t_fil *f, t_heat **h, int height, int width)
{
	int row;
	int col;

	row = -1;
	while (++row < height)
	{
		col = -1;
		while (++col < width)
		{
			if (f->map[row][col] == '.')
			{
				if (row <= (*h)->mid_row && col <= (*h)->mid_col)
					(*h)->q1++;
				else if (row <= (*h)->mid_row && col > (*h)->mid_col)
					(*h)->q2++;
				else if (row > (*h)->mid_row && col <= (*h)->mid_col)
					(*h)->q3++;
				else
					(*h)->q4++;
			}
		}
	}
}

static void	setup_heat(t_fil *f, t_heat **h)
{
	(*h)->last_row = f->map_w;
	(*h)->last_col = f->map_h;
	(*h)->mid_row = f->map_w & 1 ? (*h)->last_row / 2 : (*h)->last_row / 2 + 1;
	(*h)->mid_col = f->map_h & 1 ? (*h)->last_col / 2 : (*h)->last_col / 2 + 1;
	(*h)->start_row = 0;
	(*h)->start_col = 0;
}

//setup_heat to determine the number of empty characters in each quad
//build_heat to do the math for calculating values based on enemy position

int		start_heat(t_fil *f, t_heat *h)
{

	setup_heat(f, &h);
	count_empty(f, &h, f->map_h, f->map_w);
	fill_quads(&h);
	set_multipliers(&h);
	if (place_heat(f, &h))
		return (1);
	return (0);
}
