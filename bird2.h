#ifndef BIRD2_H
#define BIRD2_H

#include "play.h"

class bird2 : public play
{
public:
    bird2();
    bird2(int);
    ~bird2();
    void Skill();
    QLabel *avatar,*role,*skill;
};

#endif // BIRD2_H
