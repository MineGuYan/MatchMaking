#ifndef BIRD0_H
#define BIRD0_H

#include "play.h"

class bird0 : public play
{
public:
    bird0();
    bird0(int);
    ~bird0();
    void Skill();
    QLabel *avatar,*role,*skill;
};

#endif // BIRD0_H
