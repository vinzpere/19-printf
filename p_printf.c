/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:15:29 by vpere             #+#    #+#             */
/*   Updated: 2024/05/31 18:32:36 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	precursive(unsigned long nb, unsigned long baselen, char *base)
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

static int	converter(unsigned long nbr, char *base)
{
	unsigned long	baselen;
	int				count;

	baselen = 0;
	count = 0;
	while (base[baselen])
		baselen++;
	count += (precursive(nbr, baselen, base));
	return (count);
}

int	p_printf(void *ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += converter((unsigned long)ptr, "0123456789abcdef");
	return (count);
}

// int	main(void)
// {
// 	void	*ptr = 0;

// 	p_printf(ptr);
// 	printf("adresse pointeur : %p", ptr);
// }