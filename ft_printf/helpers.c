/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:47:45 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/09 23:47:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	dtoa(unsigned char digit, char uppercase)
{
	if (digit < 10)
		return (char)(digit + '0');
	else
		return (char)(digit - 10 + 'A' + (!uppercase) * 32);
}

char	*ft_itoa_base_signed(long long value, unsigned char base, char upper)
{
	char		*s;
	long long	n;
	int			sign;
	int			i;

	if (value == INT64_MIN && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (value == INT64_MAX && base == 10)
		return (ft_strdup("9223372036854775807"));
	sign = value < 0 ? 1 : 0;
	value = value < 0 ? -value : value;
	n = value;
	i = sign ? 2 : 1;
	while ((n /= base) > 0)
		i++;
	s = (char*)malloc(sizeof(char) * (4096));
	s[i] = '\0';
	while (i-- - sign)
	{
		s[i] = dtoa((unsigned char)(value % base), upper);
		value /= base;
	}
	if (sign)
		s[0] = '-';
	return (s);
}

char	*ft_itoa_base(unsigned long long value, unsigned char base, char upper)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = value;
	i = 1;
	if ((long)value == INT64_MIN && base == 10)
		return (ft_strdup("-9223372036854775807"));
	if (value == INT64_MAX && base == 10)
		return (ft_strdup("9223372036854775807"));
	while ((n /= base) > 0)
	{
		i++;
	}
	s = (char*)malloc(sizeof(char) * (4096));
	s[i] = '\0';
	while (i--)
	{
		s[i] = dtoa((unsigned char)(value % base), upper);
		value /= base;
	}
	return (s);
}
