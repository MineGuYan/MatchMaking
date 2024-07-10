#include "skill0.h"

skill0::skill0()
{
    while(Num>=5)
    {
        for(int k=0;k<=1;k++)
        {
            int x=rand()%6;
            int y=rand()%6;
            for(int i=x;i<=x+1;i++)
            {
                for(int j=y;j<y+1;j++)
                {
                    if(matrix[i][j]<5)
                    {
                        if(matrix[i][j]==People)Num++;
                        matrix[i][j] = -1;
                    }
                    else if (matrix[i][j] / 5 == 1)
                    {
                        Skillone(j);
                    }
                    else if (matrix[i][j] / 5 == 2)
                    {
                        Skilltwo(i);
                    }
                    else if(matrix[i][j] / 5 == 3)
                    {
                        Skillthree(i,j);
                    }
                }
            }
        }
        Num-=5;
        fall();
    }
}
