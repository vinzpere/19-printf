/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:24:05 by vpere             #+#    #+#             */
/*   Updated: 2024/05/31 18:32:40 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive(unsigned int nb, unsigned int baselen, char *base)
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

int	u_printf(unsigned int nbr, char *base)
{
	unsigned int	baselen;
	int				count;

	baselen = 0;
	count = 0;
	while (base[baselen])
		baselen++;
	count += (recursive(nbr, baselen, base));
	return (count);
}

// int	main(void)
// {
// 	u_printf(4294967295);
// 	printf("\n%u", 4294967294);
// }