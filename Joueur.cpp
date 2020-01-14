//---------------------------------------------------------------------------

#pragma hdrstop

#include "Joueur.h"
//---------------------------------------------------------------------------
Joueur::Joueur()
{
	trait=0;
}

void Joueur::DonneTrait()
{
	trait=1;
}

void Joueur::RetireTrait()
{
	trait=0;
}

bool Joueur::LitTrait()
{
	return trait;
}

#pragma package(smart_init)
