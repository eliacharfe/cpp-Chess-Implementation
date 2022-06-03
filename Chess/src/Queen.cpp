#include "Queen.h"
#include "Board.h"

bool Queen::m_registerit = FactoryPieces::registerit('Q', [](const char c, const Location& location,
	Board* board, Color  color) ->
	std::unique_ptr<Piece> {return std::make_unique<Queen>(location, board, color, c); }
);

Queen::Queen(const Location& location, Board* board, Color color, const char c)
	: Piece::Piece(location, board, color, c),
	Rook(location, board, color, c), Bishop(location, board, color, c)
{ }
//----------------------------------------
bool Queen::isLegalMove(const Location& source, const Location& dest)
{
	return b_isLegalMove(source, dest) || r_isLegalMove(source, dest);
}