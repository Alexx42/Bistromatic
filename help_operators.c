/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:11:48 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 22:59:52 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void		remove_elem(char **str, t_parse *parse, int len)
{
	int i;

	i = 0;
	if ((*str)[0] == '-' /*&& parse->neg == 0*/)
	{
		while (i < len)
		{
			(*str)[i] = (*str)[i + 1];
			i++;
		}
		(*str)[i] = '\0';
	}
}

void		swap(char **a, char **b, int *len_a, int *len_b)
{
	char *tmp;
	int tmp2;

	tmp2 = *len_a;
	*len_a = *len_b;
	*len_b = tmp2;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

char		*str_reverse_in_place(char *str, t_parse *parse)
{
	char *p1;
	char *p2;
	char tmp;
	int len;

	len = ft_strlen(str);
	p1 = str;
	p2 = str + (len - 1);
	while (p1 < p2)
	{
		tmp = *p1;
		*p1++ = *p2;
		*p2-- = tmp;
	}
	return (str);
}

void		*mm_realloc (void *ptr, size_t size)
{
	void *newptr;

	newptr = (char *)malloc(size);
	if (newptr == NULL)
		return NULL;
	if (ptr != NULL)
	{
		ft_memcpy(newptr, ptr, size);
		free(ptr);
	}
	return (newptr);
}