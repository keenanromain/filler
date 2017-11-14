/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 20:57:43 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define MAX_2(a, b) ((a > b) ? a : b)
# define MAX_3(a, b, c) ((a > b) ? MAX_2(a, c) : MAX_2(b, c))

typedef struct		s_fil
{
	int				n_rows;
	int				n_cols;
	int				last_r;
	int				last_c;
	int				mid_r;
	int				mid_c;
	long long int	**map;
	long long int	**piece;
	int				piece_r;
	int				piece_c;
	int				best_r;
	int				best_c;
	char			opp;
	char			me;
	int				opp_num;
	int				me_num;
	long long int	opp_min;
	long long int	me_max;
	int				turn;
}					t_fil;

int					main(void);
t_fil				*setup_map(char **line);
int					update_map(t_fil *f, char *line);
void				init_map(t_fil *f);
void				heat_fill(t_fil *f);
long long int		q1(int x, int y, t_fil *f);
long long int		q2(int x, int y, t_fil *f);
long long int		q3(int x, int y, t_fil *f);
long long int		q4(int x, int y, t_fil *f);
void				init_piece(char **line, t_fil *f);
void				config_piece(char *line, t_fil *f);
void				place_piece(t_fil *f);
void				reset_piece(t_fil *f);
int					verify_valid(t_fil *f, int map_x, int map_y);
long long int		verify_ideal(t_fil *f, int map_x, int map_y);

#endif
