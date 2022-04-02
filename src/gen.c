#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  const int size = 1000000;
  FILE *f;
  // print_hello();
  if ((f = fopen("data1kk.txt", "w")) == NULL) {
    fprintf(stderr, "Failed to open file\n");
    return -1;
  }
  for (int i = 0; i < size; i++) {
    int r = 100 + rand() % 401;
    float v = (float)r / 100;
    int count = rand() % 10000;
    if (count == 0)
      v = 0;
    fprintf(f, "%d %.2f %d\n", i, v, count);
  }

  if (fclose(f)) {
    fprintf(stderr, "Failed to close file\n");
    return 1;
  }

  return 0;
}
