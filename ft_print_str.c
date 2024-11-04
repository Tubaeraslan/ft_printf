/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:57:42 by teraslan          #+#    #+#             */
/*   Updated: 2024/11/04 14:13:10 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, size_t *counter)
{
	int	i;

	if (str == NULL)
	{
		ft_print_str("(null)", counter);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		(*counter)++;
		i++;
	}
}
