#include "filler.h"

int		clean_up(t_fill *f)
{
	place_move(0, 0);
	deallocate(f);
	return (0);
}

int		dont_play(void)
{
	ft_putstr_fd("Well, this is embarrassing.\n", 2);
	return (-1);
}

int		play(t_fill *f)
{
	if (f->turn)
		fill_map(f);
	else if (!f->turn && (f->turn = 1) == 1)
		fill_map(f);
	allocate_shape(f);
	fill_shape(f);
	return (valid_move(f) ? play(f) : clean_up(f));
}

int		main(int ac, char **av)
{
	t_fill f;

	ft_memset(&f, 0, sizeof(f));
	f.type = 'X';
	if (ft_strstr(get_right_line("$$$"), "p1") && (f.turn = 1))
		f.type = '0';
	return (allocate_map(&f) ? play(&f) : dont_play());
}
