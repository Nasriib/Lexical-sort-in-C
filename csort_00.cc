#include "sort.h"
//Sorting function
//
int compare (const void *a, const void *b) {
  const char **s1 = (const char **) a;
  const char **s2 = (const char **) b;
  return strcmp(*s1, *s2);
}
