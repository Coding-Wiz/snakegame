#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>


class Board
{
	// data members
private:
	static constexpr int  BORDER_WIDTH = 4;
	static constexpr int  BORDER_PADDING = 2;
	static constexpr int  CELL_PADDING = 1;
	static constexpr Color BORDER_COLOR  = Colors::Cyan;
	static constexpr int DIMENSION = 15;
	static constexpr int WIDTH = 39;
	static constexpr int HEIGHT = 30;
	static constexpr int POSITION = 2;
	static constexpr int X = 34;
	static constexpr int Y = 30;
	Graphics& gfx;

	// constructor & destructor
public:
	Board( Graphics& gfx );
	~Board( );

	// method members
public:
	void drawBoarder( )const;
	void drawCell( const Location loc, Color c );
	void edgeWarp( Location& loc );
	bool boardBorder( const Location& loc )const;

public:
	int getDimension( )const;
	int getGridWidth( )const;
	int getGridHeight( )const;
	int Position( )const;
};