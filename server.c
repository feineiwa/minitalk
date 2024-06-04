/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:43 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/04 22:14:00 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_atob(int sig)
{
	static int	bit;
	static int	i;

	printf("%d", sig);
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
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
	while (argc == 1)
	{
		signal(SIGUSR1, ft_atob);
		signal(SIGUSR2, ft_atob);
		pause();
	}
	return (0);
}
