#define IIF(cond) IIF_ ## cond
#define IIF_0(t,f) f
#define IIF_1(t,f) t

IIF(1)(true, false);

#define A 0

IIF(A)(true,false);

#define CAT(a, b) a ## b

#undef IIF
#define IIF(c) CAT(IIF_, c)

IIF(1)(true, false);
// CAT(IIF_, A) -> CAT(IIF_, 0) -> IIF_0
IIF(A)(true,false);

#define COMP(b) CAT(COMP_, b)
#define COMP_0 1
#define COMP_1 0

#define BITAND(x,y) CAT(BITAND_, x) (y)
#define BITAND_0(y) 0
#define BITAND_1(y) y

#define TRUE 1
#define FALSE 0

BITAND(TRUE, TRUE);
BITAND(COMP(BITAND(TRUE, FALSE)), TRUE);

#define CHECK_N(x, n, ...) n
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)
#define PROBE(x) x, 1,

CHECK(PROBE(~)); // -> CHECK(~, 1,) -> CHECK_N(~, 1, 0) -> 1
CHECK(xxx); // -> CHECK_N(xxx,0,) -> 0

#define IS_PAREN(x) CHECK(IS_PAREN_PROBE x)
#define IS_PAREN_PROBE(...) PROBE(~)

IS_PAREN(()); // CHECK(IS_PAREN_PROBE ()) -> CHECK(PROBE(~)) -> 1
IS_PAREN(xxx); // CHECK(IS_PAREN_PROBE xxx) -> 0

#define NOT(x) CHECK(CAT(NOT_, x))
#define NOT_0 PROBE(~)
#define BOOL(x) COMP(NOT(x))
#define IF(c) IIF(BOOL(c))

IF(1)(true, false);
// -> IIF(BOOL(1)) -> IIF(COMP(NOT(1))) -> IIF(COMP(CHECK(CAT(NOT_, 1))))
// -> IIF(COMP(CHECK(NOT_1))) -> IIF(COMP(0)) -> IIF(1)

IF(0)(true, false);
// -> IIF(BOOL(0)) -> IIF(COMP(NOT(0))) -> IIF(COMP(CHECK(CAT(NOT_, 0))))
// -> IIF(COMP(CHECK(NOT_0))) -> IIF(COMP(CHECK(PROBE(~)))) -> IIF(COMP(1))
// -> IIF(0)

IF(xxx)(true, false);
// -> IIF(BOOL(xxx)) -> IIF(COMP(NOT(xxx))) -> IIF(COMP(CHECK(CAT(NOT_, xxx))))
// -> IIF(COMP(CHECK(NOT_xxx))) -> IIF(COMP(0)) -> IIF(1)

