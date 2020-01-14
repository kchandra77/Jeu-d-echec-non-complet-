//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "blindChess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{   if(RadioButton1->Checked)
		{

			ServerSocket1->Port=Edit2->Text.ToInt();
			ServerSocket1->Active=true;
		}
		else
		{
			ClientSocket1->Address=Edit1->Text;
			ClientSocket1->Port=Edit2->Text.ToInt();
			ClientSocket1->Active=true;
		}
}





void __fastcall TForm2::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	Form1->Show();
	if(CheckBox1->Checked)
		{
			ClientSocket1->Socket->SendText("Vous êtes Blanc");
		}
	else
		{
		   ClientSocket1->Socket->SendText("Vous êtes Noir");
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
		AnsiString message=monClientSocket->ReceiveText();
	if(message.Length()<64)
		{
			Form1->Caption=message;
		}
		else
		{
			int i=0,j=0;
			for(int k=0;k<64;k++)
			{
				Form1->monEchiquier.ModifieEchiquier(message.c_str()[k],i,j++);
				if(j==8)
					{
						i++;j=0;
					}
			}
		Form1->ChargeFormEchiquier(Form1->monEchiquier);
		Form1->ChangeTrait();
		}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
	CheckBox1->Hide();
	CheckBox2->Hide();
	Edit2->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	CheckBox1->Show();
	CheckBox2->Show();
	Edit2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1ClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
	monClientSocket=Socket;
	Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{   int i=0,j=0;
	AnsiString message=ClientSocket1->Socket->ReceiveText();
	if(message>=64)
		{
			for(int k=0;k<64;k++)
			{
				Form1->monEchiquier.ModifieEchiquier(AnsiString(message).c_str()[k],i,j++);
				if(j==8)
					{
						i++;j=0;
					}
			}
		Form1->ChargeFormEchiquier(Form1->monEchiquier);
		Form1->ChangeTrait();
		}
}
//---------------------------------------------------------------------------

