/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:45:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 22:00:45 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int		greater_value(char *s1, char *s2, int len[2], t_parse **parse)
{
	int i;

	i = 0;
	if (s1[0] == '-')
	{
		remove_elem(&s1, *parse, len[0]);
		len[0]--;
	}
	if (s2[0] == '-')
	{
		remove_elem(&s2, *parse, len[1]);
		len[1]--;
	}
	if (len[1] > len[0])
	{
		(*parse)->neg = 1;
		return (1);
	}
	else if (len[0] > len[1])
		return (0);
	while (i < len[1])
	{
		if (s1[i] < s2[i])
		{
			(*parse)->neg = 1;
			return (1);
		}
		else if (s2[i] < s1[i])
			return (0);
		i++;
	}
	return (0);
}

char			*sub(char *a, char *b, t_parse *base)
{
	int len[2];
	int carry;
	int i;
	char *sum;
	int j;
	int sub;
	char *final;

	len[0] = (int)ft_strlen(a);
	len[1] = (int)ft_strlen(b);
	if (greater_value(a, b, len, &base))
		swap(&b, &a, &len[0], &len[1]);
	MCK(sum = (char *)malloc(sizeof(char) * (len[0] + len[1] + 4)), NULL);
	int diff = len[0] - len[1];
	carry = 0;
	i = len[1];
	sum[i] = '\0';
	j = 0;

	while (--i >= 0)
	{
		sub = ((is_base(a[i + diff], base) - '0') - (is_base(b[i], base) -
		'0') - carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		sum[j++] = (base->value_base)[sub];
	}
	i = 0;
	while (--diff >= 0)
	{
		i++;
		if (a[diff] == '0' && carry)
		{
			sum[j++] = '9';
			continue ;
		}
		sub = ((a[diff] - '0') - carry);
		if (diff > 0 || sub > 0)
			sum[j] = (char)(sub + '0');
		j++;
		carry = 0;
	}
	 sum[j] = '\0';
	str_reverse_in_place(sum, base);
	final = new_array(sum, len[0], len[1], base);
	return (final);
}
