# Build the parser
build/lemon source/grammar.lem
mv source/grammar.c source/grammar.cc
mv source/grammar.out build/parser.out
mv source/grammar.h source/tokens.hh

# Build the lexer
build/ragel -T1 -C source/lexer.rl -o build/lexer.cc

# Build the source
clang++ -Wall source/*.cc build/*.cc -o fur
