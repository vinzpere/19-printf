/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:08:13 by vpere             #+#    #+#             */
/*   Updated: 2024/05/31 18:32:42 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	precursive(unsigned int nb, unsigned int baselen, char *base)
{
	char	symbol;
	int		count;

	count = 0;
	if (nb >= baselen)
		count += precursive(nb / baselen, baselen, base);
	symbol = base[nb % baselen];
	count += write(1, &symbol, 1);
	return (count);
}

int	x_printf(unsigned int nbr, char *base)
{
	unsigned int	baselen;
	int				count;

	baselen = 0;
	count = 0;
	while (base[baselen])
		baselen++;
	count += (precursive(nbr, baselen, base));
	return (count);
}

// int	main(void)
// {
// 	printf("\n%d", int_printf(-2147321321, "0123456789abcdef"));
// }