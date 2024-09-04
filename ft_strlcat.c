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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
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
