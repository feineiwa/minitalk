/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:43 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/05 23:00:47 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit;
	static char	c;
	int			i;

	// printf("mandeha");
	// exit(EXIT_SUCCESS);
	c = 0;
	bit = 8;
	i = 0;
	// printf("%d", sig);
	if (sig == SIGUSR1)
	{
		c |= (1 << (bit - 1 - i));
	}
	else if (sig == SIGUSR2)
	{
		c &= ~(1 << (bit - 1 - i));
	}
	i++;
	if (i == 8 && c)
	{
		printf("%c\n", c);
		i = 0;
		c = 0;
	}
	// exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, &ft_btoa);
	signal(SIGUSR2, &ft_btoa);
	while (argc == 1)
	{
		sleep(1);
	}
}
