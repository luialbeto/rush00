#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    rush_width(int X, int altura, int Y)
{

    int width;
    
    width = 1;

    while(width <= X)
    {
        if(altura == 1 && (width == 1 || width == X))
        {
            ft_putchar('A');
        }
        else if (altura == Y && (width == 1 || width == X))
        {
            ft_putchar('C');
        }
        else if ((altura == 1 || altura == Y) && width != 1 && width != X)
        {
            ft_putchar('B');
        }
        else if (altura != 1 && altura != Y && (width == 1 || width == X))
        {
            ft_putchar('B');
        }
        else
        {
            ft_putchar(' ');
        }
        width++;
    }
}

/*void  rush_height(int Y)
{
    int altura;
    while (height <= Y)
    {
        if (height == Y)
        {
            ft_putchar('C');
        }
        else if(height != 0)
        {
            ft_putchar('B');
        }
        ft_putchar('\n');
        height++;
    }
}*/

void    rush(int X, int Y)
{
    int altura;
    altura = 1;

    while(altura != Y + 1)
    {
        rush_width(X, altura, Y);
        ft_putchar('\n');
        altura++;
    }
}

int main(void)
{
    rush(5,1);
}
