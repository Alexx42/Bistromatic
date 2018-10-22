/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:28:54 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/10 16:28:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_nb(t_list **lst, t_flags *flags, int i)
{
	while (i < flags->precision - flags->len)
	{
		append3(lst, "0", 1);
		i++;
	}
}

void	precision_str(t_list **lst, t_flags *flags, char **arr, int i[2])
{
	while (i[0] < flags->precision && flags->width > flags->precision &&
	flags->len > 0)
	{
		if (flags->minus == 0)
			append3(lst, " ", 1);
		else if (flags->minus == 1)
		{
			if (flags->width > flags->precision && flags->width >
			flags->len)
				append3(lst, " ", 1);
			else
			{
				(*arr)[i[0] + i[1]] = ' ';
				flags->len++;
			}
		}
		i[0]++;
	}
}

void	check_null(int *len, char **arr)
{
	if (*arr == NULL)
	{
		*len += 1;
		*arr = malloc(1);
		**arr = 0;
	}
}

void	renew(int *len, const char **fmt, t_list **lst)
{
	(*fmt)++;
	print_list2((*lst));
	*len += list_size2((*lst));
	delete_list2(lst);
}
