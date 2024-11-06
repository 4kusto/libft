/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:59:19 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/11/17 21:09:22 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atol(const char *s)
{
	long (res) = 0;
	long (coeff) = LONG_MIN;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			coeff = ~(LONG_MIN);
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