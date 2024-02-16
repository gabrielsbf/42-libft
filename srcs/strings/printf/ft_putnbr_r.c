/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:16:42 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:19:59 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_putnbr_r(int n, int fd, int *result)
{
	if (n == -2147483648)
	{
		ft_putchar_r('-', fd, result);
		ft_putchar_r('2', fd, result);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_r('-', fd, result);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_r(n / 10, fd, result);
		ft_putnbr_r(n % 10, fd, result);
	}
	else
	{
		ft_putchar_r(n + '0', fd, result);
	}
}