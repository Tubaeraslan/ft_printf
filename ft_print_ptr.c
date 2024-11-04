/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:34:19 by teraslan          #+#    #+#             */
/*   Updated: 2024/11/04 15:03:27 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long ptr, size_t *count)
{
	if (ptr == 0)
	{
		ft_print_str("(null)", count);
	}
	else
	{
		ft_print_str("0x", count);
		ft_print_hexa(ptr, 'x', count);
	}
}
