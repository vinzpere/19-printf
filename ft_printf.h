/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpere <vpere@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:28:59 by vpere             #+#    #+#             */
/*   Updated: 2024/06/07 17:20:24 by vpere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libc.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	c_printf(int c);
int	s_printf(char *str);
int	int_printf(int nbr, char *base);
int	p_printf(void *ptr);
int	x_printf(unsigned int nbr, char *base);
int	u_printf(unsigned int n, char *base);

#endif