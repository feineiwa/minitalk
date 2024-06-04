/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:42:25 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/04 15:57:33 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int seg)
{
	printf ("\nThank you");
	exit (EXIT_SUCCESS);
}

int	main()
{
	signal(SIGINT, &signal_handler);
	while (1)
	{
		printf("ok\n");
	}
}