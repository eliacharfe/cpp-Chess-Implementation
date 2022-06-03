#include "ChessManager.h"

int main()
{
	try {
		ChessManager chessManager;
		chessManager.run();
	}
	catch (std::exception e) {
		cout << e.what() << endl;
	}

	cout << endl << "Exiting " << endl;
	return EXIT_SUCCESS;
}