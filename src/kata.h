#ifndef _KATA_H
#define _KATA_H

#define KATA_MAXLEN 16
#define KATA_MAXNUM 3999

/** @brief Converts roman numeral string to integer
 *
 * If the provided string is invalid, the result is 0.
 *
 * @param nptr string containing roman numeral
 * @return integer of result (0 if invalid input given)
 */
int kata_atoi(const char *nptr);

/** @brief Convers integer to roman numeral string
 *
 * If input is out of range (1 to KATA_MAXNUM), the result
 * is an empty string.
 *
 * @param n value to convert
 * @param aptr pointer to buffer where result will be copied (must
               be at least KATA_MAXLEN chars long)
 * @return pointer to given buffer (nptr)
 */
char * kata_itoa(int n, char *aptr);

/** @brief Adds roman numeral strings aptr and bptr
 *
 * If an error is encountered, resptr will be filled with an empty
 * string.
 *
 * @param aptr string containing first roman numeral operand
 * @param bptr string containing second roman numeral operand
 * @param resptr pointer to buffer where result will be copied (must
 *               be at least KATA_MAXLEN chars long)
 * @return void
 */
void kata_add(const char *aptr, const char *bptr, char *resptr);

/** @brief Subtracts roman numeral strings aptr and bptr
 *
 * If an error is encountered, resptr will be filled with an empty
 * string.
 *
 * @param aptr string containing first roman numeral operand
 * @param bptr string containing second roman numeral operand
 * @param resptr pointer to buffer where result will be copied (must
 *               be at least KATA_MAXLEN chars long)
 * @return void
 */
void kata_sub(const char *aptr, const char *bptr, char *resptr);

#endif /* _KATA_H */
