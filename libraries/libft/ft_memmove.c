/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:12:57 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/10 04:10:04 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	i = 0;
	if (dest == src)
		return (dest);
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (i < n)
	{
		if ((void *)dest > (void *)src)
			ptr_dest[n - i - 1] = ptr_src[n - i - 1];
		else
			ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
