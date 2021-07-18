#include <unistd.h>

char	ft_putchar(char letter);

void	rush(int x, int y)
{

	/* 
	Para facilitar a implementacao, comecamos com um caso onde sem implementar nenhum codigo conseguimos resolver
	Pois em caso de (1,1) so sera printado a letra A
	*/

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

        int z;

		/*Inicio troca de valores
		Foi necessario a troca de valores onde são invertido os valores de x e y.
		Ou seja estavamos tratando os valores ao contrario na hora de printar na tela
		Por exemplo (5,1) era esperado:
		ABBBA
		E o nosso estava printando:
		A
		B
		B
		B
		C
		Ou seja estava invertido, o código abaixo faz a inversão desses valores para que possamos fazer as condições na hora dos whiles
		*/
        z = x;
        x = y;
        y = z;

		//No quesito linha foi necessario subtrair (-1) pelo fato que os valores começam por zero e ja ter uma letra printada devido a implementação por X.
		//Por exemplo, se mantessemos o valor original de Y, em um (5,1), seria printado algo parecido com:
		//ABBBBC
		//Onde e esperado apenas:
		//ABBBC
        y = y-1;

		while(x > coluna)
		{
			/*
			Observando os possiveis valores de saida podemos buscar um padrao. No caso partimos do caso mais facil para o dificil.
			Sabemos que quando a coluna for a primeira ou (coluna==0) preenchemos com a letra "A"
			*/
			if	(coluna == 0)
			{
				ft_putchar('A');
			}/* Caso nao caia na primeira condição, podemos tambem observar que o primeiro caractere da ultima linha sempre vai ser C.Colocamos (coluna + 1) pois os valores se iniciam de 0, seria ou necessario subtrair de x, ou incrementar em coluna para poder comparar e verificar se e a ultima linha*/

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

			else /*E caso nao caia em nenhuma das condicoes, ou seja, quando nao e a ultima nem a primeira linha nos printamos B */
			{
				ft_putchar('B');
			}

			/* Aqui temos uma segunda implementacao do loop while para preencher os valores na horizontal*/
			while(y > linha)
			{	
				/*Sabemos que quando e a primeira linha e o ultimo caractere devemos preencher com a Letra A, para isso
				utilizamos (linha + 1 ou y - 1) seguindo a mesma regra anterior pois os valores se iniciam de 0. Ou seja quando o valor
				da linha for igual ao parametro enviado pela funcao rush, significa que chegamos ao valor final da linha. E a outra verificao que fazemos
				e validar se o mesmo esta na primeira linha. Entao em resumo verificamos se o valor da linha equivale ao ultimo caractere e estamos na primeira coluna
				 */
                if(((linha+1) == y) && (coluna == 0)){
                    ft_putchar('A');
                }/* No segundo caso e bem parecido com o primeiro. Quando estivermos na ultima coluna e na ultima linha devemos printar C.
					Por isso nesse caso, linha+1 pois o indice comeca de 0 para verificar se estamos na ultima linha. E coluna + 1 para verificar se estamos na ultima coluna
				 */
				else if(((linha+1) == y) && (coluna+1 == x))
                {
                    ft_putchar('C');
                }/*
				Aqui chega o pulo do gato. Quando nao printamos A e nem C, temos que colocar B na tela salvo quando necessitamos inserir um caracter vazio.
				Mas nesse caso, como ja populamos o valor de coluna no primeiro While, necessitamos nos preocupar apenas com os valores que vem em seguida.
				Nesse caso verificamos que caso estamos em na primeira coluna, podemos printar B a vontade, o que nos protege se esta correto ou nao, e as condicoes acimas.
				Por isso podemos colocar essa coluna == 0. Caso nao seja essa primeira condicao, ou seja se estivermos na segunda linha, colocamos B tambem.
				Necessario debugar melhor essa condicao porque mesmo parando para entender ta dificil kkkkkkk
				 */
				else if((coluna==0) || (coluna+1 == x) || (linha+1 == y)){
                    ft_putchar('B');
                }else{
					// E caso nao cai em nenhuma das condicoes printamos um vazio.
                    ft_putchar(' ');
                }



				linha++;
			}

			ft_putchar('\n');
            linha = 0;
			coluna++;
		}
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
