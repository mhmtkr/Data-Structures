// AVL Tree

#include<stdio.h>
#include <stdlib.h>
typedef struct agac{
        int deger;
        int yukseklik;
        struct agac *sol;
        struct agac *sag;
        }AGAC;

int max(int m, int n);
int dengeal(AGAC*ptr);
AGAC* sagcevir(AGAC*y);
AGAC* solcevir(AGAC*x);

main()
{
  AGAC *KOK = NULL;
  AGAC*ekle( AGAC*, int);
  void inorder( AGAC*);



  KOK = ekle( KOK, 48);
  KOK = ekle( KOK, 76);
  KOK = ekle( KOK, 68);
  KOK = ekle( KOK, 23);
  KOK = ekle( KOK, 58);
  KOK = ekle( KOK, 42);
  KOK = ekle( KOK, 11);
  KOK = ekle( KOK, 60);
  KOK = ekle( KOK, 70);
  KOK = ekle( KOK, 80);
  KOK = ekle( KOK, 55);
  KOK = ekle( KOK, 50);

  printf("\n LNR : ");
  inorder(KOK);



}
//////////////////////
AGAC* ekle( AGAC *KOK, int x)
{
   AGAC* ptr1, *ptr;

   if( KOK == NULL)
    {
      KOK = (AGAC*)malloc(sizeof(AGAC));
      KOK->deger = x;
      KOK->sol=KOK->sag=NULL;
      return(KOK);
    }

    ptr = KOK;

    while( ptr!=NULL)
    {
      if(ptr->deger==x)
       {
          printf("\n %d AGACTA VAR.", x);
          return(KOK);
       }
       if( x < ptr->deger)

       {
         ptr1 = ptr;
         ptr = ptr->sol;
        }
       else
        {
          ptr1=ptr;
          ptr = ptr->sag;
         }

      }
     if( x < ptr1->deger)
     {
      ptr = ptr1->sol = (AGAC*)malloc(sizeof(AGAC));
      ptr->deger = x;
      ptr->sol = ptr->sag = NULL;
      return(KOK);
      }

      ptr = ptr1->sag = (AGAC*)malloc(sizeof(AGAC));
      ptr->deger = x;
      ptr -> sol = ptr -> sag = NULL;
      return(KOK);

      KOK->yukseklik = 1 + max(yukseklik(KOK->sol),
                           yukseklik(KOK->sag));


      int denge = dengeal(KOK);

      if (denge > 1 && x < KOK->sol->deger)
        return sagcevir(KOK);


      if (denge < -1 && x > KOK->sag->deger)
        return solcevir(KOK);


      if (denge > 1 && x > KOK->sol->deger)
        {
            KOK->sol =  solRotate(KOK->sol);
            return sagcevir(KOK);
        }


      if (denge < -1 && x < KOK->sag->deger)
        {
            KOK->sag = sagRotate(KOK->sag);
            return solcevir(KOK);
        }

       return KOK;
}

void inorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     inorder( ptr->sol);
     printf(" %d", ptr->deger);
     inorder( ptr->sag);
   }
}

int max(int m, int n)
{
    return (m > n)? m : n;
}

int yukseklik(AGAC*ptr)
{
    if (ptr == NULL)
        {
          return 0;
        }

    return ptr->yukseklik;
}

int dengeal(AGAC*ptr)
{
    if (ptr == NULL)
       {
         return 0;
       }

    return yukseklik(ptr->sol) - yukseklik(ptr->sag);
}

AGAC* sagcevir(AGAC*y)
{
    AGAC *x = y->sol;
    AGAC *t = x->sag;

    x->sag = y;
    y->sol = t;


    y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag))+1;
    x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag))+1;

    return x;
}

AGAC* solcevir(AGAC*x)
{
    AGAC *y = x->sag;
    AGAC *t = y->sol;

    y->sol = x;
    x->sag = t;

    x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag))+1;
    y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag))+1;

    return y;
}


