// Create a Max-Heap then delete the root two times

#include <stdio.h>

int boy = 0;
void degistir(int *a, int *b)
{
  int gecici = *b;
  *b = *a;
  *a = gecici;
}
void yap(int heap[], int boy, int i)
{
  if (boy == 1)
  {
    printf("Tek eleman... ");
  }
  else
  {
    int tepe = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;
    if (sol < boy && heap[sol] > heap[tepe])
      tepe = sol;
    if (sag < boy && heap[sag] > heap[tepe])
      tepe = sag;
    if (tepe != i)
    {
      degistir(&heap[i], &heap[tepe]);
      yap(heap, boy, tepe);
    }
  }
}
void insert(int heap[], int gir)
{
  if (boy == 0)
  {
    heap[0] = gir;
    boy += 1;
  }
  else
  {
    heap[boy] = gir;
    boy += 1;
    for (int i = boy / 2 - 1; i >= 0; i--)
    {
      yap(heap, boy, i);
    }
  }
}

koksil(int heap[])
{
  int i = 0;
  degistir(&heap[i], &heap[boy - 1]);
  boy -= 1;
  for (int i = boy / 2 - 1; i >= 0; i--)
  {
    yap(heap, boy, i);
  }
}

void heapgoster(int heap[], int boy)
{
  for (int i = 0; i < boy; ++i)
    printf("%d ", heap[i]);
  printf("\n");
}

int main()
{
  int heap[12];

  insert(heap, 48);
  insert(heap, 76);
  insert(heap, 68);
  insert(heap, 23);
  insert(heap, 58);
  insert(heap, 42);
  insert(heap, 11);
  insert(heap, 60);
  insert(heap, 70);
  insert(heap, 80);
  insert(heap, 55);
  insert(heap, 50);

  printf(" Maximum Heap: ");
  heapgoster(heap, boy);

 int p;
 for(p=1; p<3; p++)
  {
      koksil(heap);
      printf(" Kok %d silindikten sonra: ", p);
      heapgoster(heap, boy);
  }
}
