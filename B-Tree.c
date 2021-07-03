// B-Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
{
	int d;
	struct dugum *sol;
	struct dugum *sag;
}*agacB;

agacB yenidugum()
{
    return ((agacB)malloc(sizeof(struct dugum)));
}

agacB dugumgir(int d1, agacB p1, agacB p2)
{
    agacB t;

    t = yenidugum();
    t->d = d1;
    t->sol = p1;
    t->sag = p2;
    return t;
}

agacB agacyap(int a[], int i, int boyut)
{
    if (i >= boyut)
        {
            return NULL;
        }
    else
        {
            return(dugumgir(a[i], agacyap(a, 2*i+1, boyut), agacyap(a, 2*i+2, boyut)));
        }
}

void inorder (agacB kok)
{
    if (kok != NULL) {
        inorder(kok -> sol);
        printf("%d ", kok->d);
        inorder(kok -> sag);
    }
}

int main(void)
{
    int a[17] = { 60, 120, 48, 12, 210,  83, 10, 30, 400, 38, 5, 8, 70,26, 500,600, 180};
    agacB kok;

    kok = agacyap(a, 0, 17) ;

    if(kok != NULL);
    {
         printf("LNR: ");
         inorder(kok);
         printf("\n");
    }

}
