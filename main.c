/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:28:53 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/03 21:40:26 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary(char *text)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (text[i] != '\0')
	{
		c = text[i];
		j = 7;
		while (j >= 0)
		{
			if (c & (1 << j))
				printf("1");
			else
				printf("0");
			j--;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	binary(argv[1]);
	return (0);
}