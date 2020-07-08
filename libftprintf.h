/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:22:02 by sedric            #+#    #+#             */
/*   Updated: 2020/07/02 15:35:56 by sedric           ###   ########.fr       */
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

typedef struct
{
	va_list			va;
	int				index;
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	zero : 1;
	unsigned int	space : 1;
	unsigned int	octotorp : 1;
	unsigned int	error : 1;
	int				width;
	int				accuracy;
	char			type;
	char			*arg;
	int				arg_len;
	int				return_sum;
} s_data;

/* void	*ft_memset(void *str, int symbol, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memccpy(void *dest, const void *src, int symbol, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *arr, int symbol, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t len_dest);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd); */
int		ft_printf(const char *s, ...);
char	*ft_itoa(int n);
void	ft_putstr_pf(s_data* data);
size_t	ft_strlen(const char* s);
char*	ft_strchr(const char* s, int c);
void	ft_symb_arg(int symnol, s_data* data);
void	ft_width_set(s_data* data);
void* ft_memcpy(void* dest, const void* src, size_t n);
void	ft_string_arg(char* string, s_data* data);
//char    *ft_itoa(int n);

#endif
