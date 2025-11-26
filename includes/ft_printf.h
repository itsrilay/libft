/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:45:18 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:28:03 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ftpf_putchar_fd(int fd, const char c, int *count);
int	ftpf_putstr_fd(int fd, const char *str, int *count);
int	ftpf_putnbr_fd(int fd, int num, int *count);
int	ftpf_putnbr_unsigned_fd(int fd, unsigned int num, int *count);
int	ftpf_base16_fd(int fd, unsigned long num, const char *base, int *count);
int	ftpf_putptr_fd(int fd, void *ptr, int *count);
int	print_specifier_fd(int fd, va_list *args, char specifier, int *count);

#endif