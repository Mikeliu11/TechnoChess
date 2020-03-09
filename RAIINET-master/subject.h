#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "state.h"

class Observer;

class Subject {
    std::vector<Observer *> observers;
    State state;

   public:
    virtual ~Subject();
    void attach(Observer *ob);
    void notifyObservers();
    State getState();
    void setState(State s);
};
#endif
