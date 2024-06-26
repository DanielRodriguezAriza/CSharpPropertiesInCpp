# C# Properties in C++
A very simple showcase of a really wacky idea. What if we could define something similar to C# properties in C++?
That is the objective of this repository. To offer a simple proof of concept implementation for properties in C++ classes.

As of now, a Property<T> can only specify the setter function, but not a getter function, which means that the returned values will always be the exact same that is stored within the property.
