/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:25:59 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:05:48 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "./includes/libft.h"

int		ft_printf(int fd, const char *format, ...);
int		ft_putbase_fd_lower(unsigned int n, int fd);
int		ft_putnbr_fd_unsigned(unsigned int n, int fd);
int		ft_putbase_fd(unsigned int n, int fd);
int		ft_putadress(void *ptr, int fd);

#endif