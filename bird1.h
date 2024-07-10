#ifndef BIRD1_H
#define BIRD1_H

#include "play.h"

class bird1 : public play
{
public:
    bird1();
    ~bird1();
    void Skill();
    QLabel *avatar,*role,*skill;
};

#endif // BIRD1_H
