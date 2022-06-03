#include "Piece.h"
#include "Board.h"

Piece::Piece(const Location& location, Board* board, Color color, const char c)
	: m_location(location), m_board(board), m_color(color), m_char(c)
{
}
//-----------------------------------------
bool Piece::checkOnOpponent(const Location& source, const Location& dest)
{
	Location kingOpponentLocation = m_board->getOpponentKingLocation(m_color);
	return isLegalMove(source, dest) && isLegalMove(dest, kingOpponentLocation);
}
//---------------------------------
bool Piece::checkOnOpponent(const Location& source)
{
	Location kingOpponentLocation = m_board->getOpponentKingLocation(m_color);
	return isLegalMove(source, kingOpponentLocation);
}
//---------------------------------
void Piece::setLocation(const Location& dest)
{
	m_location = dest;
}
//----------------------------
Location Piece::getLocation() const
{
	return m_location;
}
//------------------------
Color Piece::getColor() const
{
	return m_color;
}
//---------------------------
char Piece::getChar() const
{
	return m_char;
}
//-----------------------------
