#include <iostream>
using namespace std;

void kabarcik(int dizi[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (dizi[j] > dizi[j + 1])
            {
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
}

void yerlestirmeli(int dizi[], int n)
{
    int i, j, anahtar;
    for (i = 1; i < n; i++)
    {
        anahtar = dizi[i];
        j = i - 1;
        while (j >= 0 && dizi[j] > anahtar)
        {
            dizi[j + 1] = dizi[j];
            j = j - 1;
        }
        dizi[j + 1] = anahtar;
    }
}

void secmeli(int arr[], int n)
{
    int enkucuk, yedek;
    for (int i = 0; i < n - 1; i++)
    {
        enkucuk = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[enkucuk])
            {
                enkucuk = j;
            }
        }
        if (enkucuk != i)
        {
            yedek = arr[i];
            arr[i] = arr[enkucuk];
            arr[enkucuk] = yedek;
        }
    }
}

void kabuk(int dizi[], int n)
{
    for (int a = n / 2; a > 0; a /= 2)
    {
        for (int i = a; i < n; i += 1)
        {
            int temp = dizi[i];
            int j;
            for (j = i; j >= a && dizi[j - a] > temp; j -= a) {
                dizi[j] = dizi[j - a];
            }
            dizi[j] = temp;
        }
    }

}

int bolumlendir(int dizi[], int kucuk, int buyuk)
{
    int pivot = dizi[buyuk];
    int i = (kucuk - 1);
    for (int j = kucuk; j <= buyuk - 1; j++)
    {
        if (dizi[j] < pivot)
        {
            i++;
            int temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
        }

    }

    int temp = dizi[i + 1];
    dizi[i + 1] = dizi[buyuk];
    dizi[buyuk] = temp;
    return (i + 1);
}

void hizlisiralama(int dizi[], int kucuk, int buyuk)
{
    if (kucuk < buyuk)
    {
        int pi = bolumlendir(dizi, kucuk, buyuk);
        hizlisiralama(dizi, kucuk, pi - 1);
        hizlisiralama(dizi, pi + 1, buyuk);

    }

}

int main()
{
    int dizi[5] = { 41, 12, 14, -14, -9 };
    //kabarcik(dizi, 5);
    //yerlestirmeli(dizi, 5);
    //secmeli(dizi, 5); 
    //kabuk(dizi, 5); 
    hizlisiralama(dizi, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << dizi[i] << " ";
    return 0;
}