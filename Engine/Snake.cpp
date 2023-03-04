#include "Snake.h"
#include <assert.h>

Snake::Snake( const Location& loc )
{
	segments[0].initHead( loc );
}
Snake::~Snake( )
{
}
void Snake::moveBy( const Location& delta_loc )
{
	for ( int i = n_segments - 1; i > 0; --i )
	{
		segments[i].follow( segments[i - 1] );
	}
	segments[0].moveBy( delta_loc );
}
void Snake::grow( )
{
	if ( n_segments < n_segment_max )
		segments[n_segments].initBody(n_segments );
	++n_segments;
}

void Snake::edgeWarp( Board& brd )
{
	segments[0].edgeWarp( brd );
}

void Snake::draw( Board & brd )
{
	for ( int i = 0; i < n_segments; ++i )
	{
		segments[i].draw( brd );
	}
}

//bool Snake::goalDetection( const Goal & goal)const
//{
//	return segments[0].goalDetection( goal);
//}

 Location Snake::NextLocation( const Location& delta_loc )
{
	Location l( segments[0].location( ) );
	l.Add( delta_loc );
	return l;
}
bool Snake::selfDetection(const Location& target)const
{
	for ( int i = 0; i < n_segments-1; ++i )
	{
		if ( segments[i].location( ) == target )
			return true;
		/*if( segments[0].location( ) == segments[i+1].location( ) )
			return true;*/
	}
	return false;
}

bool Snake::tileEmpty( const Location& target )const
{
	for ( int i = 0; i < n_segments ; i++ )
	{
		if ( segments[i].location( ) == target )
			return true;
	}
	return false;
}

void Snake::Segment::initHead( const Location & loc )
{
	this->loc = loc;
	c = Snake::head_color;
}
void Snake::Segment::initBody( const int segments )
{
	for ( int i = 0; i < segments; i++ )
	{
		if((i%2)==0)
			c = Colors::Gray;
		else
			c = Colors::White;
	}
}
void Snake::Segment::follow( const Segment & next )
{
	loc = next.loc;
}
void Snake::Segment::moveBy( const Location & delta_loc )
{
	assert( abs( delta_loc.x ) + abs( delta_loc.y ) == 1 );
	loc.Add( delta_loc );
}
void Snake::Segment::edgeWarp( Board & brd )
{
	brd.edgeWarp( loc );
}
//bool Snake::Segment::goalDetection( const Goal & goal)const
//{
//	int goal_x = goal.getX( );
//	int goal_y = goal.getY( );
//
//	return loc.x == goal_x && loc.y == goal_y;
//}

void Snake::Segment::draw( Board & brd )
{
	brd.drawCell( loc, c );
}