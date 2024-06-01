/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:04:11 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/04/25 21:27:12 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char) c)
			return ((char *)s);
		if (!*s)
			return (NULL);
		s++;
	}
}

// int main()
// {
// 	int c = 't';
// 	char *str = "";
// 	printf("%s", ft_strchr(str, c));
// }