/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 18:12:59 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

long long int		q1(int x, int y, t_fil *f)
{
	long long int **map;

	map = f->map;
	if (x == 1)
		return (map[x][y] + MAX_2(map[x][y - 1], map[x + 1][y - 1]));
	if (x == f->mid_r)
		return (10 * (map[x][y] + MAX_2(map[x][y - 1], map[x - 1][y - 1])));
	return (map[x][y] + \
			MAX_3(map[x][y - 1], map[x + 1][y - 1], map[x - 1][y - 1]));
}

long long int		q2(int x, int y, t_fil *f)
{
	long long int **map;

	map = f->map;
	if (x == 1)
		return (map[x][y] + MAX_2(map[x][y + 1], map[x + 1][y + 1]));
	if (x == f->mid_r)
		return (10 * (map[x][y] + MAX_2(map[x][y + 1], map[x - 1][y + 1])));
	return (map[x][y] + \
			MAX_3(map[x][y + 1], map[x + 1][y + 1], map[x - 1][y + 1]));
}

long long int		q3(int x, int y, t_fil *f)
{
	long long int **map;

	map = f->map;
	if (x == f->last_r - 1)
		return (map[x][y] + MAX_2(map[x][y - 1], map[x - 1][y - 1]));
	if (x == f->mid_r + 1)
		return (map[x][y] + MAX_2(map[x][y - 1], map[x + 1][y - 1]));
	return (map[x][y] + \
			MAX_3(map[x][y - 1], map[x - 1][y - 1], map[x + 1][y - 1]));
}

long long int		q4(int x, int y, t_fil *f)
{
	long long int **map;

	map = f->map;
	if (x == f->last_r - 1)
		return (map[x][y] + MAX_2(map[x][y + 1], map[x - 1][y + 1]));
	if (x == f->mid_r + 1)
		return (map[x][y] + MAX_2(map[x][y + 1], map[x + 1][y + 1]));
	return (map[x][y] + \
			MAX_3(map[x][y + 1], map[x - 1][y + 1], map[x + 1][y + 1]));
}
