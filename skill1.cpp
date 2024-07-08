#include "skill1.h"

skill1::skill1()
{
    while(Num>=7)
    {
        int x=rand()%7;
        int y=rand()%7;
        matrix[x][y]=20;
        Num-=7;
    }
}
