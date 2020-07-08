/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/05/26 00:01:46 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	va_list			va;
	int				index;
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	zero : 1;
	unsigned int	space : 1;
	unsigned int	octotorp : 1;
	int				width;
	int				accuracy;
	int				arg_len;
	char			type;
	char			*arg;
	int				return_sum;
} s_data;

void	itoa_10(int n, s_data *data)
{
    unsigned int    number;
    int             i;
    
    data->arg = malloc(11 * sizeof(char));
    i = 2;
    if (n < 0)
      data->arg[0] = '-';
    else if (data->plus == 1)
        data->arg[0] = '+';
    else i = 1;
    number = n >= 0 ? n : -n;
    while (n /= 10)
        i++;
	data->arg_len = i;
    data->arg[i] = '\0';
    while (number != 0 || n < 1)
    {
        data->arg[--i] = number % 10 + '0';
        number /= 10;
        n++;
    }
//    return (data->arg);
}

void    main()
{
	s_data data;
	data.plus = 0;
	itoa_10(0, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(1, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(-1, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(123, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(-123, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	data.plus = 1;
	itoa_10(0, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(1, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(-1, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(123, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
	itoa_10(-123, &data);
    printf("%s\n", data.arg);
	printf("len = %d\n", data.arg_len);
	free(data.arg);
//	printf("%s\n", itoa_10(0, &data));
//	printf("%s\n", itoa_10(1, &data));
//	printf("%s\n", itoa_10(1, &data));
//	printf("%s\n", itoa_10(-1, &data));
//	printf("%s\n", itoa_10(123, &data));
//	printf("%s\n", itoa_10(123, &data));
//	printf("%s\n", itoa_10(-123, &data));
//	printf("%s\n", itoa_10(-123, &data));
//	printf("%s\n", itoa_10(12545, &data));
//	printf("%s\n", itoa_10(12345, &data));
}