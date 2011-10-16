# Build the parser
lemon source/parser.lem
mv source/parser.c build/parser.c

# Build the lexer
ragel -T1 -C source/lexer.rl -o build/lexer.c

# Build the source
clang -Wall source/*.c build/*.c -o fur
