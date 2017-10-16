#include "filler.h"

int		priority_or_not(t_fill *f);
int		check_before_placing(t_fill *f);
int		set(t_fill *f, int valid);

int		valid_move(t_fill *f)
{
	int y;
	int x;

	y = -1;
	while (++y < f->map_h)
	{
		x = -1;
		while (++x < f->map_w)
		{
			// come up with some cool algo
			// you're going to need to check to see if current
			// board position touches an already placed char
			// of yours. Beyond that maybe implement some
			// strategy that evaluates the enemy's position
			// in an attempt to choke them out and pigeon-holing
			// them into a small quadrant of the board. Such a
			// thing can look like this:
			if (f->map[y][x] == f->c && priority_or_not(f))
			{
				if (set(f, check_before_placing(f)))
					ft_printf("%d %d\n", y, x);
				else
				{
					ft_printf("Issue placing piece onto board");
					continue ;
				}
				return (1);
			}
			// where the function priority or not does the
			// heavy lifting for creating the quadrants
			// and determining the proper prioritization of a
			// move or not. The placing functions would do as
			// their namesake implies before finally outputting
			// the best coordinates that it can come up with.
			// If the placing functions return false, there is
			// a problem somewhere and my printf will notify me.
			// The else statement shouldn't exist though when this
			// project is done.
		}
	}
	return (0);
}
