/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:06:25 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/10 16:06:28 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(t_list **lst, t_flags *flags, char **arr, const char *fmt)
{
	int len;

	if (flags->hash)
		len = hash_flags(lst, fmt, arr);
	else
		len = flags->len_total;
	protect_value(lst, &flags, arr);
	return (len);
}

void	width_zminus(t_list **lst, const t_flags *flags, int len)
{
	if (flags->o_flag && len == 0)
	{
		if (flags->width - flags->precision != flags->len)
			append3(lst, "0", 1);
		else
			append3(lst, " ", 1);
	}
	else if (flags->o_flag && len > 0)
		append3(lst, "0", 1);
	else if (len > 0 && flags->o_flag == 0)
		push(lst, " ", 1);
	else
		append3(lst, " ", 1);
}

void	protect_value(t_list **lst, t_flags **flags, char **arr)
{
	if (*arr)
		parse_zero(arr, flags);
	if (*arr)
		value_negative(arr, lst, flags);
}

int		precision_width(t_flags *flags)
{
	return ((flags->precision > flags->len && flags->len > 0) ?
			(flags->precision) : flags->len);
}

void	arr_width(t_flags *flags, char **arr, int i[2])
{
	(*arr)[i[1] + i[0]] = ' ';
	flags->len++;
}
