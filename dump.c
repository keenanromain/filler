#include "filler.h"

void	dump_shape(t_fil *f)
{
	int	i;

	i = -1;
	if (!f->shape)
		return ;
	while (++i < f->shape_h)
		ft_strdel(&f->shape[i]);
	ft_strdel(f->shape);
}

void	dump_map(t_fil *f)
{
	int	i;

	i = -1;
	if (!f->map)
		return ;
	while (++i < f->map_h)
		ft_strdel(&f->map[i]);
	ft_strdel(f->map);
}
