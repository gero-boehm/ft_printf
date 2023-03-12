/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:49:00 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 13:52:31 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_prefix(t_prefix prefix, t_tag *tag)
{
	tag->result.prefix = prefix;
}

static void	determine_prefix(int value, t_tag *tag)
{
	if (value < 0)
		set_prefix(PREFIX_MINUS, tag);
	else if (has_plus_flag(tag))
		set_prefix(PREFIX_PLUS, tag);
	else if (has_space_flag(tag))
		set_prefix(PREFIX_SPACE, tag);
}

int	eval_int(int value, t_tag *tag)
{
	unsigned int	uval;

	uval = value;
	if (value < 0)
		uval = ~uval + 1;
	determine_prefix(value, tag);
	return (eval_unsigned(uval, tag));
}
