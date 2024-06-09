/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:43 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/09 23:37:03 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

t_string *g_message = NULL;

void	append_char_to_list(char c)
{
	t_string	*new_node = malloc(sizeof(t_string));
	t_string	*temp;

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->c = c;
	new_node->next = NULL;
	if (!g_message)
		g_message = new_node;
	else
	{
		temp = g_message;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
void	print_and_clear()
{
	t_string	*temp = g_message;
	t_string	*to_free;
	while (temp)
	{
		write(1, &(temp->c), 1);
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	g_message = NULL;
}

// void	send_acknowledge(int client_pid)
// {
// 	if (kill(client_pid, SIGUSR1) == -1)
// 		exit(EXIT_FAILURE);
	
// }

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	// static int				client_pid = 0;

	// if (client_pid == 0)
	// 	client_pid = getpid();
	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			print_and_clear();
		}
		else
			append_char_to_list(c);
		bit = 0;
		c = 0;
	}
	// send_acknowledge(client_pid);
}

int	main(int argc, char *argv[])
{
	struct sigaction sa;
	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	printf("server PID: %d\n", getpid());
	sa.sa_sigaction = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
