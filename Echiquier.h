//---------------------------------------------------------------------------

#ifndef EchiquierH
#define EchiquierH
#include <System.Classes.hpp>
class Echiquier{
private:
	char  tabEchiquier[8][8];
public:
	Echiquier();
	char LitTabEchiquier(int ligne, int colonne);
	void InitEchiquier();
	String VisuEchiquier();
	void ModifieEchiquier(char cPiece,int ligne,int colonne);
	bool EstVide(int ligne,int colonne);
	bool EstUnePieceNoire(int ligne,int colonne);
	bool EstUnePieceBlanche(int ligne,int colonne);


};
//---------------------------------------------------------------------------
#endif
