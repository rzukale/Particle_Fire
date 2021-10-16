/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swarm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:31 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 21:11:56 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire
{
	Swarm::Swarm(): LastTime(0) {
		m_Particles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm() {
		delete [] m_Particles;
	}
	void Swarm::Update(int elapsed) {
		int DeltaTime = elapsed - LastTime;
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_Particles[i].Update(DeltaTime);
		}
		LastTime = elapsed;
	}
}