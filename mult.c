/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:56:33 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 12:48:20 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

int		check_value(char **nb1, char **nb2, t_parse *parse)
{
	if (*nb1[0] == '-' && *nb2[0] != '-')
	{
		parse->neg = 1 - 0;
		(*nb1)++;
	}
	else if (*nb1[0] == '-' && *nb2[0] == '-')
	{
		(*nb1)++;
		(*nb2)++;
		parse->neg = 0;
	}
	else if (*nb1[0] != '-' && *nb2[0] == '-')
	{
		parse->neg = 1;
		(*nb2)++;
	}
	if (*nb2[0] == '-' || *nb2[0] == '+')
		(*nb2)++;
	if (ft_strcmp(*nb1, "0") == 0 || ft_strcmp(*nb2, "0") == 0)
		return (0);
	return (1);
}

char     *mult(char *nb1, char *nb2, t_parse *parse)
{
    int		len1;
    int		len2;
    int		i;
    int		j;
    char	*res;
    int		sum;
    int		carry;
	char	*final;

	if (check_value(&nb1, &nb2, parse) == 0)
		return (ft_strdup("0"));
	len1 = (int)ft_strlen(nb1) - 1;
	len2 = (int)ft_strlen(nb2) - 1;
	MCK(res = ft_memalloc(len1 + len2 + 2), NULL);
	i = -1;
	while (++i < len1 + len2 + 2)
    	res[i] = '0';
	i = -1;
	while (++i <= len2 && (j = -1) == -1 && (carry = 0) == 0)
	{
    	while (++j <= len1)
    	{
			sum = (nb2[len2 - i] - '0') * (nb1[len1 - j] - '0') + carry;
        	carry = (sum + res[1 + len1 + len2 -j -i] - '0') / parse->base;
            res[1 + len1 + len2 - i - j] = (res[1 + len1 + len2 - i - j] - '0'
			+ sum ) % parse->base + '0';
        }
        res[1 + len1 + len2 - i - j] = carry + '0';
    }
    res[2 + len1 + len2] = '\0';
	final = new_array(res, len1, len2, parse);
    return (final);
}
