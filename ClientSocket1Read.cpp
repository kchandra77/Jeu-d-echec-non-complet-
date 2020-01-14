UnicodeString m=Socket->ReceiveText();
RichEdit1->Text=m;
char position[72];
strcpy(position,(char*)AnsiString(m).c_str());
//tcfdrfct\npppppppp\n...
int k=0;
//mettre à jour l'objet échiquier
for(int i=0;i<8;i++)
{	for(int j=0;j<8;j++)
	{	monEchiquier.ModifieEchiquier(position[k++],i,j);
	}
	//fin de ligne : sauter \n
	k++;
}
//changement du trait
ChangeTrait();
jeuInterdit=false;
ChargeFormEchiquier(monEchiquier);

