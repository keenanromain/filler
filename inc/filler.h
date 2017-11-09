/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/08 23:36:03 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define	MSG1 " - \033[01;31mFatal Error Using Malloc.\033[0m\n"
# define	MSG2 " - \033[01;31mTerminating Program\033![0m\n"
# define	MSG3 " - \033[01;31m./filler runs with the Filler VM.\033[0m\n"
# define	MSG4 " - \033[01;31m./filler_vm in resources for more.\033[0m\n"
#define		MAX(a, b) ((a > b) ? a : b )

# include "../libft/libft.h"

typedef struct	s_heat
{
	long long int		**map;		//heat map stored as long long for max number of values
	int					start_row;	// initial row in heat map. I will prob delete this
	int					start_col; // initial col in heat map. I will prob delete this
	int					mid_row; // mid point in row determined by halving the total number of nums, plus one if even
	int					mid_col; // mid point in col determined by halving the total number of cols, plus one if even
	int					last_row; // total number of rows and last row
	int					last_col; // total number of cols and last col
	int					q1;			// total number of empty chars in quad 1
	int					q2;			// total number of empty chars in quad 2
	int					q3;			// total number of empty chars in quad 3
	int					q4;			// total number of empty chars in quad 4
	int					best_q;		// current quadrant with highest number of empty char
	int					best_y;		// best y coordinate found in heat map (highest long long int value)
	int					best_x;		// best x coordinate found in heat map (highest long long int value)
}				t_heat;

typedef struct	s_fil
{
	char	my_char;				// which character I am
	int		map_w;					// map width
	int		map_h;					// map height
	int		shape_w;				// shape width
	int		shape_h;				//shape height
	char	**map;					//map initially read in character form (prior to conversation into heat map)
	char	**shape;				// the shape that I am given. May need a corresponding t_heat value to translate into
}				t_fil;

int				main(int ac, char **av);
int				throw_error(int errno);
char			*get_right_line(char *s);
void			dump_shape(t_fil *f);
void			dump_map(t_fil *f);
void			dump_heat(t_heat *h);
int				play_game(t_fil *f);
int				make_move(t_fil *f, t_heat *h);
int				print_move(int y, int x, int done, t_fil *f, t_heat *h);
int				alloc_shape(t_fil *f);
int				alloc_map(t_fil *f);
long long int	**alloc_heat(t_fil *f);
void			pop_shape(t_fil *f);
void			pop_map(t_fil *f);
void			build_heat(t_fil *f, t_heat *h);
void			fill_quads(t_heat **h);
int				max_quad(t_heat ***h);
void			best_quad(t_heat ***h);
int				start_heat(t_fil *f, t_heat *h);
int				place_heat(t_fil *f, t_heat **h);
void			set_multipliers(t_heat **h);

#endif
