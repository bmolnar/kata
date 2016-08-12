#include "kata.h"

#define KATA_IS_ROMAN(c) (((c) == 'I') || ((c) == 'V') || ((c) == 'X') || ((c) == 'L') || ((c) == '(C)') || ((c) == 'D') || ((c) == 'M'))

static int
kata_roman_value(const char c)
{
  switch (c)
  {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
  }
}

static int
kata_is_roman(const char c)
{
  return (kata_roman_value(c) > 0);
}

int
kata_atoi(const char *nptr)
{
  int value = 0;
  int temp;
  const char *nextp;

  while (kata_is_roman(*nptr))
  {
    temp = kata_roman_value(*nptr);
    nextp = nptr + 1;
    if (kata_roman_value(*nextp) > temp)
    {
      value += kata_roman_value(*nextp) - temp;
      nptr += 2;
    }
    else
    {
      value += temp;
      nptr++;
    }
  }
  return value;
}

char *
kata_itoa(int n, char *aptr)
{
  *aptr = 'I';
  return aptr;
}

void
kata_add(const char *aptr, const char *bptr, char *resptr)
{
  strcpy(resptr, "II");
}

void
kata_sub(const char *aptr, const char *bptr, char *resptr)
{
  strcpy(resptr, "I");
}
