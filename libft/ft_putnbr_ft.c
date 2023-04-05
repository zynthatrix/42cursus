/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osericol <osericol@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:57:45 by osericol          #+#    #+#             */
/*   Updated: 2023/04/05 16:29:19 by osericol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_ft(int n, int fd)
{
	char	num[11];
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	i = 0;
	while (n > 9)
	{
		num[i++] = '0' + n % 10;
		n /= 10;
	}
	num[i] = '0' + n;
	while (i >= 0)
		write(fd, &num[i--], 1);
}
