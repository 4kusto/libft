/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:04:39 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/04/25 20:57:34 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

// int	main(void)
// {
// 	char *str1 = "This is";
// 	char *str2 = " a test!";
// 	printf("%s\n", ft_strjoin(str1, str2));
// 	return (0);
// }