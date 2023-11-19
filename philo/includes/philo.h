/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:39:50 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/19 20:59:24 by davidga2         ###   ########.fr       */
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

typedef struct	s_world
{
	int				total_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	//pthread_t		th[number_of_philos];
	//pthread_mutex_t mutex[number_of_philos];
}				t_world;

typedef struct	s_philo
{
	int			identifier;
	int			times_eated;	
}				t_philo;

int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);

#endif
