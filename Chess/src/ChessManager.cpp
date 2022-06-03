#include "ChessManager.h"

ChessManager::ChessManager()
//  : m_board("RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"),
//  : m_board("##################K#######################R#############r#r#####"),
//  : m_board("R###K##R#############k##################################r#bq#b#r"),
	: m_board("RNBQKBNR#P####P#################################p####p##rnbqkbnr"),
	  m_chess(m_board.getStringBoard())
{
}
//------------------------
void ChessManager::run()
{
	int codeResponse = 0;
	Color isWhiteTurn = Color::White;

	string input = m_chess.getInput();

	while (input != "exit")
	{
		/*
		codeResponse value :
		Illegal movements :
		11 - there is not piece at the source
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination
		21 - illegal movement of that piece
		31 - this movement will cause you checkmate

		legal movements :
		41 - the last movement was legal and cause check
		42 - the last movement was legal, next turn
		*/
		{ 
			codeResponse = m_board.getCodeResponse(input, isWhiteTurn);

			if (codeResponse == Code::LegalMove || codeResponse == Code::CheckOnOpponent)
				isWhiteTurn = (isWhiteTurn == Color::White) ? Color::Black : Color::White;
		}

		m_chess.setCodeResponse(codeResponse);
		input = m_chess.getInput();
	}
}


