#ifndef _KATA_H
#define _KATA_H

#define KATA_MAXLEN 16

int kata_atoi(const char *nptr);
char * kata_itoa(int n, char *aptr);
void kata_add(const char *aptr, const char *bptr, char *resptr);
void kata_sub(const char *aptr, const char *bptr, char *resptr);

#endif /* _KATA_H */
