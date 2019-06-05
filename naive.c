
#include<stdint.h>
#include<stddef.h>

int 
naive(char *c, char *c2, size_t n){
  for (int i = 0; i < n; i++) {
	if (c[i] != c2[i])
	  return 0;
  }
  return 1;
}
