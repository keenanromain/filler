#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

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

int				main(void);
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
