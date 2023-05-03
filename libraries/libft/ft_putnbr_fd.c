/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:33:27 by mlindenm          #+#    #+#             */
/*   Updated: 2022/05/09 15:33:21 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_error(int nbr, int fb);
static int		nbr_length(int nbr);
static void		print_int_array(int numbers[], int len, int fb);

void	ft_putnbr_fd(int n, int fd)
{
	int	temp[10];
	int	temp_nbr;
	int	i;

	temp_nbr = 0;
	i = 0;
	if (check_error(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	temp_nbr = n;
	i = nbr_length(n) - 1;
	while (i >= 0)
	{
		temp[i] = temp_nbr % 10;
		temp_nbr /= 10;
		i--;
	}
	print_int_array(temp, nbr_length(n), fd);
}

static int	check_error(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

static int	nbr_length(int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	print_int_array(int numbers[], int len, int fd)
{
	char	c;
	int		i;

	i = 0;
	while (len > 0)
	{
		c = numbers[i] + '0';
		write(fd, &c, 1);
		len--;
		i++;
	}
}
