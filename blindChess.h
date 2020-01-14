//---------------------------------------------------------------------------

#ifndef blindChessH
#define blindChessH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include "Echiquier.h"
#include <Vcl.ComCtrls.hpp>
#include "Joueur.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TImage *Image12;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TImage *Image18;
	TImage *Image19;
	TImage *Image20;
	TImage *Image21;
	TImage *Image22;
	TImage *Image23;
	TImage *Image24;
	TImage *Image25;
	TImage *Image26;
	TImage *Image27;
	TImage *Image28;
	TImage *Image29;
	TImage *Image30;
	TImage *Image31;
	TImage *Image32;
	TImage *Image33;
	TImage *Image34;
	TImage *Image35;
	TImage *Image36;
	TImage *Image37;
	TImage *Image38;
	TImage *Image39;
	TImage *Image40;
	TImage *Image41;
	TImage *Image42;
	TImage *Image43;
	TImage *Image44;
	TImage *Image45;
	TImage *Image46;
	TImage *Image47;
	TImage *Image48;
	TImage *Image49;
	TImage *Image50;
	TImage *Image51;
	TImage *Image52;
	TImage *Image53;
	TImage *Image54;
	TImage *Image55;
	TImage *Image56;
	TImage *Image57;
	TImage *Image58;
	TImage *Image59;
	TImage *Image60;
	TImage *Image61;
	TImage *Image62;
	TImage *Image63;
	TImage *Image64;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TRichEdit *RichEdit1;
	TSpeedButton *SpeedButton3;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TSpeedButton *SpeedButton4;
	TShape *Shape1;
	TShape *Shape2;
	void __fastcall Nouvelle(TObject *Sender);
	void __fastcall LachePiece(TObject *Sender, TObject *Source, int X, int Y);
	void __fastcall AcceptePiece(TObject *Sender, TObject *Source, int X, int Y, TDragState State,
		  bool &Accept);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);







private:	// Déclarations utilisateur
	TImage *laCase[8][8];


public:		// Déclarations utilisateur
	char ChoixProm();
	bool Visible;
	void ChangeTrait();
	Joueur jBlanc;
	Joueur jNoir;
	bool jeuInterdit;
	Echiquier monEchiquier;

	__fastcall TForm1(TComponent* Owner);
	void ChargeFormEchiquier(Echiquier e);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
