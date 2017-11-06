#include "filler.h"

int		print_move(int y, int x, int done, t_fil *f)
{
	ft_printf("%d %d\n", y, x);
	if (done)
	{
		dump_shape(f);
		dump_map(f);
		return (0);
	}
	return (1);
}

int		play_game(t_fil *f)
{
	char *line;

	while ((line = get_right_line("01234")))
	{
		pop_map(f);
		alloc_shape(f);
		pop_shape(f);
		if (!make_move(f))
			break ;
		dump_shape(f);
		ft_strdel(&line);
	}
	return (print_move(0, 0, 1, f));
}


char	*get_right_line(char *s)
{
	char	*line;

	while (get_next_line(0, &line) > -1)
		if (ft_strstr(line, s))
			return (line);
	return (NULL);
}

int		main(void)
{
	t_fil	f;
	char	*line;

	f.my_char = 'O';
	line = get_right_line("$$$");
	if (!(ft_strstr(line, "p1")))
		f.my_char = 'X';
	ft_strdel(&line);
	if (alloc_map(&f))
		return (play_game(&f));
	ft_putstr_fd("Map Error.\n", 2);
	return (-1);
}
