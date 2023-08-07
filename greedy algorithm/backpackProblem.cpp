#include "backpackProblem.h"
#include <iostream>

using namespace std;

backpack::backpack(int c, int q, item* a)
{
    currentWeight = 0;
    maxWeight = c;
    quantity = q;
    tabl = new item[quantity];
    all = new item[quantity];

    for(int i = 0; i < c; i++)
    {
        tabl[i].value = 0;
        tabl[i].weight = 0;
    }

    for(int i = 0; i < q; i++)
    {
        all[i].value = a[i].value;
        all[i].weight = a[i].weight;
    }
}

void backpack::insertByValue()
{
    for(int i = 0; i < (quantity - 1); i++) //segreguje wszystkie rzeczy nierosnaco wedlug wartosci
    {
        int min = i;

        for(int j = i + 1; j < quantity; j++)
        {
            if(all[j].value >= all[min].value)
            {
                min = j;
            }
        }

        item x = all[i];
        all[i] = all[min];
        all[min] = x;
    }

    int k = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(currentWeight + all[i].weight <= maxWeight)
        {
            currentWeight = currentWeight + all[i].weight;
            tabl[k] = all[i];
            k++;
        }
    }
}

void backpack::insertByWeight()
{
    for(int i = 0; i < (quantity - 1); i++) //segreguje wszystkie rzeczy niemalejaco wedlug wagi
    {
        int min = i;

        for(int j = i + 1; j < quantity; j++)
        {
            if(all[j].weight <= all[min].weight)
            {
                min = j;
            }
        }

        item x = all[i];
        all[i] = all[min];
        all[min] = x;
    }

    int k = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(currentWeight + all[i].weight <= maxWeight)
        {
            currentWeight = currentWeight + all[i].weight;
            tabl[k] = all[i];
            k++;
        }
    }
}

void backpack::insertByRatio()
{
    for(int i = 0; i < (quantity - 1); i++) //segreguje wszystkie rzeczy niemalejaco wedlug stosunku wartosci do wagi
    {
        int min = i;

        for(int j = i + 1; j < quantity; j++)
        {
            int v1 = all[j].value;
            int v2 = all[min].value;
            int w1 = all[j].weight;
            int w2 = all[min].weight;

            double k = double(v1)/double(w1);
            double l = double(v2)/double(w2);

            if(k >= l)
            {
                min = j;
            }
        }

        item x = all[i];
        all[i] = all[min];
        all[min] = x;
    }

    int k = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(currentWeight + all[i].weight <= maxWeight)
        {
            currentWeight = currentWeight + all[i].weight;
            tabl[k] = all[i];
            k++;
        }
    }
}

void backpack::show()
{
    cout << "value:  " << "weight:" << endl;

    for(int i = 0; i < quantity; i++)
    {
        cout << tabl[i].value << "       " << tabl[i].weight << endl;
    }

    int x = 0;
    int y = 0;

    for(int i = 0; i < quantity; i++)
    {
        x = x + tabl[i].value;
        y = y + tabl[i].weight;
    }

    cout << endl;
    cout << endl << "current value: " << x;
    cout << endl << "current weight: " << y;
}

backpack::~backpack()
{
    delete[] tabl;
}
