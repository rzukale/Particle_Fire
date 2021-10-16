/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:46:11 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 19:49:52 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire {
	Particle::Particle() {
		m_x = ((2.0 * rand())/RAND_MAX) - 1;
		m_y = ((2.0 * rand())/RAND_MAX) - 1;

	}
	Particle::~Particle() {}
}