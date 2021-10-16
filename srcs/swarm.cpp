/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swarm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:57:31 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:34:32 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire
{
	Swarm::Swarm() {
		m_Particles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm() {
		delete [] m_Particles;
	}
	void Swarm::Update() {
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_Particles[i].Update();
		}
	}
}