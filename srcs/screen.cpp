/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:31:23 by rzukale           #+#    #+#             */
/*   Updated: 2021/10/16 20:38:03 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/particle_fire.h"

namespace fire
{
	Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {}
	Screen::~Screen() {}
	bool Screen::Init()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		{
			cout << SDL_GetError() << endl;
			return false;
		}
		m_window = SDL_CreateWindow("Particle Fire",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!m_window)
		{
			cout << SDL_GetError() << endl;
			SDL_Quit();
			return false;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		if (!m_renderer)
		{
			cout << SDL_GetError() << endl;
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!m_texture)
		{
			cout << SDL_GetError() << endl;
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		if (!m_buffer)
		{
			cout << "Buffer creation failed" << endl;
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyTexture(m_texture);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		SDL_memset4(m_buffer, 0x00000000, SCREEN_WIDTH * SCREEN_HEIGHT);
		return true;
	}
	bool Screen::ProcessEvents()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
				return false;
		}
		return true;
	}
	void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
			return ;
		this->m_buffer[y * SCREEN_WIDTH + x] = ((red << 24) | (green << 16) | (blue << 8) | (0xFF));
	}
	void Screen::Update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}
	void Screen::Close()
	{
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
	void Screen::Clear() {
		SDL_memset4(m_buffer, 0x00000000, SCREEN_WIDTH * SCREEN_HEIGHT);
	}
}