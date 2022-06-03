#include "King.h"
#include "Board.h"

bool King::m_registerit = FactoryPieces::registerit('K', [](const char c, const Location& location,
	Board* board, Color  color) ->
	std::unique_ptr<Piece> {return std::make_unique<King>(location, board, color, c); }
);

King::King(const Location& location, Board* board, Color color, const char c)
	: Piece::Piece(location, board, color, c)
{
}
//---------------------------
bool King::isLegalMove(const Location& source, const Location& dest)
{
	if (abs(source.n - dest.n != 0 && abs(source.n - dest.n) != 1))
		return false;

	if (source.l != dest.l && source.l != dest.l + 1 && source.l != dest.l - 1)
		return false;

	return true;
}