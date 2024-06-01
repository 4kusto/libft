/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:05:41 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/04/19 00:34:24 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle++)
	{
		needle_len = ft_strlen(needle);
		while (1)
		{
			while (1)
			{
				if (len-- < 1 || !*haystack++)
					return (NULL);
				if (*(haystack - 1) == *(needle - 1))
					break ;
			}
			if (needle_len > len)
				return (NULL);
			if (!ft_strncmp(haystack, needle, needle_len))
				break ;
		}
		haystack--;
	}
	return ((char *)haystack);
}
// int	main(void)
// {
// 	char haystack[] = "This is a test!";
// 	char needle[] = "is";

// 	printf("Haystack: %s\nNeedle:%s\nWhere:%s", 
// haystack, needle, ft_strnstr(haystack, needle, 4));

// 	return (0);
// }
