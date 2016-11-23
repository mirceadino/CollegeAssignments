#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>

class Observer {
  public:
    virtual void update() = 0;
    virtual ~Observer() {
    }
};

class Subject {
  public:
    virtual ~Subject() {
    }

    void notify() {
      for (auto o : observers_)
        o->update();
    }

    void addObserver(Observer* o) {
      observers_.push_back(o);
    }

    void removeObserver(Observer* o) {
      for (auto& op : observers_)
        if (op == o) {
          std::swap(observers_.back(), op);
          observers_.pop_back();
          return;
        }
    }

  protected:
    std::vector<Observer*> observers_;
};

#endif /* OBSERVER_H_ */
