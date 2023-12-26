#ifndef TIMER_H_
#define TIMER_H_

#include <iostream>

class timer{
 public:
  timer();

  void start();
  void stop();
  void pause();
  void unpause();
  void reset();

  uint64_t get_time();

 private:
  uint64_t start_time;
  uint64_t paused_time;

  bool is_started;
  bool is_paused;
};

#endif //TIMER_H_
