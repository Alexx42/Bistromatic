/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:44:43 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 12:41:54 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char		*parse_input()
{
	char	*line;
	int		i;
	int		count;
	char	*res;
	int		j;
	int 	neg;
	int 	len;
	int 	a;

	j = 0;
	i = 0;
	neg = 0;
	count = 0;
	if (get_next_line(0, &line) < 1)
		return (0);
	line = del_spaces(line);
	while (line[i] != '\0')
	{
		if (line[i] == '(')
			count++;
		else if (line[i] == ')')
			count--;
		if (ft_isdigit(line[i]) && line[i + 1] == '(')
		{
			printf("syntax error\n");
			return (NULL);
		}
		i++;
	}
	i = 0;
	len = (int)ft_strlen(line);
	if (line[i] == '(')
		i++;
	while (line[i] == '+' || ((line[i] == '-') || (line[i] == '(')))
	{
		if (line[i] == '-')
			neg++;
		i++;
	}
	res = malloc((size_t)(len + 2));
	j = 0;
	if (neg % 2 != 0)
	{
		res[j] = '-';
		j++;
	}
	a = i;
	i = 0;
	while(i < a)
	{
		if (line[i] != '+' && line[i] != '-')
		{
			res[j] = line[i];
			j++;
		}
		i++;
	}
	while (line[i])
	{
		res[j] = line[i];
		i++;
		j++;
	}
	res[j] = '\0';
	if (count != 0)
	{
		printf("syntax error\n");
		return (NULL);
	}
	return (res);
}

void		parse_argv(char **av, t_parse *parsing)
{
	parsing->base = (char)ft_strlen(av[1]);
	parsing->size = ft_atoi(av[2]);
	parsing->value_base = ft_memalloc(parsing->base + 1);
	parsing->value_base = av[1];
}
