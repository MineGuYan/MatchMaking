#include "skill4.h"

skill4::skill4()
{
    while(Num>=7)
    {
        for(int i=0;i<4;i++)
        {
            int x=rand()%7;
            int y=rand()%7;
            matrix[x][y]=matrix[x][y]%5+15;
        }
    }
}
