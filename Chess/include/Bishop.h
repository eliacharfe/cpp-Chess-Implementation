#pragma once
#include "Piece.h"
#include "FactoryPieces.h"

class Board;

class Bishop : virtual public Piece
{
public:
	Bishop(const Location& location, Board* board, Color color, const char c);

	bool isLegalMove(const Location& source, const Location& dest) override;

protected:
	bool b_isLegalMove(const Location& source, const Location& dest);

private:
	static bool m_registerit;

};