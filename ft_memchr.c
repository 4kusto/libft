/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:02:41 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/02 20:47:52 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = -1;
	while (++i < n)
		if (str[i] == (char) c)
			return ((char *)(s + i));
	return (NULL);
}
