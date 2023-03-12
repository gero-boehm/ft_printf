/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:42:18 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 11:43:21 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_str(char *value, t_tag *tag)
{
	char	*str;

	if (value == NULL)
	{
		if (strdup2("(null)", &str))
			return (1);
	}
	else
	{
		if (strdup2(value, &str))
			return (2);
	}
	set_result_str(str, tag);
	return (0);
}
