#include "Board.h"


Board::Board(const string& start)
	: m_stringBoard(start)
{
	allocateBoard();
}
//---------------------------------
Board::~Board()
{ }
//--------------------------------------
void Board::allocateBoard()
{
	try{
		m_pieces.resize(BOARD_SIZE);
		for (size_t row = 0, index_str = 0; row < BOARD_SIZE; ++row) {
			m_pieces[row].resize(BOARD_SIZE + 1);
			for (size_t col = 1; col <= BOARD_SIZE; ++col, ++index_str)
				m_pieces[row][col] = ((m_stringBoard[index_str] == '#') ? nullptr :
					FactoryPieces::create(toupper(m_stringBoard[index_str]),
						Location(getCharRow(row), col), this, getColor(m_stringBoard[index_str])));
		}
	}
	catch (UnknownLocation e) {	throw;
	}
	catch (std::bad_alloc e) { throw;
	}
	catch (std::out_of_range e) { throw;
	}
	catch (...) { throw; }
}
//----------------------------------------
int Board::getCodeResponse(string input, Color playerTurn)
{
	// If got here the input is correct (location on board) no need to check the input range.
	Location source(input[0], toInt(input[1]));
	Location dest(input[2], toInt(input[3]));

	int sourceL = getIntRow(source.l);
	int destL = getIntRow(dest.l);

	if (!m_pieces[sourceL][source.n])
		return Code::NullPiece; // 11

	if (m_pieces[sourceL][source.n]->getColor() != playerTurn)
		return Code::NotYourPiece; // 12

	if (m_pieces[destL][dest.n] &&
		(m_pieces[sourceL][source.n]->getColor() == m_pieces[destL][dest.n]->getColor()))
		return Code::YourPieceAtDestintion; // 13

	if (!m_pieces[sourceL][source.n]->isLegalMove(source, dest))
		return Code::IllegalMove; // 21

	{
		// move temporary to check if the movement cause check on my king
		std::swap(m_pieces[sourceL][source.n], m_pieces[destL][dest.n]);
		m_pieces[destL][dest.n]->setLocation(dest);

		if (threadOnMyKing(source, dest)) {
			m_pieces[destL][dest.n]->setLocation(source);
			std::swap(m_pieces[sourceL][source.n], m_pieces[destL][dest.n]);
			return Code::CheckOnMyself; // 31
		}

		m_pieces[destL][dest.n]->setLocation(source);
		std::swap(m_pieces[sourceL][source.n], m_pieces[destL][dest.n]);
	}

	if (m_pieces[sourceL][source.n]->checkOnOpponent(source, dest)) {
		movePiece(source, dest);
		return Code::CheckOnOpponent; // 41
	}

	movePiece(source, dest);
	return Code::LegalMove; // 42
}
//----------------------------------------------
bool Board::isClearPath(const char letter, int n) const
{
	return (m_pieces[getIntRow(letter)][n]) ? false : true;
}
//---------------------------------------
Location Board::getOpponentKingLocation(Color color) const
{
	for (auto& row : m_pieces)
		for (auto& piece : row) 
			if (piece && ((piece->getChar() == WHITE_KING) || (piece->getChar() == BLACK_KING))
				&& color != piece->getColor())
				return piece->getLocation();
}
//--------------------------------------
bool Board::threadOnMyKing(const Location& source, const Location& dest)
{ 
	int sourceL = getIntRow(source.l);
	int destL = getIntRow(dest.l);

	if  (m_pieces[sourceL][source.n] &&
		(  m_pieces[destL][dest.n]->getChar() == WHITE_KING
		|| m_pieces[destL][dest.n]->getChar() == BLACK_KING) )
		return false; // this is the case when the threatened king eat the threat

	for (auto& row : m_pieces)
		for (auto& piece : row) 
			if (piece &&  piece->getColor() != m_pieces[destL][dest.n]->getColor()
				&& piece->checkOnOpponent(piece->getLocation()))
				return true;

	return false; // no threat
}
//--------------------------------------------------
void Board::movePiece(const Location& source, const Location& dest)
{
	int sourceL = getIntRow(source.l);
	int destL = getIntRow(dest.l);

	std::swap(m_pieces[sourceL][source.n], m_pieces[destL][dest.n]);
	m_pieces[destL][dest.n]->setLocation(dest);
	m_pieces[sourceL][source.n].release();
}
//-----------------------------
const char Board::getCharRow(int row) const
{
	switch (row)
	{
	default: throw UnknownLocation("Unknown location of: " + row);
		break;

	case 0: return 'a'; break;
	case 1: return 'b'; break;
	case 2: return 'c'; break;
	case 3: return 'd'; break;
	case 4: return 'e'; break;
	case 5: return 'f'; break;
	case 6: return 'g'; break;
	case 7: return 'h'; break;
	}
}
//------------------------------
int Board::getIntRow(const char letter) const
{
	switch (letter)
	{
	default: throw UnknownLocation("Unknown location of: " + letter);
		break;

	case 'a': return 0; break;
	case 'b': return 1; break;
	case 'c': return 2; break;
	case 'd': return 3; break;
	case 'e': return 4; break;
	case 'f': return 5; break;
	case 'g': return 6; break;
	case 'h': return 7; break;
	}
}
//-------------------------------
Color Board::getColor(const char c) const
{
	return (islower(c)) ? Color::Black : Color::White;
}
//------------------------------
int Board::toInt(const char c)
{
	return (int)c - 48;
}