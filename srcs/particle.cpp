/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:46:11 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:50:07 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire {
	Particle::Particle() {
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;

		m_xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
		m_ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);

	}
	Particle::~Particle() {}
	void Particle::Update() {

		m_x += m_xSpeed;
		m_y += m_ySpeed;

		if (m_x <= -1.0 || m_x >= 1.0)
			m_xSpeed = -m_xSpeed;
		if (m_y <= -1.0 || m_y >= 1.0)
			m_ySpeed = -m_ySpeed;
	}
}