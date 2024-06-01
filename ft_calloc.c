/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:59:37 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/02 20:54:12 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total;
	size_t	i;

	i = 0;
	if (__builtin_mul_overflow(count, size, &total))
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
