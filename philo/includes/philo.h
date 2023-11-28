/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:39:50 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/28 17:59:32 by davidga2         ###   ########.fr       */
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
	pthread_t		th_reaper;
	pthread_t		*th_philo;
	pthread_mutex_t	*fork;
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
	int				im_dead;
}				t_philo;

int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	*ft_routine(void *arg);

#endif

// Resvisando el philo de jvasquez junto a él me ha enseñado que
// efectivamentemente tiene un hilo que revisa que los demás hilos, los
// filósofos, no hayan muerto. Este "segador" revisa constantemente que no
// haya ninguno muerto y en caso de morir alguno se asegura de matar a todos
// los demás comensales.
//
// Cada filósofo se hace responsable de notificar su muerte. Tienen una
// variable que, en caso de exceder el tiempo de vida permitido, cambiarán
// para hacerle saber al "segador" que murió.
//
// Todas las acciones que tienen permitidas hacer los filósofos se limitarán
// a dicha variable. Si un filósofo se hace con los tenedores y come, deberá
// asegurarse de seguir con vida mientras lo hace, ya que su tiempo de vida no
// será ampliado/reiniciado hasta que no termine de comer. De igual forma
// deberá "despertarse" durante el sueño para comprobar que no ha muerto
// mientras duerme. No duermen "time_to_sleep" de seguido, sino que la acción
// de dormir la desarrolla en lapsos de "usleep(50)" entre los que el propio
// filósofo comprueba que sige con vida, para que en caso de morir
// notificarlo.
//
// Tiene una versátil función para gestionar las acciones que recibe tres
// argumentos "ft_accion()" uno de ellos es el mensaje a escribir.
