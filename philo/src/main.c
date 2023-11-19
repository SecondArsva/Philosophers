/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:26:06 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/19 21:07:21 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// verificar que los argv son números
//

void	ft_encapsulate_args(int argc, char **argv, t_world **world)
{
	(*world)->total_philos = ft_atoi(argv[1]);
	(*world)->time_to_die = ft_atoi(argv[2]);
	(*world)->time_to_eat = ft_atoi(argv[3]);
	(*world)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*world)->must_eat = ft_atoi(argv[5]);
	else
		(*world)->must_eat = 0;
}

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
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args_isallnum(argv) != 0)
			return (printf("philo: invalid arguments\n"), 1);
/**/		printf("%s %s %s %s %s %s\n",
			argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
	}
	else
		return (printf("philo: invalid arguments\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_world *world;

	if (ft_check_args(argc, argv) != 0)
		return (1);
	world = malloc(sizeof(t_world));
	ft_encapsulate_args(argc, argv, &world);
	printf("STRUCT:\n%i\n%i\n%i\n%i\n%i\n",
			world->total_philos, world->time_to_die, world->time_to_eat,
			world->time_to_sleep, world->must_eat);
	return (0);
}
