/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:59:02 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/06/23 00:39:33 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_set(unsigned char *dst, uint64_t c64, size_t n64)
{
	{
		__asm__(
			"rep stosq\n"
			: "+D"(dst),
			"+c" (n64)
			: "a" (c64)
			: "memory"
			);
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t (i) = 0;
	unsigned char *(dst) = (unsigned char *)s;
	if (i < n)
	{
		uint64_t (c64) = (unsigned char)c;
		c64 |= c64 << 8;
		c64 |= c64 << 16;
		c64 |= c64 << 32;
		size_t (n64) = (n - i) / sizeof(uint64_t);
		ft_set(dst, c64, n64);
		i += n64 * sizeof(uint64_t);
	}
	while (i < n)
	{
		dst[i] = (unsigned char)c;
		++i;
	}
	return (s);
}

// int main(){
// 	char str[50];
// 	strcpy(str, "This is a test!");
// 	//char *str = "This is a test!";
// 	ft_memset(str, '-', 5);
// 	printf("%s", str);
// }
