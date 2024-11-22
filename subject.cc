#include "subject.h"
#include "observer.h"
#include <vector>

//attach observer
void Subject::attach( Observer* o ) {
    observers.emplace_back(o);
}

//remove observer
void Subject::detach( Observer* o ) {
    for (auto it = observers.begin(); it != observers.end();) {
      if (*it == o) it = observers.erase(it);
      else ++it; 
    }

}

//notify observers
void Subject::notifyObservers() {
    for (auto o : observers) o->notify();
}
