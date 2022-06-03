#include "FactoryPieces.h"

unique_ptr<Piece> FactoryPieces::create(const char c, const Location& location, Board* board, Color color)
{
	auto it = FactoryPieces::getMap().find(c);
	if (it == FactoryPieces::getMap().end())
		return nullptr;
	return it->second(c, location, board, color);
}
//---------------------------------------------------------
bool FactoryPieces::registerit(const char c, pFnc func)
{
	FactoryPieces::getMap().emplace(c, func);
	return true;
}
//-------------------------------------------------