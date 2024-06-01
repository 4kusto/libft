/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:06:16 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/24 06:14:33 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *(str);
	int (start), end;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	while (ft_strrchr(set, s1[end]) && end >= 0)
		end--;
	if (ft_strchr (set, s1[start]) && start >= end)
		return (ft_strdup(""));
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], (end - start + 2));
	return (str);
}
