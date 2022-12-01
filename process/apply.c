/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:52:48 by gbohm             #+#    #+#             */
/*   Updated: 2022/12/01 11:10:06 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	apply_precision(t_tag *tag)
{
	int	difference;

	if (tag->properties.precision == -1)
		return (0);
	if (tag->properties.specifier == 's')
	{
		difference = tag->result.size - tag->properties.precision;
		if (difference > 0)
			tag->result.size -= difference;
		if (substr2(0, tag->properties.precision, &tag->result.str))
			return (2);
		return (0);
	}
	if (is_char_specifier(tag) || is_percent_specifier(tag))
		return (0);
	if (padstr2(tag->properties.precision, 0, 1, &tag->result))
		return (2);
	return (0);
}

static int	apply_padding(t_padding_space leave_space, t_tag *tag)
{
	int	zeroes;
	int	space;

	zeroes = tag->properties.zeroes;
	if (tag->properties.left_justify
		|| (is_num_specifier(tag) && tag->properties.precision != -1))
		zeroes = 0;
	space = 0;
	if (leave_space == LEAVE_SPACE)
		space = get_prefix_length(tag->result.prefix);
	if (padstr2(tag->properties.padding - space, tag->properties.left_justify,
			zeroes, &tag->result))
		return (1);
	return (0);
}

static int	apply_prefix(t_tag *tag)
{
	char	*prefix;
	int		length;

	if (tag->result.prefix == PREFIX_EMPTY)
		return (0);
	if (get_str_for_prefix2(tag->result.prefix, &prefix))
		return (1);
	if (strapp2(prefix, &tag->result.str))
		return (free(prefix), 2);
	free(prefix);
	length = get_prefix_length(tag->result.prefix);
	tag->result.size += length;
	return (0);
}

static int	is_padding_between_prefix_and_str(t_tag *tag)
{
	return (!has_precision(tag) && has_zeroes_flag(tag)
		&& !has_left_justify_flag(tag));
}

int	apply_flags(t_tag *tag)
{
	if (apply_precision(tag))
		return (1);
	if (is_padding_between_prefix_and_str(tag))
	{
		if (apply_padding(LEAVE_SPACE, tag))
			return (2);
		if (apply_prefix(tag))
			return (3);
	}
	else
	{
		if (apply_prefix(tag))
			return (4);
		if (apply_padding(LEAVE_NO_SPACE, tag))
			return (5);
	}
	return (0);
}
