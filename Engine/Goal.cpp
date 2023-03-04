#include "Board.h"
#include "Location.h"
#include <random>
#include "Snake.h"
#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	relocateGoal( rng, brd, snake);
}

void Goal::drawGoal( Board& brd ) const
{
	brd.drawCell( loc, c );
}

void Goal::relocateGoal( std::mt19937& rng, const Board& brd, const Snake& snake )
{
	std::uniform_int_distribution<int> x_dist( brd.Position(), brd.getGridWidth( ) - 1 );
	std::uniform_int_distribution<int> y_dist( brd.Position( ), brd.getGridHeight( ) - 1 );
	
	Location goals_new_loc;
	do
	{
		goals_new_loc.x = x_dist( rng );
		goals_new_loc.y = y_dist( rng );
	} while ( snake.tileEmpty(goals_new_loc ));
	
	loc = goals_new_loc;
}