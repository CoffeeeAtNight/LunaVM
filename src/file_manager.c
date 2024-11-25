typedef enum {
  TEXT,
  BIN,
  IMG,
  DIR,
} f_type;

typedef struct {
  char*  fileName;
  int    size;
  f_type type;
} file;

char* CURRENT_DIR;
const char* ROOT_DIR;
