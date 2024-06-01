/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:59:19 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/22 20:21:14 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	const char	*str;
	int			i;

	i = 0;
	str = " \n\t\v\f\r";
	while (c != str[i])
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *s)
{
	long	res;
	long	coeff;

	res = 0;
	coeff = -1ul >> 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			coeff = ~(-1ul >> 1);
	while (*s && ft_isdigit(*s))
	{
		if (__builtin_mul_overflow(res, 10, &res)
			|| ((0 < coeff) && __builtin_add_overflow(res, *s - '0', &res))
			|| ((coeff < 0) && __builtin_sub_overflow(res, *s - '0', &res)))
			return (coeff);
		s++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	return (ft_atol(nptr));
}
// int main()
// {
// 	char *num = " \t   +1234aaaa";
// 	__builtin_printf("%d\n", ft_atoi(num));
// 	__builtin_printf("%d", atoi(num));
// }