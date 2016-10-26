#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>

class Observer {
  public:
    Observer() {
    }

    virtual void update() = 0;

    virtual ~Observer() {
    }
};

class Subject {
  public:
    Subject() {
    }

    virtual void notify() {
      for (auto& o : observers_)
        o->update();
    }

    virtual void attachObserver(Observer* O) {
      observers_.push_back(O);
    }

    virtual void dettachObserver(Observer* O) {
      for (auto& o : observers_)
        if (o == O) {
          std::swap(observers_.back(), o);
          observers_.pop_back();
          return;
        }
    }

    virtual ~Subject() {
      for (auto& o : observers_)
        delete o;
    }

  protected:
    std::vector<Observer*> observers_;
};

#endif /* OBSERVER_H_ */
