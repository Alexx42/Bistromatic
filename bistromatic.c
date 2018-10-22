/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:39:59 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 13:54:06 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

t_parse		*init()
{
	t_parse *parse;

	MCK(parse = (t_parse*)malloc(sizeof(t_parse)), NULL);
	parse->neg = 0;
	parse->base = 0;
	parse->value_base = NULL;
	parse->size = 0;
	parse->par = 0;

	return (parse);
}

int		usage(int ac)
{
	if (ac != 3)
	{
		printf("usage: calc [base] [input_size]\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	*arr;
	t_parse	*parse;

	RETURN_VAL(usage(ac), 1);
	parse = init();
	parse_argv(av, parse);
	RETURN_VAL((arr = parse_input()), NULL);
	char *sum = eval_expr(arr, parse);
	if (sum == NULL)
	{
		ft_printf("syntax error\n");
		return (0);
	}
	ft_printf("%s\n", sum);
	return (0);
}
