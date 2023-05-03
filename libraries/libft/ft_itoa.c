/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:23:35 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/09 17:44:38 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenghtint(int n)
{
	int	lenght;

	lenght = 0;
	if (n <= 0)
		lenght++;
	while (n != 0)
	{
		n /= 10;
		++lenght;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char *)malloc((lenghtint(n) + 1) * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
		*ptr = '-';
	if (n == 0)
		*ptr = '0';
	*(ptr + lenghtint(n)) = '\0';
	while (n != 0)
	{
		if (n < 0)
			*(ptr + lenghtint(n) - 1) = ((n % 10) * -1) + 48;
		else
			*(ptr + lenghtint(n) - 1) = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
