/* for.h */
#define x	INC(x)
#define PRIMITIVE_CAT(a, ...)	a## __VA_ARGS__
#define INC(x) PRIMITIVE_CAT(INC_, x)
#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_8 9
#define INC_9 9

#define NdV(a,x)	PRIMITIVE_CAT(a,INC(x))
#define NUM_0	0
#define NUM_1	1
#define NUM_2	2
#define NUM_3	3
#define NUM_4	4
#define NUM_5	5
#define NUM_6	6
#define NUM_7	7
#define NUM_8	8
#define NUM_9	9

#if(x<5)

*(Cj+(x))=NdV(c,INC(x));
//x=INC(x);
#include "for.h"

#endif
