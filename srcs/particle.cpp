/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:46:11 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 22:11:17 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire {
	Particle::Particle() : m_x(0), m_y(0) {
		Init();
	}
	Particle::~Particle() {}
	void Particle::Init() {
		m_x = 0;
		m_y = 0;
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}
	void Particle::Update(int DeltaTime) {

		m_direction += DeltaTime * 0.0002;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * DeltaTime;
		m_y += yspeed * DeltaTime;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			Init();
		}
		if (rand() < RAND_MAX / 100) {
			Init();
		}
	}
}