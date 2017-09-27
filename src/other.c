#include "filler.h"

static t_env	*map_reader(int fd, t_env *env)
{
	char *line;
	int i;
	int j;

	i = 0;
	j = i;
	while (get_next_line(fd, &line))
	{
		if (!i)
			j = ft_strlen(line);
		i++;
		ft_strdel(&line);
	}
	env->map = (char **)ft_memalloc(sizeof(char *) * (i * j));
	i = -1;
	while (get_next_line(fd, &line))
	{
		env->map[++i] = ft_strdup(line);
		ft_printf(line);
		ft_strdel(&line);
	}
	return (env);
}

int				main(int ac, char **av)
{
	int		fd;
	t_env	*env;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (perror("open failed"));
	env = map_reader(fd, (env = (t_env *)ft_memalloc(sizeof(t_env))));
}
