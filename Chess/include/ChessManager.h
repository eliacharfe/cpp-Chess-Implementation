#pragma once
#include "Board.h"
#include "Chess.h"

class ChessManager
{
public:
	ChessManager();
	void run();

private:
	Board m_board;
	Chess m_chess;
};