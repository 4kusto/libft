/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:04 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/24 18:35:53 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define AL_CH 0x1f // 1111

void	copy_aligned(const unsigned char *src, unsigned char *dst, size_t n)
{
	__asm__	__volatile__(
			"1:\n\t"
			"vmovdqa (%[src]), %%ymm0 \n\t"
			"vmovdqa %%ymm0, (%[dst]) \n\t"
			"addq $32, %[src] \n\t"
			"addq $32, %[dst] \n\t"
			"subq $32, %[n] \n\t"
			"jnz 1b \n\t"
			: [src] "+r" (src), [dst] "+r" (dst), [n] "+r" (n)
			:
			: "memory", "ymm0"
			);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char *(x) = (const unsigned char *) src;
	unsigned char *(y) = (unsigned char *) dst;
	size_t (xalign) = ((size_t)x) & AL_CH, yalign = ((size_t)y) & AL_CH;
	while ((xalign && n) || (yalign && n))
	{
		*y++ = *x++;
		xalign = ((short int)x) & AL_CH;
		yalign = ((short int)y) & AL_CH;
		--n;
	}
	if (n >= 32)
	{
		size_t (aligned_blocks) = n & ~(size_t)AL_CH;
		copy_aligned(x, y, aligned_blocks);
		x += aligned_blocks;
		y += aligned_blocks;
		n -= aligned_blocks;
	}
	while (n--)
		*y++ = *x++;
	return (dst);
}
