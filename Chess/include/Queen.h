#pragma once
#include "FactoryPieces.h"
#include "Bishop.h"
#include "Rook.h"

class Board;

class Queen : public Rook, public Bishop
{
public:
	Queen(const Location& location, Board* board, Color color, const char c);

	bool isLegalMove(const Location& source, const Location& dest) override;

private:
	static bool m_registerit;

};