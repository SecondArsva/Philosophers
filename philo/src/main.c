/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:26:06 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/06 12:52:26 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Función para comprobar que los argumentos introducidos son numéricos.
int ft_check_args_isallnum(char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '+' || argv[i][j] == '-' || ft_isdigit(argv[i][j]))
			j++;
		else
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 6)
	{
		if (ft_check_args_isallnum(argv) == 0)
			return (printf("philo: invalid arguments\n"), 0);
		printf("%s %s %s %s %s %s\n",
			argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
	}
	else
		return (printf("philo: invalid arguments\n"), 0);
	función de encapsulación de los argumentos en variables de una estructura.
	return (0);
}
