/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:02:57 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/07 09:40:28 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
			// printf("1");
		}
		else
		{
			kill(pid, SIGUSR2);
			// printf("0");
		}
		bit--;
		usleep(42);
	}
}

void	ft_send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_send_char(pid, message[i]);
		i++;
	}
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
	int pid;

	if (argc != 3)
	{
		printf("Usage: ./client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	error_handling(pid, argv);
	ft_send_message(pid, argv[2]);
	return (0);
}