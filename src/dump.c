#include "filler.h"

void	dump_shape(t_fill *f)
{
	int j;

	j = -1;
	if (f->shape)
	{
		while (++j < f->h)
			free(f->shape[j]);
		free(f->shape);
	}
}

void	dump_map(t_fill *f)
{
	int i;

	i = -1;
	if (f->map)
	{
		while (++i < f->y)
			free(f->map[i]);
		free(f->map);
	}
}
