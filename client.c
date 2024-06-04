/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:02:57 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/04 20:32:27 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int	g_bit_control; /** global static int variable. it will help us note 
// *   when we stopped receiving signals
// */

void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		// g_bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		// while (g_bit_control != 1);
		usleep(300);
	}
}

void	ft_send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		ft_send_char(pid, message[i++]);
	ft_send_char(pid, 0);
}

// void	sig_handler(int sig)
// {
// 	// if (sig == SIGUSR1)
// 		// g_bit_control = 1;
// 	if (sig == SIGUSR2)
// 	{
// 		printf("Message received\n");
// 		exit(EXIT_SUCCESS);
// 	}
// }

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		printf("Usage: ./client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	// signal(SIGUSR1, &sig_handler);
	// signal(SIGUSR2, &sig_handler);
	pid = atoi(argv[1]);
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
	ft_send_message(pid, argv[2]);
	return (0);
}