
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

int bcmp_custom(char *s1, char *s2, ssize_t n);

char foo[] = "Foo";
char lng[] = "VeryVeryLongByteThing";
char one_diff[] = "VeryVeryLxngByteThing";

#define MIN(a1, a2) (a1 < a2 ? a1 : a2)
#define BCMP_TEST(a1, a2)  printf("%s to %s: %d\n", a1, a2, \
						   bcmp_custom(a1, a2, MIN(sizeof(a1), sizeof(a2))))

#define STRINGIFY(x) #x

#define TEST_FUNC_NAME(f, name, c, c2, l) do {\
      uint64_t t1, t2; \
  	  f(c, c2, 0x10000); \
  	  asm volatile("mfspr %0, 776": "+r"(t1)::); \
      f(c, c2, 0x10000); \
      asm volatile("mfspr %0, 776": "+r"(t2)::); \
      printf(name ":%f\n", 0x10000/((double) t2 - t1));\
	} while(0);

#define TEST_FUNC(f, c, c2, l) TEST_FUNC_NAME(f, STRINGIFY(f), c, c2, l)
#define TEST(c, c2, l) TEST_FUNC(bcmp_custom, c, c2, l)


int 
naive(char *c, char *c2, size_t n);

int
main(int argc, char **argv) {
  char *c = calloc(0x10000, 1);
  char *c2 = calloc(0x10000, 1);


  bcmp_custom(c, c2, 0x10000); 
  asm volatile("mfspr %0, 776": "+r"(t1)::); 
  bcmp_custom(c, c2, 0x10000); 
  asm volatile("mfspr %0, 776": "+r"(t2)::); 

  printf("%f\n", 0x10000/((double) t2 - t1));

  asm volatile("mfspr %0, 776": "+r"(t1)::); 
  naive(c, c2, 0x10000); 
  asm volatile("mfspr %0, 776": "+r"(t2)::); 

  printf("%f\n", 0x10000/((double) t2 - t1));

  return 0;
}
