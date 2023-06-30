// C TYPES FOR KURIOS


#ifndef _KURIOS_CTP_H
#define _KURIOS_CTP_H


#define _U	0x01	// Uppercase
#define _L	0x02	// Lowercase
#define _N	0x04	// Numbers
#define _S	0x08	// Space
#define _P	0x10	// Punctuation
#define _C	0x20	// Control
#define _X	0x40	// Hexadecimal
#define _B	0x80	// Blank


extern unsigned char _ctp[];


#define ALPHA(ch)	((_ctp + 1)[ch] & (_U | _L))
#define UPPER(ch)	((_ctp + 1)[ch] & _U)
#define LOWER(ch)	((_ctp + 1)[ch] & _L)
#define DIGIT(ch)	((_ctp + 1)[ch] & _N)
#define ANUM(ch)	((_ctp + 1)[ch] & (_U | _L | _N))
#define SPACE(ch)	((_ctp + 1)[ch] & _S)
#define PUNCT(ch)	((_ctp + 1)[ch] & _P)
#define CTRL(ch)	((_ctp + 1)[ch] & _C)
#define HEXDIG(ch)	((_ctp + 1)[ch] & (_N | _X))

#define ASCII(ch)	((unsigned) ch <= 0x7F)
#define TOASCII(ch)	((unsigned) ch <= 0x7F)

#define TOUP(ch)	((ch) & ~32)
#define TOLOW(ch)	((ch) | 32)

#endif
