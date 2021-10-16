/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:43:24 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 22:08:11 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace fire {

	struct Particle {
		double m_x;
		double m_y;
		double m_speed;
		double m_direction;

	private:
		void Init();

	public:
		Particle();
		~Particle();
		void Update(int DeltaTime);
	};
}

#endif