/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:02:57 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/23 13:25:57 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	ft_send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		while (!g_ack_received)
			usleep(100);
		bit--;
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	while (*message)
		ft_send_char(pid, *message++);
	ft_send_char(pid, '\0');
}

void	error_handling(int pid, char **argv)
{
	if (!pid)
	{
		ft_printf("%s is invalid pid\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (kill(pid, 0) == -1)
	{
		ft_printf("no process for the given PID\n");
		exit(EXIT_FAILURE);
	}
	if (strlen(argv[2]) == 0)
	{
		ft_printf("Empty message, nothing to sent!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	error_handling(pid, argv);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_send_message(pid, argv[2]);
	return (0);
}
