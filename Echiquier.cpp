//---------------------------------------------------------------------------

#pragma hdrstop

#include "Echiquier.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Echiquier::Echiquier()
{
	InitEchiquier();
}


void Echiquier::ModifieEchiquier(char cPiece,int ligne,int colonne)
{
	 tabEchiquier[ligne][colonne]=cPiece;
}

char Echiquier::LitTabEchiquier(int ligne,int colonne)
{
	return tabEchiquier[ligne][colonne];
}

bool Echiquier::EstVide(int ligne,int colonne)
{
	if(tabEchiquier[ligne][colonne]==' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Echiquier::EstUnePieceNoire(int ligne,int colonne)
{
	if(tabEchiquier[ligne][colonne]>='a' && tabEchiquier[ligne][colonne]<='z')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Echiquier::EstUnePieceBlanche(int ligne,int colonne)
{
	if(tabEchiquier[ligne][colonne]>='A' && tabEchiquier[ligne][colonne]<='Z')
	{
		return true;
	}
	else
	{
        return false;
    }
}


void Echiquier::InitEchiquier()
{
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			{
				tabEchiquier[1][j]='p';
				tabEchiquier[6][j]='P';
				tabEchiquier[7][6]='C';
				tabEchiquier[7][1]='C';
				tabEchiquier[0][6]='c';
				tabEchiquier[0][1]='c';
				tabEchiquier[0][0]='t';
				tabEchiquier[0][7]='t';
				tabEchiquier[7][0]='T';
				tabEchiquier[7][7]='T';
				tabEchiquier[0][5]='f';
				tabEchiquier[0][2]='f';
				tabEchiquier[7][5]='F';
				tabEchiquier[7][2]='F';
				tabEchiquier[0][3]='d';
				tabEchiquier[7][3]='D';
				tabEchiquier[7][4]='R';
				tabEchiquier[0][4]='r';
			}

		for(int i=2;i<6;i++)
		{
			for(int j=0;j<8;j++)
			{
				tabEchiquier[i][j]=' ';
			}
		}
}
String Echiquier::VisuEchiquier()
{
	String ech="";
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			ech=ech+(String)tabEchiquier[i][j];
		}
		ech=ech+"\n";
	}
	return ech;
}
