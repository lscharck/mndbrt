# mndbrt
Offical repository of the Mandelbrot project.

## Mandelbrot ##
M = {c ∈ ℂ | lim Z_n (n -> ∞) ≠ ∞}

- Z_o = 0 + 0i
- Z_(n+1) = (Z_n)^2 + c

TODO: make the image array into a ADT with the following features - 
1. The application (put_pixle) has no clue what a image array is.
2. The application (put_pixle) adds pixles with an "add" method; a polymorphic function
3. The application (gen_set) will call "new" to create a new instace of the image class ie. an image object
4. The ADT should represent the image class as a struct so more information can be added such as index no.
5. The ADT should create only one image and maintain only one, however there should be multilple image objects
