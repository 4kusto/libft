/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:59:02 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/24 19:13:31 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
		*str++ = (unsigned char) c;
	return (s);
}

// int main(){
// 	char str[50];
// 	strcpy(str, "This is a test!");
// 	//char *str = "This is a test!";
// 	ft_memset(str, '-', 5);
// 	printf("%s", str);
// }
