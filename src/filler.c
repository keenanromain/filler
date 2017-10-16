#include "filler.h"

char	*get_right_line(char *s)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, s))
			return (line);
		ft_strdel(&line);
	}
	return (NULL);
}

int		done(t_fill *f)
{
	ft_printf("%d %d \n", 0, 0);
	dump_shape(t_fill *f);
	dump_map(t_fill *f);
	return (0);
}

int		dont_play(void)
{
	ft_putstr_fd("Umm, this is awkward.\n", 2);
	return (-1);
}

int		play(t_fill *f)
{
	while (1)
	{
		if (get_right_line("01234"))
			fill_map(f);
		alloc_shape(f);
		pop_shape(f);
		if (valid_move(f))
		{
			get_right_line("Plateau");
			dump_shape(f);
			continue ;
		}
		break ;
	}
	return (done(f));
}
/*
int		play(t_fill *f)
{
	if (get_right_line("01234"))
		fill_map(f);
	alloc_shape(f);
	pop_shape(f);
	if (valid_move(f))
	{
		get_right_line("Plateau");
		dump_shape(f);
		return (play(f));
	}
	return (done(f));
}
*/
int		main(int ac, char **av)
{
	t_fill f;

	ft_memset(&f, 0, sizeof(f));
	f.c = 'X';
	if (ft_strstr(get_right_line("$$$"), "p1"))
		f.c = '0';
	return (allocate_map(&f) ? play(&f) : dont_play());
}
