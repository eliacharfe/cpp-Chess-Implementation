#include "Bishop.h"
#include "Board.h"

bool Bishop::m_registerit = FactoryPieces::registerit('B', [](const char c, const Location& location,
	Board* board, Color  color) ->
	std::unique_ptr<Piece> {return std::make_unique<Bishop>(location, board, color, c); }
);

Bishop::Bishop(const Location& location, Board* board, Color  color, const char c)
	: Piece::Piece(location, board, color, c)
{ }
//----------------------------------
bool Bishop::isLegalMove(const Location & source, const Location & dest)
{
	return b_isLegalMove(source, dest);
}
//-----------------------------
bool Bishop::b_isLegalMove(const Location& source, const Location& dest)
{
	bool legal = true;

	int diffL = (source.l - dest.l);
	int diffN = (source.n - dest.n);

	if (abs(diffL) != abs(diffN))
		return false;

	char letter = source.l;
	int n = source.n;

	if (diffL < 0 && diffN < 0) {
		letter++; n++;
		for (; letter < dest.l; ++letter, ++n)
			if (!m_board->isClearPath(letter, n))
				legal = false;
	}
	else if (diffL < 0 && diffN > 0) {
		letter++; n--;
		for (; letter < dest.l; ++letter, --n)
			if (!m_board->isClearPath(letter, n))
				legal = false;
	}
	else if (diffL > 0 && diffN < 0) {
		letter--; n++;
		for (; letter > dest.l; --letter, ++n)
			if (!m_board->isClearPath(letter, n))
				legal = false;
	}
	else if (diffL > 0 && diffN > 0) {
		letter--; n--;
		for (; letter > dest.l; --letter, --n)
			if (!m_board->isClearPath(letter, n))
				legal = false;
	}

	return legal;
}