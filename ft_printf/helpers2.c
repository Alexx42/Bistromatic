/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:45:55 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/09 23:45:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_wchar(wchar_t *s1)
{
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
		return (ft_strdup("(null)"));
	while (s1[i])
		i++;
	if ((cpy = malloc(sizeof(char) * 4096)) == NULL)
		return (NULL);
	while (s1[j])
	{
		cpy[j] = (char)s1[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

int		is_carac(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
