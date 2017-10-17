#include "filler.h"

int		done(t_fill *f, int first, int second)
{
	ft_printf("%d %d\n", first, second);
	dump_shape(t_fill *f);
	dump_map(t_fill *f);
	return (0);
}

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

int		play(t_fill *f)
{
	while (1)
	{
		if (get_right_line("01234"))
			pop_map(f);
		alloc_shape(f);
		pop_shape(f);
		if (valid_move(f))
		{
			get_right_line("Plateau"); // might need to convert this into if statement for checking
			dump_shape(f);
			continue ;
		}
		break ;
	}
	return (done(f, 0, 0));
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
	f.me = 'X';
	if (ft_strstr(get_right_line("$$$"), "p1"))
		f.me = 'O';
	f.you = (f.me == 'X') ? 'O' : 'X' ;
	if (allocate_map(&f))
		return (play(&f));
	ft_putstr_fd("Umm, this is awkward.\n", 2);
	return (-1);
}
