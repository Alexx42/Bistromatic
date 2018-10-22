/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:26:16 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/21 00:34:57 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

 void		check_negative(char **a, char **b, t_parse *parse, int len[2])
{
	if ((*a)[0] == '-')
	{
		remove_elem(a, parse, (len)[0]);
		len[0]--;
	}
	if ((*b)[0] == '-')
	{
		remove_elem(b, parse, (len)[1]);
		len[1]--;
	}
}

char		*add(char *a, char *b, t_parse *parse)
{
	int		len[2];
	int		carry;
	int		i;
	char	*sum;
	int		j;
	char	*final;

	len[0] = (int)ft_strlen(a);
	len[1] = (int)ft_strlen(b);
	len[0] > len[1] ? swap(&a, &b, &len[0], &len[1]) : 0;
	MCK(sum = ft_memalloc(len[1] + len[0] + 4), NULL);
	check_negative(&a, &b, parse, len);
	carry = 0;
	i = len[0];
	j = 0;
	while (--i >= 0)
	{
		sum[j] = (parse->value_base)[(is_base(a[i], parse) +
		is_base(b[i +(len[1] - len[0])], parse) + carry) % parse->base];
		carry = ((is_base(a[i], parse) + is_base(b[i + len[1] - len[0]], parse))
		+ carry) / parse->base;
		j++;
	}
	i = len[1] - len[0];
	while (--i >= 0)
	{
		sum[j] = (parse->value_base)[((is_base(b[i], parse) + carry)) % parse->base];
		carry = (is_base(b[i], parse) + carry) / parse->base;
		j++;
	}
	if (carry)
		sum[j++] = (parse->value_base)[carry];
	// sum[j] = '\0';
	str_reverse_in_place(sum, parse);
	final = new_array(sum, len[0], len[1], parse);
	return (final);
}
