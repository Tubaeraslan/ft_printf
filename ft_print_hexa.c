/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:27:46 by teraslan          #+#    #+#             */
/*   Updated: 2024/11/04 14:15:43 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned long n, char c, size_t *counter)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_print_char('0', counter);
		return ;
	}
	if (n < 16)
	{
		ft_print_char(hex[n], counter);
	}
	else
	{
		ft_print_hexa(n / 16, c, counter);
		ft_print_hexa(n % 16, c, counter);
	}
}
