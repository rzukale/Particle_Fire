/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:43:24 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:46:47 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace fire {

	struct Particle {
		double m_x;
		double m_y;
		double m_xSpeed;
		double m_ySpeed;

	public:
		Particle();
		~Particle();
		void Update();
	};
}

#endif