#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "mprlib.h"

int zero_rate_count_func2(struct comments2 *coms, int size) {
  const int proc_count = 2 * sysconf(_SC_NPROCESSORS_ONLN);
  int *ans = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *ans = 0;
  int i = 0;
  pid_t pid;
  int *shared_pid_array =
      mmap(NULL, sizeof(int) * proc_count, PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  for (i = 0; i < proc_count - 1; ++i) {
    if ((pid = fork()) == -1) {
      fprintf(stderr, "Fork failed\n");
      return -1;
    }
    if (pid == 0) {
      // printf("CREATED CHILD %d %d\n", getpid(), i);
      shared_pid_array[i] = getpid();
      break;
    }
  }
  int count_for_each_proc = size / proc_count;
  if (pid == 0) {
    for (int j = count_for_each_proc * i; j < count_for_each_proc * (i + 1);
         j++) {
      if (abs(coms[j].avg_rating) < 0.001)
        (*ans)++;
    }
    // printf("CHILD %d : Hello world!\n", getpid());
    exit(0);
  }
  sleep(1);
  if (i == proc_count - 1) {
    for (int j = count_for_each_proc * i; j < size; j++) {
      if (abs(coms[j].avg_rating) < 0.001)
        (*ans)++;
    }

    for (int j = 0; j < proc_count - 1; j++) {
      int status;
      pid_t result;
      if ((result = waitpid(shared_pid_array[j], &status, 0)) == -1) {
        fprintf(stderr, "Problems with process\n");
        return -1;
      };
      // printf("Waiting for %d %d\n", j, result);
    }
  }
  // printf("PARENT: Forked child\n");
  return *ans;
}