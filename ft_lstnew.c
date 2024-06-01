/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:02:19 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/05/02 21:01:24 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof (t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
