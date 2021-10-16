/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:26:49 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:37:41 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H_
#define SCREEN_H_

namespace fire
{

	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	private:
		const static short RED_SHIFT = 24;
		const static short GREEN_SHIFT = 16;
		const static short BLUE_SHIFT = 8;
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;

	public:
		Screen();
		~Screen();
		bool Init();
		bool ProcessEvents();
		void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void Close();
		void Update();
		void Clear();
	};
}
#endif