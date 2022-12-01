/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:12:11 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/26 16:23:36 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_str_for_prefix2(t_prefix prefix, char **str)
{
	if (prefix == PREFIX_EMPTY && strdup2("", str))
		return (1);
	if (prefix == PREFIX_MINUS && strdup2("-", str))
		return (1);
	if (prefix == PREFIX_PLUS && strdup2("+", str))
		return (1);
	if (prefix == PREFIX_SPACE && strdup2(" ", str))
		return (1);
	if (prefix == PREFIX_0X_LOWER && strdup2("0x", str))
		return (1);
	if (prefix == PREFIX_0X_UPPER && strdup2("0X", str))
		return (1);
	return (*str == NULL);
}

int	get_prefix_length(t_prefix prefix)
{
	if (prefix == PREFIX_EMPTY)
		return (0);
	if (prefix == PREFIX_MINUS)
		return (1);
	if (prefix == PREFIX_PLUS)
		return (1);
	if (prefix == PREFIX_SPACE)
		return (1);
	if (prefix == PREFIX_0X_LOWER)
		return (2);
	if (prefix == PREFIX_0X_UPPER)
		return (2);
	return (-1);
}
