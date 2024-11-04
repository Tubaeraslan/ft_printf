/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:49 by teraslan          #+#    #+#             */
/*   Updated: 2024/11/04 11:55:00 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

void	ft_print_int(int n, size_t *counter)
{
	char	*num;

	if (n == 0)
	{
		write(1, "0", 1);
		(*counter)++;
	}
	else
	{
		num = ft_itoa(n);
		ft_print_str(num, counter);
		free(num);
	}
}
