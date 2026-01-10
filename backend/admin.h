#ifndef __ADMIN_H__
#define __ADMIN_H__

#include "person.h"

class Admin : public Person {
    public:
        Admin(int age, string name, string id, string sex) : Person(age, name, id, sex, true) {};
        ~ Admin();
};


#endif