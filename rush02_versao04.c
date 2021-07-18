#include <unistd.h>

void	ft_putchar(char c);

int	check_entrance(int x, int y)
{
	if (x < 0 || y < 0)
	{
		return (1);
	}
	else if ((x >= 0 && y >= 0) || (x <= 9 && y <= 9))
	{
		return (0);
	}
	return (0);
}

void	rush_width(int x, int y, int h)

{
	int	w;

	w = 1;
	while (w <= x)
	{
		if (h == 1 && (w == 1 || w == x))
		{
			ft_putchar('A');
		}
		else if (h == y && (w == 1 || w == x))
		{
			ft_putchar('C');
		}
		else if (((h == 1 || h == y)
				&& w != 1 && w != x)
			|| (h != 1 && h != y && (w == 1 || w == x)))
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		w++;
	}
}

void	rush(int x, int y)
{
	int	h;

	if (check_entrance(x, y) == 0)
	{
		h = 1;
		while (h != y + 1)
		{
			rush_width(x, y, h);
			ft_putchar('\n');
			h++;
		}
	}
	else
	{
		ft_putchar('F');
		ft_putchar('\n');
	}
}

// variables -> h = height (altura)
// variables -> w = width (largura)