#ifndef BIRD4_H
#define BIRD4_H

#include "play.h"

class bird4 : public play
{
public:
    bird4();
    bird4(int);
    ~bird4();
    void Skill();
    QLabel *avatar,*role,*skill;
};

#endif // BIRD4_H
