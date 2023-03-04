#pragma once


class Obstacle
{
private:
	Location loc{};
	Color c = Colors::Red;
public:
	void initi( std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal );

public:
	void draw( Board& brd )const;
	void relocateObstacle( std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal);
	bool collisionDetection( const Location& loc )const;
};

