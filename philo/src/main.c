/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:26:06 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/24 00:43:37 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Encapsula los argumentos en la estructura "global" convirtiéndolos en int.
void	ft_encapsulate_args(int argc, char **argv, t_global **global)
{
	(*global)->n_philos = ft_atoi(argv[1]);
	(*global)->time_to_die = ft_atoi(argv[2]);
	(*global)->time_to_eat = ft_atoi(argv[3]);
	(*global)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*global)->must_eat = ft_atoi(argv[5]);
	else
		(*global)->must_eat = 0;
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

// Verifica que haya solo 5 o 6 argumentos introducidos y que sean numéricos.
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

void *ft_routine(void *arg)
{
	arg = NULL;
	printf("Hola\n");
	return (NULL);
}

int	ft_philo(t_global *global)
{
	size_t				i;
	pthread_t		*th;
	pthread_mutex_t	*mutex;
	int				*death;

	i = 0;
	th = malloc(sizeof(pthread_t) * global->n_philos);
	if (!th)
		return (0);
	mutex = malloc(sizeof(pthread_mutex_t) * global->n_philos);
	if (!mutex)
		return (free(th), 0);
	while (i < global->n_philos)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < global->n_philos)
	{
		pthread_create(&th[i], NULL, &ft_routine, (void *)global);
		i++;
	}
	i = 0;
	while (i < global->n_philos)
	{
		pthread_join(th[i], (void **)&death);
		i++;
	}
	i = 0;
	while (i < global->n_philos)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_global *global;

	if (ft_check_args(argc, argv) != 0)
		return (1);
	global = malloc(sizeof(t_global));
	ft_encapsulate_args(argc, argv, &global);
	printf("STRUCT:\n%zu\n%zu\n%zu\n%zu\n%zu\n",
			global->n_philos, global->time_to_die, global->time_to_eat,
			global->time_to_sleep, global->must_eat);
	if (ft_philo(global) == 0)
		return (1);
	return (0);
}
