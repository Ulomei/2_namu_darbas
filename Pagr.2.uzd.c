//Uzduoties nr. - 2
//Salyga - Ivesti sveika skaiciu N. Ivesti N*N sveiku skaiciu, kurie sudarys lentele. Sioje lenteleje kiekvienoje
//eiluteje rasti minimalu skaiciu, o po to ju maksimuma. Atspausdinti rasto skaiciaus koordinates (eilute, stulpelis) ir pati skaiciu.

#include <stdio.h>
#include <stdlib.h>

#define line1 "Programa paprasys ivesti sveika skaiciu N ir vesti N*N sveiku skaiciu, kurie sudarys lentele. Lenteles kiekvienoje eiluteje ras minimalu skaiciu, o po to ju maksimuma. Atspausdins rasto skaiciaus koordinates (eilute, stulpelis) ir pati skaiciu.\n\n"
#define line2 "Iveskite sveika skaiciu N, kuris nurodys lenteles auksti ir ploti. (skaiciu sudaro ne daugiau nei devyni skaitmenys)\n"
#define line3 "Ivestis netinkama. Priimamas tik naturalusis skaicius, kuri sudaro ne daugiau nei devyni skaitmenys.\n"
#define line4 "Suveskite lenteles duomenis (vedama eilutemis). Suveskite"
#define line5 "skaicius\n"
#define line6 "Ivestis netinkama. Priimami tik sveikieji skaiciai, kuriuos sudaro ne daugiau nei devyni skaitmenys.\n"
#define line7 "Duomenys nuskaityti sekmingai!\n\n"
#define line8 "Jusu lentele atrodo taip:"
#define line9 "Maziausia reiksme"
#define line10 "Didziausia reiksme"
#define line11 "Programa negali ivygdyti savo paskirties! Neuztenka vietos masyvui!"

int doValidation (char *msg)        //ivedimas ir tikrinimas
{
    int number;
        while (scanf("%9d", &number) != 1 || getchar() != '\n')
        {
            while (getchar() != '\n')
                ;
            printf("%s", msg);
        }
    return number;
}

int getDataN (int number, char *msg1, char *msg2) // gaunamas skaicius N, kuris nurodys lenteles ploti ir auksti
{
    printf("%s", msg1);
        while (number<=0)
        {
            number = doValidation(msg2);
            if (number<=0)
                printf("%s", msg2);
        }
    return number;
}

int *getDataArray (int n, char *msg1, char *msg2, char *msg3, char *msg4) // suvedami lenteles duomenys
{
    printf("%s %d %s", msg1, n*n, msg2);
    int *data = NULL;
    data = (int*) realloc (data, sizeof(int)*n*n);
    if (data == NULL)
        return data;
    for (int i = 0; i < n*n; ++i)
            *(data+i) = doValidation(msg3);
    printf("%s", msg4);
    return data;
}

void showArray (int *data, int n, char *msg) // isvedama duomenu lentele
{
    printf ("%s", msg);
    for (int i = 0; i < n*n; ++i)
    {
        if (i%n == 0)
            printf ("\n");
        printf ("%-9d ", *(data+i));
    }
    printf("\n\n");
}

void printAnswer (char *msg, int extreme, int i, int* data, int n)
{
    printf ("%s %d", msg, extreme);

    for (int j = 0; j < n; ++j)
        {
            if (*(data+i*n+j) == extreme)
            {
                printf(" (%d, %d)",  i+1, j+1);
            }
        }
    printf ("\n");
}

void countSmallLarge (int *data, int n) // apskaiciuojamos didziausios ir maziausios reiksmes ir jos isvedamos
{
    int smallest, biggest;
    for (int i = 0; i < n; ++i)
    {
        smallest = *(data+i*n);
        biggest = *(data+i*n);
        for (int j = 1; j < n; ++j)
        {
            if (*(data+i*n+j) <= smallest)
            {
                smallest = *(data+i*n+j);
            }
            if (*(data+i*n+j) >= biggest)
            {
                biggest = *(data+i*n+j);
            }
        }
        printAnswer(line9, smallest, i, data, n);
        printAnswer(line10, biggest, i, data, n);
    }
}

int main()
{   int n=0, number;
    int *data;
    printf("%s", line1);

    n = getDataN(n, line2, line3);

    data = getDataArray(n, line4, line5, line6, line7);
    if (data == NULL)
        printf ("%s", line11);
    else
    {
        showArray(data, n, line8);
        countSmallLarge (data, n);
        free (data);
    }
    return 0;
}
