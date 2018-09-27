#include <stdlib.h>
#include <assert.h>


size_t parse_number(const char s[], int nums[], size_t dest) {
  size_t i;
  nums[dest] = 0;
  for (i = 0; s[i]; ++i)
    if (s[i] < '0' || s[i] > '9')
      break;
    else
      nums[dest] = nums[dest] * 10 + (s[i] - '0');

  return i;
}

#define SKIP_SPACE(msg, i) do { while (msg[i] == ' ') ++i; } while (0)

int calc(const char msg[]) {
  int nums[2];
  size_t i = parse_number(msg, nums, 0);

  SKIP_SPACE(msg, i);
  char op = msg[i]; ++i;
  SKIP_SPACE(msg, i);

  parse_number(msg + i, nums, 1);

  switch (op) {
    case '+': return nums[0] + nums[1];
    case '-': return nums[0] - nums[1];
    case '*': return nums[0] * nums[1];
    case '/': return nums[0] / nums[1];
    default: assert(0);
  }
}

int main(void) {
  return calc("214 / 2");
}
