#include "sprlib.h"
#include <stdlib.h>

int zero_rate_count_func(struct comments *coms, int size) {
  int ans = 0;
  for (int i = 0; i < size; i++) {
    if (abs(coms[i].avg_rating) < 0.001)
      ans++;
  }
  return ans;
}