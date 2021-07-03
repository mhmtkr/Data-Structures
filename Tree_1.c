// Trees

#include<stdio.h>
#include <stdlib.h>
typedef struct agac{
        int deger;
        struct agac *sol;
        struct agac *sag;
        }AGAC;

AGAC* koksil(AGAC*root, int n);
AGAC* minDeger(AGAC* dugum);

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

     printf("\n 1--> devam,  0---> cikis ");
     scanf("%d",&secim);

  }

  printf("\n Koku silmek istiyorsaniz---> 1");  // Agaç olusturup 0 a basip cikis yaptiktan sonra Koku silmek istiyorsaniz 1 e basin. 1 girilirse koku silip agaci tekrar gosteriyor
  scanf("%d",&silme);
  if(silme)
  {
     KOK = koksil(KOK, 0);

     printf("\n LNR : ");
     inorder(KOK);

     printf("\n NLR : ");
     preorder(KOK);

     printf("\n LRN : ");
     postorder(KOK);
  }
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


   AGAC* koksil(AGAC*root, int n)
{
    if (root == NULL) return root;

        if (root->sol == NULL)
        {
            AGAC*gecici = root->sag;
            free(root);
            return gecici;
        }
        else if (root->sag == NULL)
        {
            AGAC*gecici = root->sol;
            free(root);
            return gecici;
        }

        AGAC* gecici = minDeger(root->sag);

        root->deger = gecici->deger;

        root->sag = koksil(root->sag, gecici->deger);

    return root;
}

AGAC* minDeger(AGAC* dugum)
{
    AGAC* simdiki = dugum;

    while (simdiki && simdiki->sol != NULL)
        simdiki = simdiki->sol;

    return simdiki;
}

