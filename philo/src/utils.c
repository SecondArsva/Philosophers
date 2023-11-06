/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:32:55 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/06 11:56:03 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int result;
	int sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0'); 
		i++;
	}
	return (result * sign);
}

void *ft_calloc(size_t count, size_t size)
{
	void	*new_allocation;

	new_allocation = (void *) malloc(count * size);
	if (!new_allocation)
		return (NULL);
	memset(new_allocation, 0, count * size);
	return (new_allocation);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	*str1 = "\n\t\v\f\r -13";
	char	*str2 = "\n\t\v\f\r -288a1";
	char	*str3 = "\n\t\v\f\r +-288";
	char	*str4 = "Has visto a cmatelloc-?";
	char	*str5;
	int		i = 0;
	int		counter = 0;

	printf("%i\n", ft_atoi(str1));
	printf("%i\n", ft_atoi(str2));
	printf("%i\n", ft_atoi(str3));
	printf("\n");
	while (str4[i])
	{
		printf("%c - %p\n", str4[i], &str4[i]);
		i++;
	}
	printf("\n");
	counter = i;
	i = 0;
	str5 = ft_calloc(counter, sizeof(char));
	while (i <= counter)
	{
		printf("%i - %p\n", str5[i], &str5[i]);
		i++;
	}
	i = 0;
	while (i <= counter)
	{
		str5[i] = str4[i];
		i++;
	}
	printf("\n");
	i = 0;
	while (i <= counter)
	{
		printf("%c - %p\n", str5[i], &str5[i]);
		i++;
	}
	return (0);
}*/
