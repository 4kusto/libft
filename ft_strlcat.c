/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:04:48 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/02 19:08:51 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dst;
	osrc = src;
	n = size;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
// int	main(void)
// {
// 	//i is just a counter
// 	//j is dest size
// 	//k is src size
// 	char	test1[50] = "This is a ";
// 	char	test2[50] = "Test!";
// 	size_t	size = 15;
// 	//ft_strlcat(test1, test2, size);
// 	printf("Final sentence is: %s\nAnd the size is %d", 
// test1, (int)ft_strlcat(test1, test2, size));
// 	return (0); 
// }
