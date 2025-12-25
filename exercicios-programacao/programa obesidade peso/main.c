#include <stdio.h>
#include <math.h>

float Mosteller (int pe, float alt)
{
  float area;
  area = sqrt (pe * 1000 * alt) / 60;
  printf ("\nArea Calculada:%.3f", area);

  return area;
}

float MetaPeso (int m2, float meta)
{

  printf ("\nProgresso:%.1f", meta - m2);

  if (m2 > meta)
    {
      printf ("\nTu precisa perder peso");
    }
  else
    {
      printf ("\nVoce bateu a meta");
    }
}

int main ()
{
  int peso;
  float altura;
  float metaUser;
  printf ("\nInsira peso e altura:");
  scanf ("%d %f", &peso, &altura);
  Mosteller (peso, altura);
  printf ("\nInsira meta de area corporal:");
  scanf ("%f", &metaUser);


  MetaPeso (Mosteller (peso, altura), metaUser);

  return 0;
}
