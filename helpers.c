/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:21:12 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/21 00:15:47 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	shift_right_minus(char **str, int *len, t_parse *base)
{
	int i;

	i = *len - 1;
	while (i >= 0)
	{
		(*str)[i + 1] = (*str)[i];
		i--;
	}
	(*str)[0] = '-';
	(*len)++;
}

int		is_base(char c, t_parse *parse)
{
	int i;

	i = -1;
	while (parse->value_base[++i])
		if (c == parse->value_base[i])
			return (i);
	if (c == '/' || c == '*' || c == '%' || c == '+'
	|| c == '-' || c == '\0' || c == ')' || c == '(')
		return (-1);
	return (-2);
}

int		is_op(char c)
{
	if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-' || c == '\0')
		return (1);
	return (0);
}

char	*new_array(char *res, int len1, int len2, t_parse *parse)
{
	char	*ret;
	int		i;
	int		len;
	int		j;

	len = (int)ft_strlen(res);
	i = 0;
	j = 0;
	MCK(ret = ft_memalloc(len1 + len2 + 4), NULL);
	while (i < len && res[i] == '0')
		i++;
	if (i == len)
		return (ft_strdup("0"));
	while (j <= len)
	{
		ret[j] = res[i + j];
		j++;
	}
	if (parse->neg)
	{
		shift_right_minus(&ret, &len, parse);
		j++;
	}
	else
		remove_elem(&ret, parse, len);
	// ret[j] = '\0';
	return (ret);
}
