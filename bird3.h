#ifndef BIRD3_H
#define BIRD3_H

#include "play.h"

class bird3 : public play
{
public:
    bird3();
    bird3(int);
    ~bird3();
    void Skill();
    QLabel *avatar,*role,*skill;
};

#endif // BIRD3_H
