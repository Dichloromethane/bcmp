
#include<stdio.h>
#include<stdlib.h>

int bcmp_custom(char *s1, char *s2, int n);

char foo[] = "Foo";
char lng[] = "VeryVeryLongByteThingDUUDUDUDUDUDUDU";
char one_diff[] = "VeryVeryLongByteThingDUUDUDUDUDUDUDX";


#define FORM_STR ("\"%s\" to \"%s\": %d, should be %d\n")
#define MIN(a1, a2) (a1 < a2 ? a1 : a2)
#define BCMP_TEST(a1, a2, res)  printf(FORM_STR, a1, a2, \
						   bcmp_custom(a1, a2, MIN(sizeof(a1), sizeof(a2))),\
						   res)
#define BCMP_TEST_L(a1, a2, l, res)  printf(FORM_STR, a1, a2, \
						        bcmp_custom(a1, a2, l), res)

#define N 0x10000

int
main(int argc, char **argv) {
  char *c, *c2, *c3;
  c = calloc(N, 1);
  c2 = calloc(N, 1);
  c3 = calloc(N, 1);
  c3[N-1] = 'A';
  BCMP_TEST(foo, lng, 0);
  BCMP_TEST(foo, foo, 1);
  BCMP_TEST(lng, lng, 1);
  BCMP_TEST(lng, one_diff, 0);
  BCMP_TEST("Foo", "", 0);
  BCMP_TEST("", "", 1);
  BCMP_TEST_L(c, c2, N, 1);
  BCMP_TEST_L(c, c3, N, 0);
  return 0;
}
