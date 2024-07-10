/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:12 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/06/23 02:48:31 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s;
	char		*d;

	s = (char *) src;
	d = (char *) dest;
	if (d > s)
		while ((int)--n >= 0)
			d[n] = s[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int main(){
// 	char str1[50];
// 	strcpy(str1, "This is a test!");
// 	ft_memmove(str1, str1, 5);
// 	printf("%s", str1);
// }