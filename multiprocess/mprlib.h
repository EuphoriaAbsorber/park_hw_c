#ifndef MPRLIB_H
#define MPRLIB_H

struct comments2 {
    int id;
    float avg_rating;
    unsigned int votes; 
};

int zero_rate_count_func2(struct comments2 *coms, int size);

#endif