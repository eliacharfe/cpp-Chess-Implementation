#pragma once
#include "Utilities.h"
#include "Exception.h"
#include "CodeResponse.h"
#include "Piece.h"
#include "FactoryPieces.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Color.h"

class Board
{
public:
	Board(const string& start = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");
	~Board();

	const string& getStringBoard() const { return m_stringBoard; }
	int getCodeResponse(string input, Color playerTurn);

	bool isClearPath(const char letter, int n) const;
	Location getOpponentKingLocation(Color color) const;

private:
	vector < vector < unique_ptr < Piece > >> m_pieces;
	string m_stringBoard;

	void allocateBoard();

	bool threadOnMyKing(const Location& source, const Location& dest);
	void movePiece(const Location& source, const Location& dest);

	int toInt(const char c);
	const char getCharRow(int row) const;
	int getIntRow(const char letter) const;
	Color getColor(const char c) const;
};