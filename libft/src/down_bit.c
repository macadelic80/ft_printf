/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:08:45 by aben-azz          #+#    #+#             */
/*   Updated: 2018/12/01 09:17:47 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bits	down_bit(t_bits i, t_bits n)
{
	return (n & ~(1 << i));
}
