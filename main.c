
#include<stdio.h>

int bcmp_custom(char *s1, char *s2, int n);

char foo[] = "Foo";
char lng[] = "VeryVeryLongByteThing";
char one_diff[] = "VeryVeryLxngByteThing";

#define MIN(a1, a2) (a1 < a2 ? a1 : a2)
#define BCMP_TEST(a1, a2)  printf("%s to %s: %d\n", a1, a2, \
						   bcmp_custom(a1, a2, MIN(sizeof(a1), sizeof(a2))))

int
main(int argc, char **argv) {
  BCMP_TEST(foo, lng);
  BCMP_TEST(foo, foo);
  BCMP_TEST(lng, lng);
  BCMP_TEST(lng, one_diff);
  BCMP_TEST("Foo", "");
  return 0;
}
