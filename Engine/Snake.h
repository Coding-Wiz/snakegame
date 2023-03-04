#pragma once
#include "Board.h"
//#include "Goal.h"
//#include "Obstacle.h"
#include <random>

class Snake
{
	// class segment
private:
	class Segment
	{
		// data members segment
	private:
		Location loc{};
		Color c{};

		// method members for segment
	public:
		const Location& location()const
		{
			return loc;
		}
		void initHead( const Location& loc );
		void initBody(const int segments);
		void follow( const Segment& next );
		void moveBy( const Location& delta_loc );
		void edgeWarp( Board& brd );
		//bool goalDetection( const Goal& goal )const;
		void draw( Board& brd );
	};

	// data members for snake
private:
	static constexpr Color head_color = Colors::Green;
	static constexpr int n_segment_max = 100;
	Segment segments[n_segment_max]{};
	int n_segments = 1;

	// constructor & destructor 
public:
	Snake( const Location& loc );
	~Snake( );

	// method members 
	void moveBy( const Location& delta_loc );
	void grow(  );
	void edgeWarp( Board& brd );
	void draw( Board& brd );
	//bool goalDetection( const Goal& goal)const;
	 Location NextLocation( const Location& delta_loc );
	bool selfDetection( const Location& target )const;
	bool tileEmpty( const Location& target )const;
};