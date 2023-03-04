#pragma once

class Location
{
public:
	int x;
	int y;

public:
	void Add( const Location& val )
	{
		x += val.x;
		y += val.y;
	}
	bool operator==( const Location& rhs )const
	{
		return x == rhs.x && y == rhs.y;
	}
};

