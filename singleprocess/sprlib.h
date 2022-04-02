#ifndef SPRLIB_H
#define SPRLIB_H

struct comments {
  int id;
  float avg_rating;
  unsigned int votes;
};

int zero_rate_count_func(struct comments *coms, int size);

#endif