// Author (Created): Roger "Equah" Hürzeler
// Date (Created): 12019.12.25 HE
// License: apache-2.0

#include "equah/historia.h"

// [i] Function declarations.
void counter_increment(int);
void counter_set(int);

// [i] Local variables.
int counter = 0;
char *counter_name = "Example Counter";

// [>] Main
int main() {
  
  // [i] First log message indicating that counter starts.
  equah_historia__log(equah_historia__lvl_info, "counter.c > int main() > 1", "Counter example started.", (const equah_historia__LogData[]) {
    {"Counter start value", equah_historia__dt_int, NULL, &counter},
    {"Counter Name", equah_historia__dt_str, NULL, counter_name}
  }, 2);
  
  // [i] Do some stuff with counter.
  counter_set(10);
  counter_increment(500);
  counter_increment(-120);
  counter_increment(30);
  
  
  // [i] Last log message indicating that counter ended.
  equah_historia__log(equah_historia__lvl_info, "counter.c > int main() > 2", "Counter example end.", (const equah_historia__LogData[]) {
    {"Counter exit value", equah_historia__dt_int, NULL, &counter}
  }, 1);
  
  return 0;
}

// [>] Counter Increment
// [i] Increments the counter value by given value.
// [P] {int} inc => Amount to add to the counter value.
void counter_increment(int inc) {
  
  int previous_value = counter;
  counter += inc;
  
  // [i] Log message counter increment.
  // [NOTE] Increment uses special formatting in data output.
  equah_historia__log(equah_historia__lvl_info, "counter.c > void counter_increment(int) > 1", "Counter increment.", (const equah_historia__LogData[]) {
    {"Counter before increment", equah_historia__dt_int, NULL, &previous_value},
    {"Increment", equah_historia__dt_int, ">> %i <<", &inc},
    {"Counter after increment", equah_historia__dt_int, NULL, &counter}
  }, 3);
  
}

// [>] Counter Set
// [i] Sets the counter to a given value.
// [P] {int} set => Value to set the counter to.
void counter_set(int set) {
  
  int previous_value = counter;
  counter = set;
  
  // [i] Log message counter set.
  equah_historia__log(equah_historia__lvl_info, "counter.c > void counter_set(int) > 1", "Counter set.", (const equah_historia__LogData[]) {
    {"Counter before set", equah_historia__dt_int, NULL, &previous_value},
    {"Counter set value", equah_historia__dt_int, NULL, &counter}
  }, 2);
  
}
