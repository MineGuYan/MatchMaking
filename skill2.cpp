#include "skill2.h"

skill2::skill2()
{
    while(Num>=6)
    {
        for(int i=0;i<4;i++)
        {
            int x=rand()%7;
            int y=rand()%7;
            int size=rand()%2;
            if(size==1)
            {
                matrix[x][y]=matrix[x][y]%5+5;
            }
            else matrix[x][y]=matrix[x][y]%5+10;
        }
        Num-=6;
    }
}
