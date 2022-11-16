#!/bin/bash

# Compilamos los archivos como .o
gcc -c -g libreria.c
gcc -c -g test.c

# Compilamos un test ejecutable
gcc -o test test.o libreria.o

# Eliminamos los archivos .o
rm libreria.o
rm test.o

# Test cases
echo  -e '\nTesting head with test.txt\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test head 2

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test head 5

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test head 7

echo -e '\n'

echo -e 'Testing head with testtext.txt\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test head 2

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test head 5

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test head 7

echo -e '\n'

echo -e 'Testing tail with test.txt\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test tail 2

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test tail 5

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test tail 7

echo -e '\n'

echo -e 'Testing tail with testtext.txt\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test tail 2

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test tail 5

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test tail 7

echo -e '\n'

echo -e 'Testing longlines with test.txt\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test longlines 2

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test longlines 5

echo -e '\n'

echo 'abc
abcdefghijklmnopq
abcde
a
abcdefg
abcdefghi
ab
abcdefghijklmnopqrstuvwxyz
abcdefghijkl
abcd' | ./test longlines 7

echo -e '\n'

echo -e 'Testing longlines with testtext.txt\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test longlines 2

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test longlines 5

echo -e '\n'

echo 'Hola me llamo manolo
uwu
viva castillita :)
fuck caceres
bad gyal primera de espania
si
seniora pa cuando enseniarnos a programar c????
lorem ipsum dolor
platanos, huevos, leche, pan
me gusta python mas
castilla la mancha mejor que emos' | ./test longlines 7