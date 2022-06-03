#pragma once
#include "Piece.h"
#include "FactoryPieces.h"

class Board;

class Rook : virtual public Piece
{
public:
	Rook(const Location& location, Board* board, Color color, const char c);

	//bool isLegalMove(const char sourceL, int sourceN, const char destL, int destN) override;

	bool isLegalMove(const Location& source, const Location& dest) override;

protected:
	//bool r_isLegalMove(const char sourceL, int sourceN, const char destL, int destN);

	bool r_isLegalMove(const Location& source, const Location& dest);

private:
	static bool m_registerit;

};