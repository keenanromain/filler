#include "filler.h"

int		clean_up(t_fill *f)
{
	place_move(0, 0);
	deallocate(f);
	return (0);
}

int		dont_play(void)
{
	ft_putstr_fd("Umm, this is awkward.\n", 2);
	return (-1);
}

int		play(t_fill *f)
{
	if (get_right_line("01234"))
		fill_map(f);
	allocate_shape(f);
	fill_shape(f);
	if (valid_move(f)) 
	{
		get_right_line("Plateau");
		empty_shape(f);
		return (play(f));
	}
	return (clean_up(f));
}

int		main(int ac, char **av)
{
	t_fill f;

	ft_memset(&f, 0, sizeof(f));
	f.c = 'X';
	if (ft_strstr(get_right_line("$$$"), "p1"))
		f.c = '0';
	return (allocate_map(&f) ? play(&f) : dont_play());
}
