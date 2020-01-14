//---------------------------------------------------------------------------

#ifndef JoueurH
#define JoueurH
#include <System.Classes.hpp>
class Joueur
{
private:
	bool trait;
	String nom;
public:
Joueur();
void DonneTrait();
void RetireTrait();
bool LitTrait();
int demiCoupsAffiche;


};
//---------------------------------------------------------------------------
#endif
