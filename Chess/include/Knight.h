#pragma once
#include "Piece.h"
#include "FactoryPieces.h"

class Board;

class Knight : public Piece
{
public:
	Knight(const Location& location, Board* board, Color  color, const char c);

	bool isLegalMove(const Location& source, const Location& dest) override;

private:
	static bool m_registerit;

};