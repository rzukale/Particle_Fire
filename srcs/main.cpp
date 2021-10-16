/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:53:05 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:26:57 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.Init() == false) {
		cout << "SDL Init failed" << endl;
		return EXIT_FAILURE;
	}

	Swarm swarm;

	while (true) {
		if (screen.ProcessEvents() == false) {
			break;
		}
		int elapsed = SDL_GetTicks();
		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		const Particle * const pParticles = swarm.GetParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH * 0.5);
			int y = (particle.m_y + 1) * (Screen::SCREEN_HEIGHT * 0.5);
			screen.SetPixel(x, y, red, green, blue);
		}



		// for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
		// 	for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
		// 		screen.SetPixel(x, y, red, green, blue);
		// 	}
		// }
		screen.Update(); // update particles

		// draw particles
		// check for messages/events

	}
	screen.Close();
	return EXIT_SUCCESS;
}