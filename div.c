/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:46:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 16:47:08 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int		check_values(char *a, char *b, int *len)
{
	int i;

	i = 0;
	if (len[0] < len[1])
		return (1);
	while (i < len[1])
	{
		if (a[i] < b[i])
			return (1);
		else if (a[i] > b[i])
			return (0);
		i++;
	}
	if (ft_strcmp(a, b) == 0)
		return (2);
	return (0);
}

char	*division(char *a, char *b, t_parse *parse)
{
	char	*res;
	char	*final;
	int		temp;
	int		len[2];
	char	*obj;

	len[0] = (int)ft_strlen(a);
	len[1] = (int)ft_strlen(b);
	obj = (char*)malloc(sizeof(char) * len[1] + 1);
	if (ft_strcmp(b, "0") == 0)
	{
		ft_printf("syntax error\n");
		return (NULL);
	}
	if (check_values(a, b, len) == 1)
		return (ft_strdup("0"));
	if (check_values(a, b, len) == 2)
		return (ft_strdup("1"));
	if (ft_strcmp(a, "0") == 0)
		return (ft_strdup("0"));
	ft_strncpy(obj, a, len[1]);
	if (sub(obj, b, parse)[0] == '-')
	{
		obj = ft_strncpy(obj, a, len[1] + 1);
		obj = sub(obj, b, parse);
	}

	return (res);
}
