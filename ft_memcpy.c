/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:04 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/06/29 18:14:36 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_aligned32(void *src, void *dst, size_t n)
{
	if (1)
	{
		asm (
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
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char *(src_ptr) = (const unsigned char *) src;
	unsigned char *(dst_ptr) = (unsigned char *) dst;
	unsigned long (src_al) = ((size_t)src_ptr) & 0x1f;
	unsigned long (dst_al) = ((size_t)dst_ptr) & 0x1f;
	if (!dst && !src)
		return (NULL);
	while ((src_al && n) || (dst_al && n))
	{
		*dst_ptr++ = *src_ptr++;
		src_al = ((short int)src_ptr) & 0x1f;
		dst_al = ((short int)dst_ptr) & 0x1f;
		--n;
	}
	if (n >= 32)
	{
		size_t (aligned_blocks) = n & ~(size_t)0x1f;
		copy_aligned32(src_ptr, dst_ptr, aligned_blocks);
		src_ptr += aligned_blocks;
		dst_ptr += aligned_blocks;
		n -= aligned_blocks;
	}
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
