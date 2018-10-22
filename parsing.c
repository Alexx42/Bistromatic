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

	i = 0;
	count = 0;
	if (get_next_line(0, &line) < 1)
		return (0);
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
	if (count != 0)
	{
		printf("syntax error\n");
		return (NULL);
	}
	return (line);
}

void		parse_argv(char **av, t_parse *parsing)
{
	parsing->base = ft_strlen(av[1]);
	parsing->size = ft_atoi(av[2]);
	parsing->value_base = ft_memalloc(parsing->base + 1);
	parsing->value_base = av[1];
}
