/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbohm <gbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:22:36 by gbohm             #+#    #+#             */
/*   Updated: 2022/11/30 14:00:52 by gbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	init_tag(t_tag *tag)
{
	tag->properties.left_justify = 0;
	tag->properties.plus = 0;
	tag->properties.space = 0;
	tag->properties.prefix = 0;
	tag->properties.zeroes = 0;
	tag->properties.padding = 0;
	tag->properties.precision = -1;
	tag->properties.specifier = 0;
	tag->range.start = 0;
	tag->range.length = 0;
	tag->result.str = NULL;
	tag->result.prefix = PREFIX_EMPTY;
	tag->result.size = 0;
}

void	free_tag(t_tag *tag)
{
	free(tag->result.str);
}

int	has_left_justify_flag(t_tag *tag)
{
	return (tag->properties.left_justify);
}

int	has_plus_flag(t_tag *tag)
{
	return (tag->properties.plus);
}

int	has_space_flag(t_tag *tag)
{
	return (tag->properties.space);
}

int	has_prefix_flag(t_tag *tag)
{
	return (tag->properties.prefix);
}

int	has_zeroes_flag(t_tag *tag)
{
	return (tag->properties.zeroes);
}

int	has_padding(t_tag *tag)
{
	return (tag->properties.padding > 0);
}

int	has_precision(t_tag *tag)
{
	return (tag->properties.precision >= 0);
}
