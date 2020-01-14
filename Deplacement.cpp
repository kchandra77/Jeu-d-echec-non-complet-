//---------------------------------------------------------------------------

#pragma hdrstop

#include "Deplacement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "Echiquier.h"
bool Deplacement::ValidePositionArrivee(int iarr, int jarr)
{       for(int n=0;n<NbPositionArrivee;n++)
                if(iarr==TabPositionArrivee[0][n] && jarr==TabPositionArrivee[1][n])
                        return true;
        return false;
}

void DeplaceTour::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int diri[4]={-1,+1,+0,+0};      //direction en ligne
        int dirj[4]={+0,+0,-1,+1};      //direction en colonne
        int d,iarr,jarr;
        bool couleur=0,stop;            //0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='t' || PE->LitTabEchiquier(idep,jdep)=='T')
        {    if(PE->LitTabEchiquier(idep,jdep)=='t') couleur=1;     //noir
             for(d=0;d<4;d++)           //pour les 4 directions
             {       iarr=idep+diri[d]; //une case plus loin que la case de départ
                     jarr=jdep+dirj[d];
                     stop=false;
                     while((iarr>=0 && iarr<8 && jarr>=0 && jarr<8)   //dans l'échiquier
                        &&!(PE->LitTabEchiquier(iarr,jarr)>=('A'+couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('Z'+couleur*32))
                        &&!stop)
                     {  TabPositionArrivee[0][NbPositionArrivee]=iarr;
                        TabPositionArrivee[1][NbPositionArrivee]=jarr;
                        NbPositionArrivee++;
                        if(PE->LitTabEchiquier(iarr,jarr)!=' ') stop=true;  //une pièce a été rencontrée
                        iarr=iarr+diri[d]; //case suivante
                        jarr=jarr+dirj[d];
                     }
             }
        }
}
void DeplaceFou::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int diri[4]={-1,+1,-1,+1};      //direction en ligne
        int dirj[4]={-1,-1,+1,+1};      //direction en colonne
        int d,iarr,jarr;
        bool couleur=0,stop;            //0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='f' || PE->LitTabEchiquier(idep,jdep)=='F')
        {    if(PE->LitTabEchiquier(idep,jdep)=='f') couleur=1;     //noir
             for(d=0;d<4;d++)           //pour les 4 directions
             {       iarr=idep+diri[d]; //une case plus loin que la case de départ
                     jarr=jdep+dirj[d];
                     stop=false;
                     while((iarr>=0 && iarr<8 && jarr>=0 && jarr<8)   //dans l'échiquier
                        &&!(PE->LitTabEchiquier(iarr,jarr)>=('A'+couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('Z'+couleur*32))
                        &&!stop)
                     {  TabPositionArrivee[0][NbPositionArrivee]=iarr;
                        TabPositionArrivee[1][NbPositionArrivee]=jarr;
                        NbPositionArrivee++;
                        if(PE->LitTabEchiquier(iarr,jarr)!=' ') stop=true;  //une pièce a été rencontrée
                        iarr=iarr+diri[d]; //case suivante
                        jarr=jarr+dirj[d];
                     }
             }
        }
}
void DeplaceDame::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int diri[8]={-1,+1,+0,+0,-1,+1,-1,+1};      //direction en ligne
        int dirj[8]={+0,+0,-1,+1,-1,-1,+1,+1};      //direction en colonne
        int d,iarr,jarr;
        bool couleur=0,stop;            //0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='d' || PE->LitTabEchiquier(idep,jdep)=='D')
        {    if(PE->LitTabEchiquier(idep,jdep)=='d') couleur=1;     //noir
             for(d=0;d<8;d++)           //pour les 8 directions
             {       iarr=idep+diri[d]; //une case plus loin que la case de départ
                     jarr=jdep+dirj[d];
                     stop=false;
                     while((iarr>=0 && iarr<8 && jarr>=0 && jarr<8)   //dans l'échiquier
                        &&!(PE->LitTabEchiquier(iarr,jarr)>=('A'+couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('Z'+couleur*32))
                        &&!stop)
                     {  TabPositionArrivee[0][NbPositionArrivee]=iarr;
                        TabPositionArrivee[1][NbPositionArrivee]=jarr;
                        NbPositionArrivee++;
                        if(PE->LitTabEchiquier(iarr,jarr)!=' ') stop=true;  //une pièce a été rencontrée
                        iarr=iarr+diri[d]; //case suivante
                        jarr=jarr+dirj[d];
                     }
             }
        }
}
void DeplaceRoi::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int sauti[10]={-1,-1,-1,+0,+0,+1,+1,+1,+0,+0};
        int sautj[10]={-1,+0,+1,-1,+1,-1,+0,+1,+2,-2};
        int n,iarr,jarr;
        bool couleur=0;//0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='r' || PE->LitTabEchiquier(idep,jdep)=='R')
        {    if(PE->LitTabEchiquier(idep,jdep)=='r') couleur=1;
             for(n=0;n<10;n++)
             {       iarr=idep+sauti[n];
                     jarr=jdep+sautj[n];
                     if(iarr>=0 && iarr<8 && jarr>=0 && jarr<8)//dans l'échiquier
                     {  if((n<8 && !(PE->LitTabEchiquier(iarr,jarr)>=('A'+couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('Z'+couleur*32)))
                         || (n==8 && jdep==4 && iarr==(7-couleur*7) && PE->LitTabEchiquier(iarr,jarr)==' ' && PE->LitTabEchiquier(iarr,jarr-1)==' '//cas du petit roque
                             && PE->LitTabEchiquier(iarr,jarr+1)=='T'+couleur*32)
                         || (n==9 && jdep==4 && iarr==(7-couleur*7) && PE->LitTabEchiquier(iarr,jarr)==' ' && PE->LitTabEchiquier(iarr,jarr+1)==' '//cas du grand roque
                             && PE->LitTabEchiquier(iarr,jarr-1)==' ' && PE->LitTabEchiquier(iarr,jarr-2)=='T'+couleur*32))
                        {       TabPositionArrivee[0][NbPositionArrivee]=iarr;
                                TabPositionArrivee[1][NbPositionArrivee]=jarr;
                                NbPositionArrivee++;
                        }
                     }
             }
        }
}
void DeplaceCavalier::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int sauti[8]={-2,-2,-1,-1,+1,+1,+2,+2};
        int sautj[8]={-1,+1,-2,+2,-2,+2,-1,+1};
        int n,iarr,jarr;
        bool couleur=0;//0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='c' || PE->LitTabEchiquier(idep,jdep)=='C')
        {    if(PE->LitTabEchiquier(idep,jdep)=='c') couleur=1;
             for(n=0;n<8;n++)
             {
                     iarr=idep+sauti[n];
                     jarr=jdep+sautj[n];
                     if(iarr>=0 && iarr<8 && jarr>=0 && jarr<8)//dans l'échiquier
                     {  if(!(PE->LitTabEchiquier(iarr,jarr)>=('A'+couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('Z'+couleur*32)))
                        {       TabPositionArrivee[0][NbPositionArrivee]=iarr;
                                TabPositionArrivee[1][NbPositionArrivee]=jarr;
                                NbPositionArrivee++;
                        }
                     }
             }
        }
}
void DeplacePion::CalculPositionArrivee(int idep,int jdep,Echiquier *PE)
{       int Desti[4]={-1,-2,-1,-1};
        int Destj[4]={+0,+0,-1,+1};
        int n,iarr,jarr;
        bool couleur=0;//0=blanc
        NbPositionArrivee=0;
        if(PE->LitTabEchiquier(idep,jdep)=='p' || PE->LitTabEchiquier(idep,jdep)=='P')
        {    if(PE->LitTabEchiquier(idep,jdep)=='p') couleur=1;
             for(n=0;n<4;n++)
             {       if(couleur) Desti[n]*=-1;
                     iarr=idep+Desti[n];
                     jarr=jdep+Destj[n];
                     if(iarr>=0 && iarr<8 && jarr>=0 && jarr<8)//dans l'échiquier
                     {  if(  (n==0 && PE->LitTabEchiquier(iarr,jarr)==' ')
                           ||(n==1 && PE->LitTabEchiquier(iarr,jarr)==' ' && PE->LitTabEchiquier(idep+Desti[0],jdep+Destj[0])==' '
                                   && idep==(6-couleur*5))
                           ||(Destj[n]!=0 && (PE->LitTabEchiquier(iarr,jarr)>=('a'-couleur*32) && PE->LitTabEchiquier(iarr,jarr)<=('z'-couleur*32)))
                           ||(Destj[n]!=0 && (PE->LitTabEchiquier(idep,jarr)>=('a'-couleur*32) && PE->LitTabEchiquier(idep,jarr)<=('z'-couleur*32))//Prise en passant
                                          && PE->LitTabEchiquier(iarr,jarr)==' ' && PE->LitTabEchiquier(1+couleur*5,jarr)==' ' && iarr==(2+couleur*3)))
                        {       TabPositionArrivee[0][NbPositionArrivee]=iarr;
                                TabPositionArrivee[1][NbPositionArrivee]=jarr;
                                NbPositionArrivee++;
                        }
                     }
             }
        }
}

