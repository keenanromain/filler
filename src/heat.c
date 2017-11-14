/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 21:52:11 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void	top_left(t_fil *f)
{
	int row;
	int col;

	row = 1;
	while (row <= f->mid_r)
	{
		col = 1;
		while (col <= f->mid_c)
		{
			f->map[row][col] = q1(row, col, f);
			col++;
		}
		row++;
	}
}

static void	top_right(t_fil *f)
{
	int row;
	int col;

	row = 1;
	while (row <= f->mid_r)
	{
		col = f->last_c - 1;
		while (col > f->mid_c)
		{
			f->map[row][col] = q2(row, col, f);
			col--;
		}
		row++;
	}
}

static void	bottom_left(t_fil *f)
{
	int row;
	int col;

	row = f->last_r - 1;
	while (row > f->mid_r)
	{
		col = 1;
		while (col <= f->mid_c)
		{
			f->map[row][col] = q3(row, col, f);
			col++;
		}
		row--;
	}
}

static void	bottom_right(t_fil *f)
{
	int row;
	int col;

	row = f->last_r - 1;
	while (row > f->mid_r)
	{
		col = f->last_c - 1;
		while (col > f->mid_c)
		{
			f->map[row][col] = q4(row, col, f);
			col--;
		}
		row--;
	}
}

void		heat_fill(t_fil *f)
{
	int row;
	int col;

	row = 1;
	while (row < (f->n_rows + 2))
	{
		col = 1;
		while (col < (f->n_cols + 2))
		{
			if (row == 1 || col == 1)
				f->map[row][col] = -200000000000;
			else if (row == f->last_r || col == f->last_c)
				f->map[row][col] = -200000000000;
			else
				f->map[row][col] = 1;
			col++;
		}
		row++;
	}
	top_left(f);
	top_right(f);
	bottom_left(f);
	bottom_right(f);
}
