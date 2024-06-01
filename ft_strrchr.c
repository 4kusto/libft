/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:05:51 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/04/26 18:22:52 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (1)
	{
		if (*s == (char) c)
			save = (char *)s;
		if (!*s)
			return (save);
		s++;
	}
}
// int main()
// {
// 	int c = 't';
// 	char *str = "batata";
// 	printf("%s", ft_strchr(str, c));
// }