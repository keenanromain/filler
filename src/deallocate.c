#include "filler.h"

void	empty_shape(t_fill *f)
{
	int j;

	j = 0;
	if (f->shape && f->shape[j])
	{
		while (j < f->h)
			free(f->shape[j++]);
		free(f->shape);
	}
}

void	empty_map(t_fill *f)
{
	int i;

	i = 0;
	if (f->map && f->map[i])
	{
		while (i < f->y)
			free(f->map[i++]);
		free(f->map);
	}
}

void	deallocate(t_fill *f)
{
	empty_shape(t_fill *f);
	empty_map(t_fill *f);
}
