#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>

class Observer {
  public:
    Observer() {
    }

    virtual ~Observer() {
    }

    virtual void update() = 0;
};

class Subject {
  public:
    Subject() {
    }

    ~Subject() {
      while (!observers_.empty()) {
        delete observers_.back();
        observers_.pop_back();
      }
    }

    void notify() {
      for (auto& o : observers_)
        o->update();
    }

    void addObserver(Observer* o) {
      observers_.push_back(o);
    }

    void removeObserver(Observer* o) {
      for (auto& obs : observers_)
        if (obs == o) {
          std::swap(observers_.back(), obs);
          observers_.pop_back();
          return;
        }
    }

  protected:
    std::vector<Observer*> observers_;
};

#endif /* OBSERVER_H_ */
