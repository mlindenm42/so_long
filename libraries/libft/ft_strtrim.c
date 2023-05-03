/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:00:04 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/09 12:24:09 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = 0;
	end = 0;
	ptr = NULL;
	if (set == NULL && s1 != NULL)
		return ((char *)s1);
	else if (s1 != NULL)
	{
		if (ft_strlen(s1) > 0)
			end = ft_strlen(s1) - 1;
		while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
			start++;
		while (end > start && ft_strchr(set, s1[end]) != NULL)
			end--;
		ptr = ft_substr(s1, start, end - start + 1);
	}
	return (ptr);
}
