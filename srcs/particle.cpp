/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:46:11 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 21:13:09 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire {
	Particle::Particle() : m_x(0), m_y(0) {
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.0001 * rand()) / RAND_MAX;
	}
	Particle::~Particle() {}
	void Particle::Update(int DeltaTime) {
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * DeltaTime;
		m_y += yspeed * DeltaTime;
	}
}