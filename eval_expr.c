/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:17:11 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/21 00:30:32 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

char	*del_spaces(char *str)
{
	char *arr;
	int i;
	int len;
	int j;

	j = 0;
	i = 0;
	len = (int)ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	MCK(arr = ft_memalloc((len - i) + 1), NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			arr[j] = str[i];
			j++;
		}
		i++;
	}
	arr[j] = '\0';
	return (arr);
}

char	*parse_atoms(char **str, t_parse *parse)
{
	char *n;
	char *ptr;
	int i;
	int ret;
	int len;
	static int count = 0;

	len = (int)ft_strlen(*str);
	i = 0;
	n = 0;
	ptr = ft_memalloc(len + 1);
	if (**str == '(')
	{
		++(*str);
		n = parse_sums_subs(str, parse);
		if (**str == ')')
		{
			++(*str);
			return (n);
		}
	}
	while ((ret = is_base((*str)[i], parse)) >= 0 || (is_op((*str)[i - 1]) &&
	is_op((*str)[i])) || ((*str)[0] == '-' && count == 0))
	{
		ptr[i] = (*str)[i];
		count++;
		i++;
	}
	if (ret == -2)
		return (NULL);
	while (i--  > 0 && (*str)[i] != '-')
	{
//		parse->neg = 0;
		parse->par = 1;
		(*str)++;
	}
	return (ptr);
}

char	*parse_factors(char **str, t_parse *parse)
{
	char	*num1;
	char	*num2;
	char	op;
	char 	*init;

	init = (char*)malloc(2);
	if (parse->neg == 0)
	{
		init[0] = '-';
		init[1] = 1;
	}

	num1 = parse_atoms(str, parse);
	while (1)
	{
		parse->neg = 0;
		op = **str;
		if (op != '/' && op != '*' && op != '%')
			return (mult(num1, init, parse));
		++(*str);
		num2 = parse_atoms(str, parse);
		if (op == '/')
			num1 = division(num1, num2, parse);
		else if (op == '*')
			num1 = mult(num1, num2, parse);
		else
			ft_printf("salut\n");
	}
}

char	*parse_sums_subs(char **str, t_parse *parse)
{
	char	*num1;
	char	*num2;
	char	op;

	num1 = parse_factors(str, parse);
	while (1)
	{
		parse->neg = 0;
		op = **str;
		if (op != '+' && op != '-')
			return (num1);
		++(*str);
		num2 = parse_factors(str, parse);
		if (op == '+')
		{
			if (num1[0] == '-' && num2[0] != '-')
			{
				num1 = sub(num2, num1, parse);
			}
			else if (num1[0] != '-' && num2[0] == '-')
			{
				num1 = sub(num1, num2, parse);
			}
			else if (num1[0] == '-' && num2[0] == '-')
			{
				parse->neg = 1;
				num1 = add(num2, num1, parse);
			}
			else
			{
				num1 = add(num1, num2, parse);
			}
		}
		else
		{
			if (num1[0] == '-' && num2[0] != '-')
			{
				parse->neg = 1;
				num1 = add(num1, num2, parse);
			}
			else if (num1[0] != '-' && num2[0] == '-')
			{
				num1 = add(num1, num2, parse);
			}
			else if (num1[0] == '-' && num2[0] == '-')
			{
				num1 = sub(num1, num2, parse);
			}
			else
				num1 = sub(num1, num2, parse);
		}
	}
}

char*		eval_expr(char *str, t_parse *parse)
{
	str = del_spaces(str);
	return (parse_sums_subs(&str, parse));
}
