#include <unistd.h>

char	ft_putchar(char letter);

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{		
		ft_putchar('A');
		ft_putchar('\n');
	}
	else
	{
		int	linha;
		linha = 0;
		int coluna;
		coluna = 0;

		while(x > coluna)
		{
			if	(coluna == 0)
			{
				ft_putchar('A');
			}
			else if	(coluna + 1 == x)
			{
				ft_putchar('C');
			}
			else
			{
				ft_putchar('B');
			}
			while(y -1 > linha)
			{
				if(((coluna+1) == y) && (linha == 0))
                {
                ft_putchar('A');
                }
			else if(((coluna + 1) == y) && (linha + 1 == x))
            {
                ft_putchar('C');
            }else if((linha == 0) || (linha + 1 == y) || (coluna + 1 == x)){
                ft_putchar('B');
            }else{
                ft_putchar(' ');
            }
				linha++;
			}
			ft_putchar('\n');
			coluna++;
		}
	}
}
