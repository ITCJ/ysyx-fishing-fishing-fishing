#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NUM,

  /* TODO: Add more token types */
  TK_HEX, TK_REG, TK_PARE,

  TK_PLUS = '+', TK_MIN = '-', TK_MUL = '*', TK_DIV = '/'

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +",                  TK_NOTYPE},       // spaces

  {"0x[0-9,a-f]*",        TK_HEX},          //hex num
  {"\\$[0-9,a-z]{1,3}",   TK_REG},          //reg begin with "$"
  {"\\(.*\\)",            TK_PARE},         // le ri pare

  {"\\+",                 '+'},             // plus
  {"\\-",                 '-'},             //sub
  {"\\*",                 '*'},             //mul
  {"\\/",                 '/'},             //div
  
  {"[0-9]+",              TK_NUM},
  
  {"==",                  TK_EQ},           // equal
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

//TCJ 记录token
typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

//TCJ make_token 识别token
static bool make_token(char *e) {
  int position = 0; //当前处理到的位置
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",    //输出成功信息
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        assert(rules[i].token_type);
        printf("%d--%d\n", nr_token, rules[i].token_type);
        switch (rules[i].token_type) {
          case TK_NOTYPE:
          case TK_PARE:
          case '+':
          case '-':
          case '*':
          case '/':
          case TK_EQ:
            tokens[nr_token].type = rules[i].token_type;
          break;
          
          case TK_HEX:
          case TK_REG:
          case TK_NUM:
            strncpy(tokens[nr_token].str, substr_start,substr_len );
            tokens[nr_token].type = rules[i].token_type;
          break;

          default: TODO();
        }
        
        nr_token ++;

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

//TCJ expr
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  TODO();

  return 0;
}
