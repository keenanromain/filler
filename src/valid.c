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
			if (f->map[y][x] == f->me && priority_or_not(f))
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

/* High-Level Strategy overview
 *	1. Read and populate board
 *	2. Split board into quadrants (talk to Jarvis about this if proving tricky)
 *	3. Draw definsive line through the initially empty quadrants, to siphon off any
 *		potential gains that the opponent can have from my half of the board. Best
 *		way to do this is connect to the closest wall first, before going after the 
 *		futherest one.
 *	4. Push into opponent's side of the board. My line should prevent him from venturing my territory
 *		so we'd duke it out for ground in his territory
 *	5. Retreat into my territory once there is no more room in opponents territory. In a perfect world,			I'd have the line drawn with a large amount of land unexploited in my side of the board. Only 
 *		when there is no more land in his zone, I can exploit the empty land that I siphoned off
 *
 *	Current thoughts
 *		Depending on how fast the line drawing algorithm is, I might need to protect only a quadrant
 *		rather than half the board (ideally) or slightly less than that. I'd be entirely vulnerable
 *		if the opponent can sneak behind my definsive line and exploit the land I'm trying to siphon
 *		off. The line drawing algorithm should be the hardest part to build, will think more on it.
 * */
