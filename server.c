/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:43 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/08 22:26:34 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static char				message[BUFFER_SIZE];
	static int				i = 0;
	int						k ;

	k = 0;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			message[i] = c;
			while (message[k])
			{
				write(1, &message[k], 1);
				k++;
			}
			bit = 0;
			c = 0;
			i = 0;
			return ;
		}
		message[i] = c;
		bit = 0;
		c = 0;
		i++;
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
	signal(SIGUSR1, &ft_btoa);
	signal(SIGUSR2, &ft_btoa);
	while (argc == 1)
		pause();
	return (0);
}
