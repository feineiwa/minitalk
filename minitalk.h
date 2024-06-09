/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:29:25 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/09 23:31:05 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
// # include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_string
{
	char				c;
	struct	s_string	*next;
}	t_string;

#endif