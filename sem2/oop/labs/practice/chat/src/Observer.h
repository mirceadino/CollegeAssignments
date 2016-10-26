#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>
#include <string>

class Observer {
  public:
    Observer() {
    }
    virtual std::string getName() = 0;
    virtual void update() = 0;
    virtual ~Observer() {
    }
};

class Subject {
  public:
    Subject() {
    }

    virtual ~Subject() {
    }

    void addObserver(Observer* obs) {
      observers_.push_back(obs);
    }

    void removeObserver(Observer* obs) {
      for (auto& o : observers_)
        if (o == obs) {
          std::swap(o, observers_.back());
          observers_.pop_back();
          return;
        }
    }

    void notify() {
      for (auto& o : observers_)
        o->update();
    }

  protected:
    std::vector<Observer*> observers_;
};

#endif /* OBSERVER_H_ */
