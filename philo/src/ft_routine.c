/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:55:03 by davidga2          #+#    #+#             */
/*   Updated: 2023/11/19 21:07:17 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep()
{

}

void	ft_think()
{

}

void	ft_eat()
{

}

int		ft_its_death(int time_alive)
{
	if (time_alive >= time_to_die)
		return (kill);
	else
		return (0);
}

void	*ft_routine(void *arg)
{
	if (ft_its_death == 0)
		ft_eat();
	else
		return (death);
	
	if (ft_its_death == 0)
		ft_think();
	else
		death;

	if (ft_its_death == 0)
		ft_sleep();
	else
		death;

	return (NULL);
}
