/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:39:50 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/24 00:28:16 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_global
{
	size_t			n_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat;
	//pthread_t		th[number_of_philos];
	//pthread_mutex_t mutex[number_of_philos];
}				t_global;

typedef struct	s_philo
{
	size_t			id;
	pthread_t		th;
	pthread_mutex_t	mutex;
	pthread_mutex_t *next_mutex;
	size_t			times_eated;
	struct s_philo	*next;
}				t_philo;

int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	*ft_routine(void *arg);

#endif
