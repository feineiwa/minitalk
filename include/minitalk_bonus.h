/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:52:19 by frahenin          #+#    #+#             */
/*   Updated: 2024/06/28 16:10:54 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_string
{
	unsigned char		c;
	struct s_string	*next;
}					t_string;

#endif