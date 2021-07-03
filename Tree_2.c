// Trees

#include<stdio.h>
#include <stdlib.h>
typedef struct agac{
        int deger;
        struct agac *sol;
        struct agac *sag;
        }AGAC;

void yaprakbul(AGAC* root2);  //Yapraklari toplayan ve sayan fonksiyon

float toplam = 0, say = 0, ym = 0;
main()
{
  AGAC *KOK = NULL;
  AGAC*ekle( AGAC*, int);
  void inorder( AGAC*);
  void preorder( AGAC*);
  void postorder( AGAC*);

  int secim = 1, x, silme = 0;

  while( secim )
  {
     printf("\n Bir Deger giriniz..");
     scanf("%d",&x);

     KOK = ekle( KOK, x);

     printf("\n LNR : ");
     inorder(KOK);

     printf("\n NLR : ");
     preorder(KOK);

     printf("\n LRN : ");
     postorder(KOK);


     printf("\n 1--> devam,  0---> cikis ve aritmetik ortalama ");
     scanf("%d",&secim);

  }

     //cikis yapildiktan sonra aritmetik ortalamayi buluyor
     yaprakbul(KOK);
     ym = toplam / say;
     printf("\n Yapraklardaki degerlerin aritmetik ortalamasi: %f ",ym);

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
}
/////////////////////////////
void inorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     inorder( ptr->sol);
     printf(" %d", ptr->deger);
     inorder( ptr->sag);
   }
}
/////////////////////////
void preorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {

     printf(" %d", ptr->deger);
     preorder(ptr->sol);
     preorder( ptr->sag);
   }
}
////////////////////////
void postorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     postorder( ptr->sol);
     postorder( ptr->sag);
     printf(" %d", ptr->deger);
   }
}

void yaprakbul(AGAC*root2){


    if (root2 == NULL)
       {
          return 0;
       }



    if (root2->sol == NULL && root2->sag == NULL)        //Yaprak bulma
        {
            toplam += root2->deger;
            say += 1;
        }

    yaprakbul(root2->sol);   //Rekürsif olarak alt agaçlara iniyoruz
    yaprakbul(root2->sag);
}

