/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:29:25 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/11 09:44:04 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
// # include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

typedef struct s_string
{
	char				c;
	unsigned int		len;
	// struct	s_string	*next;
}	t_string;

#endif