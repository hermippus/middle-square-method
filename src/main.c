#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned int middle_square(unsigned int seed, int n) {
  unsigned long long square = (unsigned long long) seed * seed;
  int total_digits = 2 * n;

  char buffer[total_digits + 1];
  snprintf(buffer, sizeof(buffer), "%0*llu", total_digits, square);
  int start = (total_digits - n) / 2;
  
  char middle_str[n + 1];
  strncpy(middle_str, buffer + start, n);
  middle_str[n] = '\0';

  unsigned int new_seed = (unsigned int)atoi(middle_str);
  return new_seed;
}

int main(int argc, char *argv[]) {
  time_t t = time(NULL);
  unsigned long long seed = t * t;
  int digits = 4;

  int num = middle_square(seed, digits);
  int randomNumber = middle_square(num, digits);
  printf("Random number: %d", randomNumber);
  return 0;
}
