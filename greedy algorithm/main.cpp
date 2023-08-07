#include <iostream>
#include "backpackProblem.h"

using namespace std;

int main()
{
    int max_weight = 15;
    int number_of_items = 7;
    item things[]={{1,4},{5,2},{1,1},{1,2},{4,3},{6,7},{2,4}};
    backpack a(max_weight,number_of_items,things);
    a.insertByRatio();
    a.show();

}
