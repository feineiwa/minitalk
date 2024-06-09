/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:02:57 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/09 23:31:38 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

// int	g_ack_received;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		printf("Message has been received by server!\n");
	// (void)sig;
	// g_ack_received = 1;
}

void	ft_send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		// g_ack_received = 0;
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		// while (!g_ack_received)
		usleep(50);
	}
}

void	ft_send_message(int pid, char *message)
{
	while (*message)
		ft_send_char(pid, *message++);
	signal(SIGUSR1, ack_handler);
	ft_send_char(pid, '\0');
}

void	error_handling(int pid, char **argv)
{
	if (!pid)
	{
		printf("%s is invalid pid\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (kill(pid, 0) == -1)
	{
		printf("no process for the given PID\n");
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[2]) == 0)
	{
		printf("Empty message, nothing to sent!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	
	if (argc != 3)
	{
		printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	error_handling(pid, argv);
	ft_send_message(pid, argv[2]);
	return (0);
}