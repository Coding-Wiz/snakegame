#pragma once


class Goal
{
	// data members
private:
	// data members for random
	Location loc{};
	// constructor & destructor
public:
	Color c = Colors::Cyan;
	Goal( ) = default;
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	
	// method members
public:
	void drawGoal( Board& brd )const;
	void relocateGoal( std::mt19937& rng, const Board& brd, const Snake& snake);
public:
	const Location& location( )const
	{
		return loc;
	}
};

