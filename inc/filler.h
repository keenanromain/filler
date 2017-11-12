/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:09:46 by kromain           #+#    #+#             */
/*   Updated: 2017/11/12 14:00:30 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define MAX_2(a, b) ((a > b) ? a : b)
# define MAX_3(a, b, c) ((a > b) ? MAX_2(a, c) : MAX_2(b, c))

typedef struct		t_fil
{
	int				n_rows;
	int				n_cols;
	int				start_r;
	int				start_c;
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
}					t_fil;


int					main(void);
t_fil				*set_struct(char *line);
char				*get_right_line(char *s);
int					update_map(t_fil *f);
t_fil				*init_map(t_fil *f);
t_fil				*set_map(t_fil *f);
long long int		border(int row, int col, t_fil *f);
t_fil				*flow_br(t_fil *f);
t_fil				*flow_bl(t_fil *f);
t_fil				*flow_tr(t_fil *f);
void				flow_tl(t_fil *f);
long long int		q1(int row, int col, t_fil *f);
long long int		q2(int row, int col, t_fil *f);
long long int		q3(int row, int col, t_fil *f);
long long int		q4(int row, int col, t_fil *f);
void				init_piece(t_fil *f);
void				config_piece(t_fil *f);
void				place_piece(t_fil *f);
int					verify_possible(t_fil *f, int map_row, int map_col);
long long int		verify_value(t_fil *f, int map_row, int map_col);
void				clean_piece(t_fil *f);
//void				clean_map(t_fil *f);

#endif
