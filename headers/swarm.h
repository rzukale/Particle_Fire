/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swarm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:55:36 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:50:13 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWARM_H_
#define SWARM_H_

#include "particle.h"

namespace fire
{
	class Swarm {
	private:
		Particle *m_Particles;
	public:
		const static int NPARTICLES = 1000;
	public:
		Swarm();
		~Swarm();
		Particle *GetParticles() { return m_Particles; };
		void Update();
	};
}

#endif