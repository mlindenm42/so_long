/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:45:39 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/19 20:49:06 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arraycounter(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	charcounter(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*(s + i) != c && *(s + i))
		i++;
	return (i);
}

static int	stringmaker(char **ptrptr, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		*(ptrptr + i) = (char *) malloc((charcounter(s, c) + 1) * sizeof(char));
		if (*(ptrptr + i) == NULL)
			return (0);
		while (*s == c && *s)
			s++;
		ft_strlcpy(*(ptrptr + i), s, charcounter(s, c) + 1);
		s += charcounter(s, c);
		while (*s == c && *s)
			s++;
		i++;
	}
	*(ptrptr + i) = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrptr;

	ptrptr = NULL;
	if (s == NULL)
		return (NULL);
	ptrptr = (char **) malloc((arraycounter(s, c) + 1) * sizeof(char *));
	if (ptrptr == NULL)
		return (NULL);
	if (!(arraycounter(s, c)))
		*(ptrptr) = NULL;
	else if (!(stringmaker(ptrptr, s, c)))
	{
		while (*ptrptr)
		{
			free (*ptrptr);
			ptrptr++;
		}
		free (ptrptr);
		return (NULL);
	}
	return (ptrptr);
}
