/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:02:53 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/03 17:59:12 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*str1;
	const unsigned char		*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = -1;
	while (++i < n)
		if (str1[i] != str2[i])
			return ((str1[i] - str2[i]));
	return (0);
}
