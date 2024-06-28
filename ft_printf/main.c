/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:53:47 by frahenin          #+#    #+#             */
/*   Updated: 2024/03/15 15:27:11 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	c;

	c = 214748;
	c = ft_printf("j\' ai %d, je suis %s et mon adresse est %p et l'hex %x et %X et ce carac %c avec %u %%\n", 24, "faneva", &c, c, c, 'u', 78654254);
	ft_printf("%d\n", c);
}
