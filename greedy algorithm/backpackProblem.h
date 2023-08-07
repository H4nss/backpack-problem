#ifndef BACKPACKPROBLEM_H
#define BACKPACKPROBLEM_H

struct item
{
    int value;
    int weight;
};

class backpack
{
    private:
        item* tabl;
        int maxWeight;
        item* all; // wskaznik do tablicy rzeczy sposrod ktorych musimy wybrac tylko kilka
        int quantity; // liczba rzeczy sposrod ktorych musimy wybrac tylko kilka
        int currentWeight;

    public:
        backpack(int c, int q, item* a);
        void insertByValue();
        void insertByWeight();
        void insertByRatio();
        void show();
        ~backpack();
};

#endif
