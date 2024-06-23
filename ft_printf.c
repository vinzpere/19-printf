/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:15:31 by vpere             #+#    #+#             */
/*   Updated: 2024/06/07 17:48:23 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	redir(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += c_printf(va_arg(ap, int));
	else if (c == 's')
		i += s_printf(va_arg(ap, char *));
	else if (c == 'p')
		i += p_printf(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		i += int_printf(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		i += u_printf(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		i += x_printf(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		i += x_printf(va_arg(ap, int), "0123456789ABCDEF");
	else
		i += write(1, &c, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += redir(format[i + 1], ap);
			i++;
		}
		else if (format[i] != '%')
		{
			count += (write(1, &format[i], 1));
		}
		i++;
	}
	return (va_end(ap), count);
}

// int	main(void)
// {
// 	char *s;
// 	int n = -5;

// 	s = "mdr";
// 	ft_printf("nb %d\n", ft_printf("moi : <%s>\n", s));
// 	printf("nb %d\n", printf("toi : <%s>\n", s));
// 	ft_printf("nb %d\n", ft_printf("moi : <%c>\n", *s));
// 	printf("nb %d\n", printf("toi : <%c>\n", *s));
// 	ft_printf("nb %d\n", ft_printf("moi : <%d>\n", n));
// 	printf("nb %d\n", printf("toi : <%d>\n", n));
// 	ft_printf("nb %d\n", ft_printf("moi : <%i>\n", n));
// 	printf("nb %d\n", printf("toi : <%i>\n", n));
// 	ft_printf("nb %d\n", ft_printf("moi : <%u>\n", 500));
// 	printf("nb %d\n", printf("toi : <%u>\n", 500));
// 	ft_printf("nb %d\n", ft_printf("moi : <%x>\n", n));
// 	printf("nb %d\n", printf("toi : <%x>\n", n));
// 	ft_printf("nb %d\n", ft_printf("moi : <%X>\n", n));
// 	printf("nb %d\n", printf("toi : <%X>\n", n));
// 	ft_printf("nb %d\n", ft_printf("moi : <%p>\n", n));
// 	printf("nb %d\n", printf("toi : <%p>\n", n));
// 	ft_printf("nb %d\n", ft_printf(""));
// 	printf("nb %d\n", printf(""));
// }