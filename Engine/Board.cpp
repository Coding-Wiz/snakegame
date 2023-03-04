#include "Board.h"

Board::Board( Graphics& gfx )
	: gfx( gfx )
{
}
Board::~Board( )
{
}
void Board::drawBoarder( )const
{
	const int TOP = Y;
	const int LEFT = X;
	const int BOTTOM = TOP + ( BORDER_WIDTH + BORDER_PADDING ) * 2 + HEIGHT *DIMENSION;
	const int RIGHT = LEFT+ ( BORDER_WIDTH + BORDER_PADDING ) * 2 + WIDTH*DIMENSION;

	// top
	gfx.DrawRect( LEFT, TOP, RIGHT, TOP + BORDER_WIDTH, BORDER_COLOR );
	// left 
	gfx.DrawRect( LEFT, TOP + BORDER_WIDTH, LEFT+ BORDER_WIDTH, BOTTOM-BORDER_WIDTH, BORDER_COLOR );
	// right
	gfx.DrawRect( RIGHT, TOP + BORDER_WIDTH-4, RIGHT + BORDER_WIDTH, BOTTOM - BORDER_WIDTH + 4, BORDER_COLOR );
	// bottom
	gfx.DrawRect( LEFT, BOTTOM - BORDER_WIDTH, RIGHT, BOTTOM, BORDER_COLOR );
}
void Board::drawCell( const Location loc, Color c )
{
	assert( loc.x >= POSITION );
	assert( loc.x < WIDTH );
	assert( loc.y >= POSITION );
	assert( loc.y < HEIGHT );

	const int OFF_X = loc.x + BORDER_WIDTH + BORDER_PADDING;
	const int OFF_Y = loc.y + BORDER_WIDTH + BORDER_PADDING;

	gfx.DrawRectDim( loc.x * DIMENSION + OFF_X+CELL_PADDING, loc.y * DIMENSION+OFF_Y+CELL_PADDING, DIMENSION-CELL_PADDING*2, DIMENSION- CELL_PADDING * 2, c );
}
bool Board::boardBorder( const Location & loc ) const
{
	return loc.x >= POSITION && loc.x < WIDTH && loc.y >= POSITION && loc.y < HEIGHT;
}
void Board::edgeWarp( Location & loc )
{
	if ( loc.x < POSITION )
		loc.x = WIDTH - 1;

	if ( loc.x >= WIDTH )
		loc.x = POSITION;

	if ( loc.y < POSITION )
		loc.y = HEIGHT - 1;

	if ( loc.y >= HEIGHT )
		loc.y = POSITION;
}
int Board::getDimension( )const
{
	return DIMENSION;
}
int Board::getGridWidth( )const
{
	return WIDTH;
}
int Board::getGridHeight( )const
{
	return HEIGHT;
}
int Board::Position( )const
{
	return POSITION;
}