#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>
#include "Location.h"
#include "Obstacle.h"


void Obstacle::initi( std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal )
{
	relocateObstacle( rng, brd, snake, goal );
}

void Obstacle::draw(  Board& brd ) const
{
	brd.drawCell( loc, c );
}

void Obstacle::relocateObstacle( std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal )
{
	std::uniform_int_distribution<int> x_dist( brd.Position( ), brd.getGridWidth( ) - 1 );
	std::uniform_int_distribution<int> y_dist( brd.Position( ), brd.getGridHeight( ) - 1 );

	Location new_loc;
	do
	{
		new_loc.x = x_dist( rng );
		new_loc.y = y_dist( rng );
	} while ( snake.tileEmpty( new_loc )|| loc == new_loc || new_loc == goal.location());

	loc = new_loc;
}

bool Obstacle::collisionDetection( const Location& snake_next_loc) const
{
	return loc == snake_next_loc;
}
