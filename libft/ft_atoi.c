/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:39:04 by gbohm             #+#    #+#             */
/*   Updated: 2022/10/18 14:33:30 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c == '\t' || c == '\n' || c == '\v')
		|| (c == '\f' || c == '\r' || c == ' '));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			break ;
		result = result * 10 + (int) *str - '0';
		str++;
	}
	return (result * sign);
}
