#define ASSIGN(x, y) \
  y x !

#define CONST(x, y) \
  : x y;

#define DECLARE(x) \
  variable x
#define DECLARE_ARRAY(x, y) \
  variable x y cells
#define DECLARE_MATRIX(xb) \
  variable DIM_##x_1 \
  variable DIM_##x_2 \
  DECLARE_ARRAY(x, 1000)

#define INIT_MATRIX(x, a, b) \
  ASSIGN(DIM_##x_1, a) \
  ASSIGN(DIM_##x_2, b)

#define PUSH(x) \
  x @

#define PUSH_ADDR(x) \
  x

#define PUSH_ELEM(x, a) \
  PUSH_ADDR(x) PUSH(a) + @

#define PUSH_CELL(x, a, b) \
  ASSIGN(aux, a DIM_##x_2 * b +) \
  PUSH_ADDR(x) PUSH(aux) + @

#define IF(cond) \
  PUSH(cond) \
  if
#define THEN
#define ELSE \
  else
#define FI \
  then

#define WHILE(cond) \
  PUSH(cond) \
  while
#define DO
#define DONE(cond) \
  PUSH(cond) \
  repeat

#define FOR(x, y, z) \
  x \
  WHILE(y) DO \
    z \
  DONE(y)
