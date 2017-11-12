/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 15:49:41 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_fil	*flow_br(t_fil *f)
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
	return (f);
}

t_fil	*flow_bl(t_fil *f)
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
	return (f);
}

t_fil	*flow_tr(t_fil *f)
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
	return (f);
}

void	flow_tl(t_fil *f)
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
