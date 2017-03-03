#include "lab2.h"

float *x;
float **a;
float **b;
float **y;

int  autoset_var(int n, int nr_filtre, int k, int p, int user)
{
  int i,j;

  //Alocare memorie pentru x
          x = (float *)malloc(n * sizeof(float));
          if(!x)
            return(printf("Error malloc x\n"));
            if (user == 0)
              initialize_uni(x, n, 1.0,0.0,-1.0,2.0,-3.0,4.0,2.0,-3.0,1.0,2.0,-1.0);
            else
              user_initialize_uni(x, n, "INITIALIZARE X");


  //Alocare memorie pentru a
          a = (float **)malloc(nr_filtre * sizeof(float *));
          if (!a)
            return(printf("Error malloc a\n"));
          i = 0;
          while (i < nr_filtre)
          {
            a[i] = (float *)malloc(k * sizeof(float));
            if (!a[i])
              return(printf("Error malloc a[i]\n"));
            i++;
          }
          initialize_bi(a, nr_filtre, k,  -1.0,     0.0,    1.0,
                                          1.0,     -1.0,    0.0,
                                          -1.5,   1.0,    0.5,
                                          0.0,      1.0,    1.0,
                                          0.5,    0.0,    1.0,
                                          -0.5,   1.0,    1.0,
                                          -1.0,     0.5,  0.5);

  //Alocare memorie pentru b
          b = (float **)malloc(nr_filtre * sizeof(float *));
          if (!b)
            return(printf("Error malloc b\n"));
          i = 0;
          while (i < nr_filtre)
          {
            b[i] = (float *)malloc(p * sizeof(float));
            if (!b[i])
              return(printf("Error malloc b[i]\n"));
            i++;
          }
          initialize_bi(b, nr_filtre, p + 1,    0.0,   1.0,    -1.0,     0.0,
                                                0.0,   0.0,     1.0,     -1.0,
                                                0.0,   0.5,     0.5,     1.0,
                                                0.0,   -0.5,    0.5,     1.0,
                                                0.0,   0.5,     -0.5,    1.0,
                                                0.0,   -1.0,   -0.5,     0.5,
                                                0.0,   -1.0,    0.0,    -1.0);

  //Alocare memorie pentru y
          y = (float **)malloc(n * sizeof(float *));
          i = 0;
          while (i < n)
          {
              y[i] = (float *)malloc(nr_filtre * sizeof(float));
              if (!y[i])
                return(printf("Error malloc y[i]\n"));
              i++;
          }

          // initialize_bi(y,n,nr_filtre,  1.0,1.0,1.0,1.0,2.0,1.0,1.0,
          //                               2.0,2.0,4.0,5.0,2.0,1.0,2.0,
          //                               2.0,1.0,1.0,-1.0,-2.0,1.0,3.0,
          //                               8.0,8.0,8.0,9.0,9.0,9.0,8.0,
          //                               7.0,8.0,8.0,8.0,9.0,9.0,9.0,
          //                               9.0,9.0,9.0,9.0,9.0,9.0,9.0,
          //                               1.0,1.0,2.0,-1.0,2.0,-1.0,3.0,
          //                               1.0,1.0,1.0,1.0,1.0,2.0,1.0,
          //                               5.0,5.0,5.0,5.0,5.0,5.0,5.0,
          //                               6.0,6.0,6.0,6.0,6.0,6.0,7.0,
          //                               4.0,5.0,6.0,5.0,5.0,5.0,6.0);


}

void print_y(int n, int nr_filtre)
{
  int i;
  int k_filtru;

  printf("%c\t", 'n');
  k_filtru = 0;
  while (k_filtru < nr_filtre)
  {
    printf("%15s", ft_strjoin("F", ft_itoa(k_filtru + 1)));
    k_filtru++;
  }
  printf("\n" );


  i = 0;
  while (i < n)
    {
      printf("%d\t", i);
      k_filtru = 0;
      while (k_filtru < nr_filtre)
      {
        printf("%15f", y[i][k_filtru]);
        k_filtru++;
      }
      printf("\n" );
      i++;
    }
}

void print_y_and_classes(int n, int nr_filtre, char clases[11][3], int prag)
{
  int i;
  int k_filtru;

  i = 0;
  printf("%c\t", 'n');
  k_filtru = 0;
  while (k_filtru < nr_filtre)
  {
    printf("%15s", ft_strjoin("F", ft_itoa(k_filtru + 1)));
    k_filtru++;
  }

  printf("%10s\n\n",ft_strjoin("Tpr=", ft_itoa(prag) ));

  while (i < n)
    {
      printf("%d\t", i);
      k_filtru = 0;
      while (k_filtru < nr_filtre)
      {
        printf("%15f", y[i][k_filtru]);
        k_filtru++;
      }
      printf("%10s\n", clases[i]);
      i++;
    }
}

void filtrare(int n, int nr_filtre, int k, int p)
{
  int i;
  int n_i;
  int k_filtru;
  float x_value;
  float y_value;
  float sum1, sum2;

  printf("\nFILTRARE\n" );
  k_filtru = 0;
  while (k_filtru < nr_filtre)
  {
      n_i = 0;
      while(n_i < n )
      {
        sum1 = 0;
        sum2 = 0;
        i = 0;
        while (i < k)
        {
          if (n_i - i < 0)
            x_value = 0;
          else
            x_value = x[n_i - i];
          sum1 = sum1 + a[k_filtru][i] * x_value;
          i++;
        }

        i = 1;
        while (i < p + 1)
        {
          if (n_i - i < 0)
            y_value = 0;
          else
            y_value = y[n_i - i][k_filtru];
          sum2 = sum2 + b[k_filtru][i] * y_value;
          i++;
        }
        y[n_i][k_filtru] = sum1+ sum2;
        n_i++;
      }
      k_filtru++;
  }

  print_y(n, nr_filtre);
  printf("\n\n" );
}

void segmentare(int n, int nr_filtre, int prag)
{
  int clase_nucleu_index = 0;
  int clase_index = 0;
  char *nume;
  int i;                      //Var de iterare
  int j;                      //Var de iterare
  int k;                      //Var de iterare
  float sum;                  //Suma diferentelor la fiecare iteratie
  int stop = 0;               //Flag ajutator
  t_clasa *clase_nucleu[10];  //Lista de clase nucleu
  char  clase[11][3];         //Lista de clase determinate pentru fiecare n

  printf("SEGMENTARE\n" );

  //CREARE PRIMA CLASA in lista claselor de clase nuclee
    clase_nucleu[clase_nucleu_index++] = create_clasa(0, "C1");

  //Initializarea n=0 cu aceasta clasa (adica clasa C1)
    strcpy(clase[clase_index++], "C1");

    i = 1;
    while (i < n)
    {
      stop = 0;
      k = 0;
      //Calculeaza atita timp cit mai exista clase nucleu
      //si nu s-a gasit clasa corecta. (adica flagul stop == 0)
      while (k < clase_nucleu_index && stop == 0)
      {
            j = 0;
            sum = 0;
            //Calculeaza suma diferentelor dintre rindul i si clasa k
            while (j < nr_filtre)
            {
              sum = sum + fabs(y[clase_nucleu[k]->index][j] - y[i][j]);
              j++;
            }

            //Daca suma primita e mai mica ca pragul ...
            if (sum < prag)
            {
              //... atunci clasa este potrivita, si spunem
              // ca nu mai e nevoie sa se caute o alta clasa (adica setam flagul stop = 1)
              stop = 1;
              strcpy(clase[i], clase_nucleu[k]->nume);
            }
            //Daca suma primita e mai mare ca pragul ...
            else
            {
              //si Daca e ultima clasa nucleu precautata ...
              if (k == clase_nucleu_index - 1)
              {
                //... atunci se CREEAZA o clasa noua
                nume = ft_itoa(clase_nucleu_index + 1);
                //Se seteaza numele clasei noi, si spunem
                clase_nucleu[clase_nucleu_index++] = create_clasa(i, ft_strjoin("C", ft_itoa(clase_nucleu_index)));
                strcpy(clase[i], clase_nucleu[clase_nucleu_index-1]->nume);
                // ca nu mai e nevoie sa se caute o alta clasa (adica setam flagul stop = 1)
                stop = 1;
              }
            }
            //Mergem la alta clasa nucleu
            k++;
      }
      i++;
    }
    print_y_and_classes (n, nr_filtre, clase,prag);
}

int main(int argc, char **argv)
{
  int n;
  int nr_filtre;
  int k = 3;
  int p = 3;
  int prag;

  if (argc == 3)
{
    n = ft_atoi(argv[1]);
    nr_filtre =  ft_atoi(argv[2]);
}
  else
{
      n = 11;
      nr_filtre = 7;
}

  autoset_var(n,nr_filtre,k,p,1);

  filtrare(n,nr_filtre,k,p);
  printf("Introduceti pragul: " );
  scanf("%d", &prag);
  while ( prag != -1)
  {
      segmentare(n, nr_filtre, prag);
      printf("Introduceti pragul: " );
      scanf("%d", &prag);
  }

  return (0);
}
