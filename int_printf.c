/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:08:13 by vpere             #+#    #+#             */
/*   Updated: 2024/05/31 18:32:24 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive(int nb, int baselen, char *base)
{
	char	symbol;
	int		count;

	count = 0;
	if (nb >= baselen)
		count += recursive(nb / baselen, baselen, base);
	symbol = base[nb % baselen];
	count += write(1, &symbol, 1);
	return (count);
}

int	int_printf(int nbr, char *base)
{
	int	baselen;
	int	count;

	baselen = 0;
	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	while (base[baselen])
		baselen++;
	if (nbr < 0)
	{
		nbr *= -1;
		count += write(1, "-", 1);
	}
	count += (recursive(nbr, baselen, base));
	return (count);
}

// int	main(void)
// {
// 	printf("\n%d", int_printf(-2147321321, "0123456789abcdef"));
// }