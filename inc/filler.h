/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/09/25 19:52:22 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define MSG1 " - \033[01;31mFatal Error Using Malloc.\033[0m\n"
# define MSG2 " - \033[01;31mTerminating Program\033![0m\n"
# define MSG3 " - \033[01;31m./filler runs with the Filler VM.\033[0m\n"
# define MSG4 " - \033[01;31m./filler_vm in resources for more.\033[0m\n"

# include "../libft/libft.h"

typedef struct	s_fil
{
	char	my_char;
	int		map_w;
	int		map_h;
	int		shape_w;
	int		shape_h;
	char	**map;
	char	**shape;
}				t_fil;

int				main(int ac, char **av);
int				throw_error(int errno);
char			*get_right_line(char *s);
void			dump_shape(t_fil *f);
void			dump_map(t_fil *f);
int				play_game(t_fil *f);
int				make_move(t_fil *f);
int				print_move(int y, int x, int done, t_fil *f);
int				alloc_shape(t_fil *f);
int				alloc_map(t_fil *f);
void			pop_shape(t_fil *f);
void			pop_map(t_fil *f);

#endif
