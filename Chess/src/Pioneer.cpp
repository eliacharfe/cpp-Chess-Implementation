#include "Pioneer.h"
#include "Board.h"

bool Pioneer::m_registerit = FactoryPieces::registerit('P', [](const char c, const Location& location,
	Board* board, Color color) ->
	std::unique_ptr<Piece> {return std::make_unique<Pioneer>(location, board, color, c); }
);

Pioneer::Pioneer(const Location& location, Board* board, Color color, const char c)
	: Piece::Piece(location, board, color, c)
{ }
//------------------------------------
bool Pioneer::isLegalMove(const Location& source, const Location& dest)
{
	int diffL = (source.l - dest.l);

	if ((m_color == Color::White && source.l == 'b' && source.n == dest.n && source.l == dest.l - 2)
		|| (m_color == Color::Black && source.l == 'g' && source.n == dest.n && source.l == dest.l + 2))
		return true;

	if (abs(diffL) != 1 || (source.n != dest.n)
		|| ((source.l >= dest.l) && m_color == Color::White)
		|| ((source.l <= dest.l) && m_color == Color::Black))
		return false;

	return true;
}
