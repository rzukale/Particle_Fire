/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:43:24 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 19:51:40 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace fire {

	struct Particle {
		double m_x;
		double m_y;
	public:
		Particle();
		~Particle();
	};
}

#endif