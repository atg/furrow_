# Build the parser
build/lemon source/parser.lem
mv source/parser.c build/parser.cc

# Build the lexer
build/ragel -T1 -C source/lexer.rl -o build/lexer.cc

# Build the source
clang++ -Wall source/*.cc build/*.cc -o fur
