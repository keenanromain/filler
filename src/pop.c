#include "filler.h"

void	pop_shape(t_fill *f)
{
	char *line;
	int i;
	int j;

	i = -1;
	while (++i < f->h)
	{
		get_next_line(0, &line);
		j = -1;
		while (++j < f->w)
			f->shape[i][j] = line[j];
		//ft_strdel(&line)
	}
}

int		alloc_shape(t_fill *f)
{
	char *line;
	char **s;
	int i;

	if ((line = get_right_line("Piece")))
	{
		s = ft_strsplit(line, ' ');
		f->h = ft_atoi(s[1]);
		f->w = ft_atoi(s[2]);
		if (!(f->shape = (char **)malloc(sizeof(char **) * f->h)))
			return (0);
		i = -1;
		while (++i < f->h)
			if (!(f->shape[i] = (char *)malloc(sizeof(char *) * f->w)))
				return (0);
		//ft_strdel(&line);
		//ft_strdel(s);
		return (1);
	}
	return (0);
}

void	pop_map(t_fill *f)
{
	char *line;
	char **s;
	int i;
	int j;

	i = -1;
	while (++i < f->y)
	{
		get_next_line(0, &line);
		s = ft_strsplit(line, ' ')
		j = -1;
		while (++j < f->x)
			f->mp[i][j] = s[i][j];
		//ft_strdel(&line);
		//ft_strdel(s);
	}
}

int		alloc_map(t_fill *f)
{
	char	*line;
	char	**s;
	int		i;

	if ((line = get_right_line("Plateau")))
	{
		s = ft_strsplit(line, ' ');
		f->y = ft_atoi(s[1]);
		f->x = ft_atoi(s[2]);
		if (!(f->map = (char **)malloc(sizeof(char **) * f->y)))
			return (0);
		i = -1;
		while (++i < f->y)
			if (!(f->map[i] = (char *)malloc(sizeof(char *) * f->x)))
				return (0);
		//ft_strdel(&line);
		//ft_strdel(s);
		return (1);
	}
	return (0);
}
