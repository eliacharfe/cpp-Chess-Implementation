#include "Rook.h"
#include "Board.h"

bool Rook::m_registerit = FactoryPieces::registerit('R', [](const char c, const Location& location,
	 Board* board, Color color) ->
	std::unique_ptr<Piece> {return std::make_unique<Rook>(location, board, color, c); }
);

Rook::Rook(const Location& location, Board* board, Color color, const char c)
	: Piece::Piece(location, board, color, c)
{
}
//-----------------------------------
bool Rook::isLegalMove(const Location& source, const Location& dest)
{
	return r_isLegalMove(source, dest);
}
//---------------------------------------------
bool Rook::r_isLegalMove(const Location& source, const Location& dest)
{
	bool legal = true;

	if ((source.l == dest.l) && (source.n != dest.n))
	{
		if (source.n < dest.n) {
			for (int n = (source.n + 1); n < dest.n; ++n)
				if (!m_board->isClearPath(source.l, n))
					legal = false;
		}
		else
			for (int n = (source.n - 1); n > dest.n; --n)
				if (!m_board->isClearPath(source.l, n))
					legal = false;
	}
	else if ((source.l != dest.l) && (source.n == dest.n))
	{
		if (source.l < dest.l) {
			for (char letter = (source.l + 1); letter < dest.l; ++letter)
				if (!m_board->isClearPath(letter, source.n))
					legal = false;
		}
		else
			for (char letter = (source.l - 1); letter > dest.l; --letter)
				if (!m_board->isClearPath(letter, source.n))
					legal = false;
	}
	else
		legal = false;

	return legal;
}
//----------------------------------------