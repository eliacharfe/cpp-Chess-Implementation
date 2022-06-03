#pragma once
#include "Utilities.h"
#include "Piece.h"
#include "Location.h"

class FactoryPieces : public Piece
{
public:
	using pFnc = unique_ptr<Piece>(*)(const char, const Location&, Board* board, Color color);
	static unique_ptr<Piece> create(const char, const Location&, Board* board, Color color);
	static bool registerit(const char, pFnc);
	
private:
	static auto& getMap() {
		static std::map <const char, pFnc > map;
		return map;
	}
	
};
