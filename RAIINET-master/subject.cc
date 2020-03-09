#include "subject.h"
#include "observer.h"
#include <iostream>
#include <ostream>
using namespace std;

void Subject::attach(Observer *ob)
{
    observers.emplace_back(ob);
}
void Subject::notifyObservers()
{
    for (auto &ob : observers)
    {
        ob->notify(*this);
    }
}

State Subject::getState() { return state; }

void Subject::setState(State s) { state = s; }

Subject::~Subject() {}
