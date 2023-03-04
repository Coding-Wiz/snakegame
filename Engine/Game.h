/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Location.h"
#include "SpriteCodex.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go( );
private:
	void ComposeFrame( );
	void UpdateModel( );
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables*/
	// data member for game
private:
	SpriteCodex sprite_codex;
	// data member for snake game
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int>x_dist;
	std::uniform_int_distribution<int>y_dist;
	Board brd;
	Location delta_loc = { 1, 0 };
	Snake snake;
	Goal goal;
	static constexpr int N_OBSTACLE = 150;
	Obstacle obstacles[N_OBSTACLE]{};
	int interval = 0;
	int obstacle_redrawn_rate = 1000;
	int obstacle_timer = 0;
	int snake_move_rate = 20;
	int snake_move_counter = 0;
	int speed_up = 0;
	// data member for game
private:
	bool is_game_started = false;
	bool is_game_over = false;
	/********************************/
};