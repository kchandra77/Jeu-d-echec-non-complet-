//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "blindChess.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	laCase[0][0]=Image1; laCase[0][1]=Image2; laCase[0][2]=Image3; laCase[0][3]=Image4; laCase[0][4]=Image5; laCase[0][5]=Image6;
	laCase[0][6]=Image7; laCase[0][7]=Image8; laCase[1][0]=Image9; laCase[1][1]=Image10; laCase[1][2]=Image11; laCase[1][3]=Image12;
	laCase[1][4]=Image13; laCase[1][5]=Image14; laCase[1][6]=Image15; laCase[1][7]=Image16; laCase[2][0]=Image17; laCase[2][1]=Image18;
	laCase[2][2]=Image19; laCase[2][3]=Image20; laCase[2][4]=Image21; laCase[2][5]=Image22; laCase[2][6]=Image23; laCase[2][7]=Image24;
	laCase[3][0]=Image25; laCase[3][1]=Image26; laCase[3][2]=Image27; laCase[3][3]=Image28; laCase[3][4]=Image29; laCase[3][5]=Image30;
	laCase[3][6]=Image31; laCase[3][7]=Image32; laCase[4][0]=Image33; laCase[4][1]=Image34; laCase[4][2]=Image35; laCase[4][3]=Image36;
	laCase[4][4]=Image37; laCase[4][5]=Image38; laCase[4][6]=Image39; laCase[4][7]=Image40; laCase[5][0]=Image41; laCase[5][1]=Image42;
	laCase[5][2]=Image43; laCase[5][3]=Image44; laCase[5][4]=Image45; laCase[5][5]=Image46; laCase[5][6]=Image47; laCase[5][7]=Image48;
	laCase[6][0]=Image49; laCase[6][1]=Image50; laCase[6][2]=Image51; laCase[6][3]=Image52; laCase[6][4]=Image53; laCase[6][5]=Image54;
	laCase[6][6]=Image55; laCase[6][7]=Image56; laCase[7][0]=Image57; laCase[7][1]=Image58; laCase[7][2]=Image59; laCase[7][3]=Image60;
	laCase[7][4]=Image61; laCase[7][5]=Image62; laCase[7][6]=Image63; laCase[7][7]=Image64;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nouvelle(TObject *Sender)
{
	monEchiquier.InitEchiquier();
	ChargeFormEchiquier(monEchiquier);
	RichEdit1->Text = monEchiquier.VisuEchiquier();
	//on donne le trait au joueur blanc
	jBlanc.DonneTrait();
	jNoir.RetireTrait();
	Shape1->Visible=false;   //Noir invisivle
	Shape2->Visible=true;	// Blanc visible
   

	for(int i=2;i<6;i++)
	for(int j=0;j<8;j++)
	{
		laCase[i][j]->Picture->LoadFromFile("vide.bmp");
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::LachePiece(TObject *Sender, TObject *Source, int X, int Y)

{
	int idep,jdep,iarr,jarr;
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(Source==laCase[i][j])
		{
			idep=i;
			jdep=j;
		}
		if(Sender==laCase[i][j])
		{
			iarr=i;
			jarr=j;
		}

	}
	//Si on est le joueur Blanc et qu'on deplace une piece blanche
	if(jBlanc.LitTrait()&& monEchiquier.EstUnePieceBlanche(idep,jdep)==1 || jNoir.LitTrait()&& monEchiquier.EstUnePieceNoire(idep,jdep))
	{
		char p= monEchiquier.LitTabEchiquier(idep,jdep);
		monEchiquier.ModifieEchiquier(p,iarr,jarr);
		monEchiquier.ModifieEchiquier(' ',idep ,jdep);
		if(p=='P'&& iarr==0)
			{
				monEchiquier.ModifieEchiquier(ChoixProm(),iarr,jarr);
			}
		if(p=='p'&& iarr==7)
			{
				monEchiquier.ModifieEchiquier(ChoixProm()+32,iarr,jarr);
			}

		ChargeFormEchiquier(monEchiquier);
		RichEdit1->Text = monEchiquier.VisuEchiquier();

	ChangeTrait();
	}

		String position="";
		for(int i=0;i<8;i++) for(int j=0;j<8;j++)
		position=position+(String)monEchiquier.LitTabEchiquier(i,j);
		if(Form2->RadioButton2->Checked)
		{
			Form2->ClientSocket1->Socket->SendText(position);
		}
		else if(Form2->RadioButton1->Checked)
		{
			Form2->monClientSocket->SendText(position);
		}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::AcceptePiece(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept)
{
	Accept=1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
  TImage *temp=new TImage(this);
	for(int i=0;i<4;i++)
	for(int j=0;j<8;j++)
	{
	   temp->Picture=laCase[i][j]->Picture;
	   laCase[i][j]->Picture=laCase[7-i][7-j]->Picture;
	   laCase[7-i][7-j]->Picture=temp->Picture;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	RichEdit1->Text = monEchiquier.VisuEchiquier();
}
//---------------------------------------------------------------------------
void TForm1::ChargeFormEchiquier(Echiquier e)
{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				char p=e.LitTabEchiquier(i,j);
				switch(p)
				{
					case 't': laCase[i][j]->Picture->LoadFromFile("tourN.bmp");
					break;
					case 'T': laCase[i][j]->Picture->LoadFromFile("tourB.bmp");
					break;

					case 'c': laCase[i][j]->Picture->LoadFromFile("cavN.bmp");
					break;
					case 'C': laCase[i][j]->Picture->LoadFromFile("cavB.bmp");
					break;

					case 'f': laCase[i][j]->Picture->LoadFromFile("fouN.bmp");
					break;
					case 'F': laCase[i][j]->Picture->LoadFromFile("fouB.bmp");
					break;

					case 'd': laCase[i][j]->Picture->LoadFromFile("dameN.bmp");
					break;
					case 'D': laCase[i][j]->Picture->LoadFromFile("dameB.bmp");
					break;

					case 'r': laCase[i][j]->Picture->LoadFromFile("roiN.bmp");
					break;
					case 'R': laCase[i][j]->Picture->LoadFromFile("roiB.bmp");
					break;

					case 'p': laCase[i][j]->Picture->LoadFromFile("pionN.bmp");
					break;
					case 'P': laCase[i][j]->Picture->LoadFromFile("pionB.bmp");
					break;

					case ' ': laCase[i][j]->Picture->LoadFromFile("vide.bmp");
					break;
				}
			}
		}
}

char TForm1::ChoixProm()
{
	if(RadioButton1->Checked) return 'D';
	if(RadioButton2->Checked) return 'C';
	if(RadioButton3->Checked) return 'F';
	if(RadioButton4->Checked) return 'T';
}

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
	 if(Visible==0)
	 {
	 for(int i=0;i<8;i++)
	 for(int j=0;j<8;j++)
	 laCase[i][j]->Picture->LoadFromFile("vide.bmp");
	 Visible=true;
	 }
	 else
	 {
	 ChargeFormEchiquier(monEchiquier);
	 Visible=false;
	 }

}
void TForm1::ChangeTrait()
{
	 if(jBlanc.LitTrait()==true)
	 {
		 jBlanc.RetireTrait();
		 jNoir.DonneTrait();
		 Shape1->Visible=true;
		 Shape2->Visible=false;

	 }
	 else
	 {
		 jNoir.RetireTrait();
		 jBlanc.DonneTrait();
		 Shape1->Visible=false;
		 Shape2->Visible=true;
     }
}
//---------------------------------------------------------------------------


