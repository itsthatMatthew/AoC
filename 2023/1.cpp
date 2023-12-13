#include "cstdio"

// the entire puzzle input was pasted here
constexpr auto input = "...";

int main() {
  unsigned sum = 0;
  int first = -1, last = -1;

  // ugly C-stlye walk trough the string
  for (const char *iter = input; *iter != '\0'; iter++) {
    // num is possibly a number 
    unsigned num = *iter - '0';

    // is it really a number?
    if (num < 10) {
      // if so, first in line?
      if (first == -1) {
        // then set both
        first = last = num;
      }
      // otherwise only update last
      last = num;
    }
    // if it was not a number, maybe a newline?
    else if (*iter == '\n') {
      // if so, sum and reset
      sum += first * 10 + last;
      first = last = -1;
    }
  }

  // print result
  printf("%d", sum);
}