/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:23:34 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/23 23:44:28 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*ft_philonew(void)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo) * 1);
	if (!new_philo)
		return (0);
	new_philo->id = 0;
	new_philo->th = NULL;
	new_philo->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!new_philo->mutex)
		return (free(new_philo), 0);
	pthread_mutex_init(new_philo->mutex, NULL);
	new_philo->next_mutex = NULL;
	new_philo->times_eated = 0;
	new_philo->next = NULL;
	return (new_philo);
}

void	ft_philoadd_front(t_philo **list, t_philo *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

t_philo *ft_create_table(size_t n_philos)
{
	t_philo	*new_list;

	new_list = NULL;
	while (n_philos > 0)
	{
		ft_philoadd_front(&new_list, ft_philonew());
		n_philos--;
	}
	return (new_list);
}

void	ft_print_dinners(t_philo *list, size_t n_philos)
{
	size_t	i;

	i = 0;
	while (i < n_philos)
	{
		printf("Diner %zu:\n", i);
		printf("	ID:			%lu\n", list->id);
		printf("	Thread:		%lu\n", list->th);
		printf("	My fork:	%p\n", (void *) list->mutex);
		printf("	Next fork:	%p\n", (void *) list->next_mutex);
		printf("	Time eated:	%lu\n", list->times_eated);
		printf("	Next node:	%p\n", list->next);
		list = list->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*list_philo;
	int		n_philos;

	if (argc == 2)
	{
		n_philos = atoi(argv[1]);
		list_philo = ft_create_table(n_philos);
		ft_print_dinners(list_philo, n_philos);
	}
	else
		printf("text: invalid argument. Needs an int for create the nodes\n");
	return (0);
}
