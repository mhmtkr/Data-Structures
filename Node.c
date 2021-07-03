// Nodes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct liste
{
    int icerik;
    struct liste *sonraki;
}lst;

lst *ilk;

void listeolustur(int n);
void listegoster();
bool asalmi(int m);
void tekcift();
void dugumsil(lst **ref, int anahtar);

int cift = 0, tek = 0, asal = 0;
bool b = true;

int main()
{
    int n;

    printf(" Dugum sayisini giriniz : ");
    scanf("%d", &n);
    listeolustur(n);
    printf("\n Listedeki degerler : \n");
    listegoster();
    tekcift();

    printf("\n Listedeki ilk asal sayi : %d \n", asal);

    dugumsil(&ilk, asal);
    printf("\n Asal silindikten sonra liste: \n");
    listegoster();

    return 0;
}
void listeolustur(int n)
{
    struct liste *fnliste, *gc;
    int icerik, i;


    ilk = (struct liste *)malloc(sizeof(struct liste));

    if(ilk == NULL)
    {
        printf(" Bellekte yer yok");
    }
    else
    {

//Liste degerlerini kullanicidan aliyoruz

        printf(" Dugum 1 icin bir tamsayi degeri giriniz: ");
        scanf("%d", &icerik);
        ilk->icerik = icerik;
        ilk->sonraki = NULL;
        gc = ilk;

// Diger dugumleri olusturuyoruz

        for(i=2; i<=n; i++)
        {
            fnliste = (struct liste *)malloc(sizeof(struct liste));
            if(fnliste == NULL)
            {
                printf(" Bellekte yer yok");
                break;
            }
            else
            {
                printf(" dugum %d icin bir tamsayi degeri giriniz : ", i);
                scanf(" %d", &icerik);

                fnliste->icerik = icerik;
                fnliste->sonraki = NULL;

                gc->sonraki = fnliste;
                gc = gc->sonraki;
            }
        }
    }
}
void listegoster()   // Burada listeyi gosterirken ayrica tek ve cift dugumleri sayiyorum ve ilk asal dugumu buluyorum
{
    struct liste *gc;
    if(ilk == NULL)
    {
        printf(" Liste bos ");
    }
    else
    {
        gc = ilk;



        while(gc != NULL)
        {
           while(b == true)     //Asal bulma
           {
               if (asalmi(gc->icerik) == true)
             {
              asal = gc->icerik;
              b = false;
              break;
             }
             break;
           }


            if( gc->icerik % 2 == 0)
             {
                 cift++;
             }
            else
             {
                tek++;
             }

            printf(" Data = %d\n", gc->icerik);
            gc = gc->sonraki;
        }
    }
}

void tekcift()
{
    printf("\n Listedeki toplam cift sayi iceren dugumlerin sayisi : %d ", cift);
    printf("\n Listedeki toplam tek sayi iceren dugumlerin sayisi : %d ", tek);
}

bool asalmi(int m)
{
        int j;

        for (j = 2; j <= m / 2; ++j) {

        if (m % j == 0) {
            return false;
            break;
           }
    }

    return true;
}


void dugumsil(lst **ref, int anahtar)
{

    lst* gecici = *ref, *pre;


    if (gecici != NULL && gecici->icerik == anahtar)
    {
        *ref = gecici->sonraki;
        free(gecici);
        return;
    }


    while (gecici != NULL && gecici->icerik != anahtar)
    {
        pre = gecici;
        gecici = gecici->sonraki;
    }


    if (gecici == NULL) return;

    pre->sonraki = gecici->sonraki;

    free(gecici);
}
