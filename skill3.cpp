#include "skill3.h"

skill3::skill3()
{
    while(Num>7)
    {
        int x=rand()%7;
        int y=rand()%7;
        Skillone(y);
        Skilltwo(x);
    }
}
