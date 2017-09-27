/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/14/08 26:45:21 by kromain           #+#    #+#             */
/*   Updated: 2017/09/26 18:02:52 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include <errno.h>
# include <stdbool.h>

typedef struct		s_meta
{
	bool			trend; //if opponent has passed a sufficient distance from his starting point, he is trending
	bool			beeline; // cut off opponent, if possible, when he is trending
	int				q_attack; // what quadrant to care about - based on trend and bee line
	int				danger; //not sure what to do about this one or kill. Could be used for protection
	int				kill;
}					t_meta;

typedef struct		s_env
{
	char			**map;
	int				start_me;
	int				start_u;
	int				last_me;
	int				last_u;
	bool			my_turn;
	unsigned int	total_me;
	unsigned int	total_u;
	unsigned int	quad_me;
	unsigned int	quad_u;
	t_meta			*meta;
	int				quad_1; //amount of empty space in quad 1. same for below...
	int				quad_2;
	int				quad_3;
	int				quad_4;
	int				valid;
	int				invalid;
}					t_env;

#endif
