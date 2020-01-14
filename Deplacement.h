//---------------------------------------------------------------------------

#ifndef DeplacementH
#define DeplacementH
//---------------------------------------------------------------------------
class Echiquier;
class Deplacement
{       protected:
                int TabPositionArrivee[2][63];
                int NbPositionArrivee;
        public:
				Deplacement(){};
                bool ValidePositionArrivee(int iarr,int jarr);
};
class DeplaceCavalier : public Deplacement
{       public:
				DeplaceCavalier(){};
				void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
class DeplaceFou : public Deplacement
{       public:
				DeplaceFou(){};
                void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
class DeplaceDame : public Deplacement
{       public:
				DeplaceDame(){};
                void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
class DeplaceRoi : public Deplacement
{       public:
				DeplaceRoi(){};
                void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
class DeplaceTour : public Deplacement
{       public:
				DeplaceTour(){};
                void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
class DeplacePion : public Deplacement
{       public:
                DeplacePion(){};
                void CalculPositionArrivee(int idep,int jdep,Echiquier *PE);
};
#endif
