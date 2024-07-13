/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:28:43 by frahenin          #+#    #+#             */
/*   Updated: 2024/07/13 13:54:42 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_string	*g_message = NULL;

void	append_char_to_list(char c)
{
	t_string	*new_node;
	t_string	*temp;

	new_node = malloc(sizeof(t_string));
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

void	print_and_clear(void)
{
	t_string	*temp;
	t_string	*to_free;

	temp = g_message;
	while (temp)
	{
		ft_printf("\e[0;37m%c", temp->c);
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	g_message = NULL;
}

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bit = 7;
	static unsigned char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
	{
		if (c == '\0')
			print_and_clear();
		else
			append_char_to_list(c);
		bit = 7;
		c = 0;
	}
	if (info->si_pid != 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("server PID: \e[0;33m [%d]\n", getpid());
	sa.sa_sigaction = ft_btoa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
