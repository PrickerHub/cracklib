/*
 * This program is copyright Alec Muffett 1993. The author disclaims all 
 * responsibility or liability with respect to it's usage or its effect 
 * upon hardware or computer systems, and maintains copyright as set out 
 * in the "LICENCE" document which accompanies distributions of Crack v4.0 
 * and upwards.
 */

#include "config.h"
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include "packer.h"

int
main ()
{
    uint32_t i;
    PWDICT *pwp;
    char buffer[STRINGSIZE];

    if (!(pwp = PWOpen (NULL, "r")))
    {
	perror ("PWOpen");
	return (-1);
    }

    printf("enter dictionary words, one per line...\n");

    while (fgets (buffer, STRINGSIZE, stdin))
    {
    	uint32_t i;

	Chop(buffer);
	i = FindPW(pwp, buffer);
	printf ("%s: %lu%s\n", buffer, i, (i==PW_WORDS(pwp) ? " **** NOT FOUND ****" : ""));
    }

    return (0);
}
