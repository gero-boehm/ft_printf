/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:53:13 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 13:33:48 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_unsigned(unsigned int value, t_tag *tag)
{
	char	*str;

	if (value == 0 && tag->properties.precision == 0)
	{
		if (strdup2("", &str))
			return (1);
	}
	else
	{
		if (itoa_base2(value, "0123456789", &str))
			return (2);
	}
	set_result_str(str, tag);
	return (0);
}
