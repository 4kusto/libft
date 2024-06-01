/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:04:58 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/04/22 21:32:38 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
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
// test1, (int)ft_strlcpy(test1, test2, size));
// 	return (0); 
// }