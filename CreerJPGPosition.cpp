	// 1er copier-coller
	int i,j, colonne,ligne,coul,limg=laCase[0][0]->Picture->Width;
	int couleurTransparente;
	Image66->Picture->LoadFromFile("blanc.bmp"); //image blanche de la taille d'une pièce
	Image66->Picture->Bitmap->Width=limg*8;
	Image66->Picture->Bitmap->Height=limg*8;
	for(ligne=0;ligne<8;ligne++) for(colonne=0;colonne<8;colonne++)
	{
		// Ligne à ajouter
		couleurTransparente = laCase[ligne][colonne]->Picture->Bitmap->Canvas->Pixels[0][0];
		for(i=0;i<limg;i++) for(j=0;j<limg;j++)
		{
			// Ligne à ajouter
			if(laCase[ligne][colonne]->Picture->Bitmap->Canvas->Pixels[i][j] == couleurTransparente)
			{
				if((ligne+colonne)%2) coul=0xa0a0a0;
				else coul=0xffffff;
				Image66->Picture->Bitmap->Canvas->Pixels[i+colonne*limg][j+ligne*limg]=coul;
			}
			else
			{
				Image66->Picture->Bitmap->Canvas->Pixels[i+colonne*limg][j+ligne*limg]=laCase[ligne][colonne]->Picture->Bitmap->Canvas->Pixels[i][j];
			}
		}
	}
	// 2ème copier-coller
	TJPEGImage *jpg = new TJPEGImage;
	jpg->Assign(Image66->Picture->Bitmap);
	jpg->SaveToFile("echiquier.jpg");