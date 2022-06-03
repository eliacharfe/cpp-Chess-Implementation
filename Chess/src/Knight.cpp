#include "Knight.h"
#include "Board.h"

bool Knight::m_registerit = FactoryPieces::registerit('N', [](const char c, const Location& location,
	Board* board, Color  color) ->
	std::unique_ptr<Piece> {return std::make_unique<Knight>(location, board, color, c); }
);

Knight::Knight(const Location& location, Board* board, Color color, const char c)
	: Piece::Piece(location, board, color, c)
{
}
//-------------------------------------
bool Knight::isLegalMove(const Location& source, const Location& dest)
{
	return ((((source.l == dest.l - 2) || (source.l == dest.l + 2)) && (abs(source.n - dest.n) == 1))
		|| (((source.n == dest.n - 2) || (source.n == dest.n + 2)) && (abs(source.l - dest.l) == 1)));
}
