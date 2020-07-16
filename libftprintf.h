/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:22:02 by sedric            #+#    #+#             */
/*   Updated: 2020/07/17 00:21:29 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define FLAGS "-0# +"
# define DIGIT "0123456789"

typedef	struct		s_data
{
	va_list			va;
	int				index;
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	zero : 1;
	unsigned int	space : 1;
	unsigned int	octotorp : 1;
	unsigned int	error : 1;
	unsigned int	zero_type : 1;
	unsigned int	conversion : 4;
	int				width;
	int				accuracy;
	char			type;
	char			*arg;
	int				arg_len;
	int				return_sum;
}					t_data;

int					ft_printf(const char *s, ...);
int					ft_s_parsing(const char *s, t_data *data);
void				*ft_memset(void *str, int symbol, size_t n);
void				ft_putstr_pf(t_data *data);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
void				ft_symb_arg(int symnol, t_data *data);
void				ft_width_set(t_data *data, char symbol);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_string_arg(char *string, t_data *data);
int					ft_get_arg(t_data *data);
void				itoa_10(long long int value, t_data *data);
void				itoa_u(unsigned long long int val, int base,
					t_data *data, char *s);

#endif
