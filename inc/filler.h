#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_fill
{
	int			turn;
	char		**map;
	char		**shape;
	char		type;
	int			h; // height for shape;
	int			w; // width for shape;
	int			y; // height for map;
	int			x; // width for map;

}				t_fill;
