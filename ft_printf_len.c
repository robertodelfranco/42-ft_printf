/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:42:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/25 17:54:50 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_hexa_len(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(void *ptr)
{
	write(1, ptr, ft_hexa_len((unsigned long)ptr));
}

void	ft_putnbr_base(unsigned long nb)
{
	if (nb > 15)
	{
		ft_putnbr_base(nb / 16);
		ft_putnbr_base(nb % 16);
	}
	else
	{
		if (nb >= 10)
			ft_putchar_fd(nb - 10 + 'a', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}

void	ft_putnbr_base_upper(unsigned long nb)
{
	if (nb > 15)
	{
		ft_putnbr_base_upper(nb / 16);
		ft_putnbr_base_upper(nb % 16);
	}
	else
	{
		if (nb >= 10)
			ft_putchar_fd(nb - 10 + 'A', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}