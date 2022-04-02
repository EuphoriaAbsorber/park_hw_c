#include "mprlib.h"
#include "sprlib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f;
  if ((f = fopen("../src/data10k.txt", "r")) == NULL) {
    fprintf(stderr, "Failed to open file\n");
    return -1;
  }
  struct comments2 abb;
  int count = 0;
  while (fscanf(f, "%d%f%ud", &(abb.id), &(abb.avg_rating), &(abb.votes)) !=
         EOF) {
    if (!f)
      break;
    count++;
  }
  rewind(f);
  const int size = count;
  const int max_size = 10000000;
  int read_size = (size < max_size) ? size : max_size;
  int k = size / max_size;
  if ((size % max_size) != 0)
    k++;
  struct comments2 *wcd = malloc(sizeof(struct comments2) * (read_size + 1));
  int ans = 0;

  for (int j = 0; j < k; j++) {
    for (int i = 0; i < read_size; i++) {
      if (j * read_size + i >= size)
        break;
      if (fscanf(f, "%d%f%u", &(wcd[i].id), &(wcd[i].avg_rating),
                 &(wcd[i].votes)) == EOF) {
        fprintf(stderr, "Failed reading\n");
        return -1;
      }
      // printf("%d \n", wcd[i].id);
    }
    ans += zero_rate_count_func2(wcd, read_size);
  }

  if (fclose(f)) {
    fprintf(stderr, "Failed to close file\n");
    return 1;
  }

  printf("%d записей не имеют оценки \n", ans);
  free(wcd);
  return 0;
}
