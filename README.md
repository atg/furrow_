# Furrow
### C++11, the Functional Parts

This is just a quick weekend experiment.

If you browse over to the [Wikipedia article on C++11](http://en.wikipedia.org/wiki/C%2B%2B11), you might be pleasently surprised to find new features such as [lambdas](http://en.wikipedia.org/wiki/C%2B%2B11#Lambda_functions_and_expressions), [type inference](http://en.wikipedia.org/wiki/C%2B%2B11#Type_inference), and [tuples](http://en.wikipedia.org/wiki/C%2B%2B11#Tuple_types) (along with highly batshit features like [user defined literals](http://en.wikipedia.org/wiki/C%2B%2B11#User-defined_literals)).

Furrow takes the features you know and love from functional languages such as Haskell, and implements them on top of C++11. Since the code that Furrow outputs is (mostly) standard C++, Furrow and C++ can be used together with no problems. Just import the header files and call the functions. There's no foreign interface to set up, no datatypes to convert between.

In essence Furrow is a Functional CoffeeScript for C++11. Or that's the plan.
