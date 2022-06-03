#pragma once
#include "Location.h"
#include "Color.h"

class Board;

class Piece
{
public:
	Piece(const Location& location,  Board* board, Color color, const char c);
	virtual ~Piece() = default;

	virtual bool isLegalMove(const Location& source, const Location& dest) = 0;

	bool checkOnOpponent(const Location& source, const Location& dest);
	bool checkOnOpponent(const Location& source);

	//void setLocation(const char destL, int destN);
	void setLocation(const Location& dest);

	Location getLocation() const;
	Color getColor() const;
	char getChar() const;

protected:
	Board* m_board;
	Location m_location;
	char m_char;
	Color m_color;

private:
};