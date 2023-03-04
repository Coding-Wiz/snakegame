/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rd( ),
	rng( rd( ) ),
	x_dist( brd.Position( ), brd.getGridWidth( ) - 1 ),
	y_dist( brd.Position( ), brd.getGridHeight( ) - 1 ),
	brd( gfx ),
	snake( { x_dist( rng ), y_dist( rng ) } ),
	goal( rng, brd, snake)
{
	for ( int i = 0; i < N_OBSTACLE; ++i )
	{
		obstacles[i].initi( rng, brd, snake, goal );
	}
}

void Game::Go( )
{
	gfx.BeginFrame( );
	UpdateModel( );
	ComposeFrame( );
	gfx.EndFrame( );
}
void Game::UpdateModel( )
{
	if ( is_game_started && ( !( is_game_over ) ) )
	{
		if ( wnd.kbd.KeyIsPressed( VK_UP ) )
			delta_loc = { 0, -1 };
		
		if ( wnd.kbd.KeyIsPressed( VK_DOWN ) )
			delta_loc = { 0, 1 };
		
		if ( wnd.kbd.KeyIsPressed( VK_LEFT ) )
			delta_loc = { -1, 0 };

		if ( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
			delta_loc = { 1, 0 };

		++snake_move_counter;
		++obstacle_timer;
		if ( snake_move_counter >= snake_move_rate )
		{
			if ( snake_move_rate <= 0 )
				snake_move_rate = 1;
			snake_move_counter = 0;
			if (snake.tileEmpty(goal.location() ))
			{
				goal.relocateGoal( rng, brd, snake );
				snake.grow( );
				++speed_up;
				if ( snake_move_rate != 1 )
					if ( ( speed_up % 2 ) == 0 )
						snake_move_rate -= 1;
			}
			if ( obstacle_timer >= obstacle_redrawn_rate )
			{
				obstacle_timer = 0;
				if ( ( obstacle_timer % 40 ) == 0 )
					++interval;
			}
			
			snake.moveBy( delta_loc );
		}
		if ( snake.selfDetection(snake.NextLocation(delta_loc)))
			is_game_over = true;

		for ( int i = interval; i < interval + 1; ++i )
			if ( obstacles[i].collisionDetection( snake.NextLocation( delta_loc ) ) )
				is_game_over = true;
		snake.edgeWarp( brd );
	} else
	{
		if ( wnd.kbd.KeyIsPressed( VK_RETURN ) )
			is_game_started = true;
	}
}
void Game::ComposeFrame( )
{
	if ( !is_game_started )
		sprite_codex.DrawTitle( 300, 200, gfx );
	else
	{
		brd.drawBoarder( );
		goal.drawGoal( brd );
		snake.draw( brd );
		for ( int i = 0; i < interval; ++i )
			obstacles[i].draw( brd );	
		
		if ( is_game_over )
			SpriteCodex::DrawGameOver( 300, 200, gfx );
	}
}
