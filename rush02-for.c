#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c);

int through_lines(int a, int b)
{
    int i;
    int j;

    //I or B are equal to lines
    //J or A are equal to columns
    // A B B A
    // B     B
    // C B B C

    a = a-1;

    for(i=0; i < b; i++)
    {
        if(i == 0){
            ft_putchar('A');
        }else if(i+1 == b){
            ft_putchar('C');
        }else{
            ft_putchar('B');
        }
        
        for(j=0; j < a; j++)
        {   
            if(((j+1) == a) && (i == 0)){
                ft_putchar('A');
            }else if(((j+1) == a) && (i+1 == b))
            {
                ft_putchar('C');
            }else if((i==0) || (i+1 == b) || (j+1 == a)){
                ft_putchar('B');
            }else{
                ft_putchar(' ');
            }
        }


        ft_putchar('\n');
    }
}


int rush(int a, int b)
{
    if(a == 1 && b == 1)
    {
        ft_putchar('A');
        ft_putchar('\n');
    }else{
        through_lines(a,b);
    }
       
}

