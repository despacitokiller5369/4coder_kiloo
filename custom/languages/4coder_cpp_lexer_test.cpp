/*
4coder_lexer_cpp_test.cpp - A tester for the C++ lexer.
*/

// TOP

#if 0

0.
0.f
0.1
0.1f
0.0
0.0f
0.F
0.0F
.0
.0f
.1
.9
.1f
.9f
0.e1
0.e1f
0.e1F
0.E1f
0.E1F
0.e+1
0.e+1f
0.e+1F
0.E+1f
0.E+1F
0.e-1
0.e-1f
0.e-1F
0.E-1f
0.E-1F

0.l
0.1
0.1l
0.0l
0.L
0.0L
.0l
.1l
.9l
0.e1
0.e1l
0.e1L
0.E1l
0.E1L
0.e+1
0.e+1l
0.e+1L
0.E+1l
0.E+1L
0.e-1
0.e-1l
0.e-1L
0.E-1l
0.E-1L

0x0
0x1
0xa
0xf
0xg
0xA
0xF
0xG
0x01
0x0a
0x0f
0x0g
0x0A
0x0F
0x0G

0x0z
0x1z
0xaz
0xfz
0xAz
0xFz
0x01z
0x0az
0x0fz
0x0Az
0x0Fz

0x0l
0x1l
0xal
0xfl
0xAl
0xFl
0x01l
0x0al
0x0fl
0x0Al
0x0Fl

0x0u
0x1u
0xau
0xfu
0xAu
0xFu
0x01u
0x0au
0x0fu
0x0Au
0x0Fu

0x0L
0x1L
0xaL
0xfL
0xAL
0xFL
0x01L
0x0aL
0x0fL
0x0AL
0x0FL

0x0U
0x1U
0xaU
0xfU
0xAU
0xFU
0x01U
0x0aU
0x0fU
0x0AU
0x0FU

0x0lu
0x1lu
0xalu
0xflu
0xAlu
0xFlu
0x01lu
0x0alu
0x0flu
0x0Alu
0x0Flu

0x0Lu
0x1Lu
0xaLu
0xfLu
0xALu
0xFLu
0x01Lu
0x0aLu
0x0fLu
0x0ALu
0x0FLu

0x0lU
0x1lU
0xalU
0xflU
0xAlU
0xFlU
0x01lU
0x0alU
0x0flU
0x0AlU
0x0FlU

0x0LU
0x1LU
0xaLU
0xfLU
0xALU
0xFLU
0x01LU
0x0aLU
0x0fLU
0x0ALU
0x0FLU

0x0ul
0x1ul
0xaul
0xful
0xAul
0xFul
0x01ul
0x0aul
0x0ful
0x0Aul
0x0Ful

0x0uL
0x1uL
0xauL
0xfuL
0xAuL
0xFuL
0x01uL
0x0auL
0x0fuL
0x0AuL
0x0FuL

0x0Ul
0x1Ul
0xaUl
0xfUl
0xAUl
0xFUl
0x01Ul
0x0aUl
0x0fUl
0x0AUl
0x0FUl

0x0UL
0x1UL
0xaUL
0xfUL
0xAUL
0xFUL
0x01UL
0x0aUL
0x0fUL
0x0AUL
0x0FUL

0x0llu
0x1llu
0xallu
0xfllu
0xAllu
0xFllu
0x01llu
0x0allu
0x0fllu
0x0Allu
0x0Fllu

0x0LLu
0x1LLu
0xaLLu
0xfLLu
0xALLu
0xFLLu
0x01LLu
0x0aLLu
0x0fLLu
0x0ALLu
0x0FLLu

0x0llU
0x1llU
0xallU
0xfllU
0xAllU
0xFllU
0x01llU
0x0allU
0x0fllU
0x0AllU
0x0FllU

0x0LLU
0x1LLU
0xaLLU
0xfLLU
0xALLU
0xFLLU
0x01LLU
0x0aLLU
0x0fLLU
0x0ALLU
0x0FLLU

0x0ull
0x1ull
0xaull
0xfull
0xAull
0xFull
0x01ull
0x0aull
0x0full
0x0Aull
0x0Full

0x0uLL
0x1uLL
0xauLL
0xfuLL
0xAuLL
0xFuLL
0x01uLL
0x0auLL
0x0fuLL
0x0AuLL
0x0FuLL

0x0Ull
0x1Ull
0xaUll
0xfUll
0xAUll
0xFUll
0x01Ull
0x0aUll
0x0fUll
0x0AUll
0x0FUll

0x0ULL
0x1ULL
0xaULL
0xfULL
0xAULL
0xFULL
0x01ULL
0x0aULL
0x0fULL
0x0AULL
0x0FULL

01
07
08
09
010
011
077
078
087

"foo"
"foo
foo"
"foo\
bar"
L"foo"
L"foo
Lfoo"
L"foo\
bar"
u"foo"
u"foo
ufoo"
u"foo\
bar"
u8"foo"
u8"foo
u8foo"
u8"foo\
bar"
U"foo"
U"foo
Ufoo"
U"foo\
bar"
R"(foo)"
R"bar(foo)bar"
R"foo(foo)foo"
LR"bar(foo)bar"
uR"bar(foo)bar"
u8R"bar(foo)bar"
UR"bar(foo)bar"
LR"foo(foo)foo"
uR"foo(foo)foo"
u8R"foo(foo)foo"
UR"foo(foo)foo"
R"bar(foo

\

)bar"
R"foo(foo

\

)foo"
R"bar(foo

"

)"

)b"

)ba"

)bar"

R"bar(foo

)bar

)bar

)bar

)bar"

#error ``` Foo bar is bad news bears! ```
#   define foo bar
#    define bar baz
#define baz bish

# error wishy washy
#define swish(x,y,...) switch(x){ y(__VA_ARGS__) }

#endif

#include "4coder_base_types.h"
#include "4coder_token.h"
#include "generated/lexer_cpp.h"

#include "4coder_base_types.cpp"
#include "4coder_token.cpp"
#include "generated/lexer_cpp.cpp"

#include "4coder_stringf.cpp"
#include "4coder_malloc_allocator.cpp"

#include <stdio.h>
#include <time.h>

internal void
print_token_list(Token_List *list, String_Const_u8 text){
  for (Token_Block *block = list->first;
       block != 0;
       block = block->next){
    i32 count = block->count;
    Token *token = block->tokens;
    for (i32 i = 0; i < count; i += 1, token += 1){
      printf("[%5llu, %5llu) %20s / %20s : 0x%04x / 0x%04x\n",
             token->pos, token->pos + token->size,
             token_base_kind_names[token->kind],
             token_cpp_kind_names[token->sub_kind],
             token->flags, token->sub_flags);
      printf("\t:%.*s:\n", (i32)token->size, text.str + token->pos);
    }
  }
}

internal String_Const_u8
file_read_all(Arena *arena, FILE *file){
  String_Const_u8 result = {};
  fseek(file, 0, SEEK_END);
  result.size = ftell(file);
  fseek(file, 0, SEEK_SET);
  result.str = push_array(arena, u8, result.size + 1);
  fread(result.str, result.size, 1, file);
  result.str[result.size] = 0;
  return(result);
}

int main(void){
  Arena arena_ = make_arena_malloc();
  Arena *arena = &arena_;

  String_Const_u8 path_to_self = string_u8_litexpr(__FILE__);
  path_to_self = string_remove_last_folder(path_to_self);
  String_Const_u8 path_to_src = string_remove_last_folder(path_to_self);

  String_Const_u8 test_file_name = push_u8_stringf(arena, "%S/languages/4coder_lexer_cpp_test.cpp", path_to_src);

  FILE *test_file = fopen((char*)test_file_name.str, "rb");
  if (test_file == 0){
    printf("error: count not open test file %s\n", test_file_name.str);
    exit(1);
  }
  String_Const_u8 text = file_read_all(arena, test_file);
  fclose(test_file);

  Token_List list = lex_full_input_cpp(arena, text);
  print_token_list(&list, text);

  for (i32 i = 0; i < KB(4); i += 1){
    fprintf(stdout, "\n");
  }
  fflush(stdout);

  return(0);
}

// BOTTOM
