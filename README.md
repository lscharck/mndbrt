# mndbrt
Offical repository of the Mandelbrot project.

## Mandelbrot ##
M = {c ∈ ℂ | lim Z_n (n -> ∞) ≠ ∞}

- Z_o = 0 + 0i
- Z_(n+1) = (Z_n)^2 + c

## Coloring Schemes ##
1. Escape Algorithms
- Based on number of iterations until the point escapes the orbit
   - Black and White:
     - Uses only two colors
     - First color is for points inside the orbit
     - Second color is for points that escape the orbit 
   - Linear color function:
     - Uses a linear transformation to map iterations to a color 
     - Typically maps the single interation value into a rgb triplet
     - Usally an interpolating function is used to produce a linear gradient
     - Easy to understant and implement
     - Produces unfavorable wide "*bands*" when the iteration count changes slowly at low iteration values
     - Produces unfavorable rapid short "*bands*" when the iteration count changes rapidly at high iteration values
   - Polynomial color function:
     - Uses a polynomial to map iterations to a color.
     - Typically maps the single interation value into a rgb triplet
     - Usally an aproximating function is used to produce a changing color gradient
     - Easy to understant and implement
     - More variation in colors and more interesting
     - Produces unfavorable wide "*bands*" when the iteration count changes slowly at low iteration values
     - Produces unfavorable rapid short "*bands*" when the iteration count changes rapidly at high iteration values
   - Non linear color function:
     - Uses a non linear function to map iterations to a color.
     - Typically maps the single interation value into a rgb triplet
     - Usally an aproximating function of an exp form is used to produce a changing color gradient
     - Easy to understant and implement
     - More variation in colors and more interesting
     - Reduces unfavorable wide "*bands*" when the iteration count changes slowly at low iteration values
     - Reduces unfavorable rapid short "*bands*" when the iteration count changes rapidly at high iteration values
     - The nature of a exp function allows for smaller iterations to change more rapidly and larger iterations to change more slowly
   - Smooth escape function:
     - Uses a normalized iteration function
     - Smooths the iteration count
     - Reduces harsh "*banding*"
     - Much more complicated
    - Histogram:
      - Uses a histogram of iterations
      - Applies a linear color map to the histogram values from smallest iteration to largest iteration
      - smooth
      - Slow and annoying to implement
2. Distance Algorithm
- Based on the distance from neighboring points
  - Distance estimator algorithm:
    - Uses the derivative of the iteration function to produce the distance between dwell bands
    - Maps both the iteration and distance to a HB or HSB if the angle is calculated
    - More complicated
    - Much more visually pleasing
    - Utilizes hue saturation and brightness which *feels* more balanced
    - Better at displaying the filaments

## TODO ## 
- Make the image array into a ADT with the image ADT "should" statments
1. The application (put_pixle) should have no access to what an image array is
2. The application (put_pixle) adds pixles with an "add" method; a polymorphic function
3. The application (genset) will call "new" to create a new instace of the image class ie. an image object
4. The ADT should represent the image class as a struct so more information can be added such as index no.
5. The ADT should create only one image and maintain only one, however there should be multilple image objects
6. The ADT should be able to handle multiple thread calls to "new" ie. the first call makes the image with "fio" subsequent calls forgo "fio"
7. The call to "fio" should take place in the "constructor" and the "destructor" should undo "fio"
8. The call to "new" should be variatic and should take the image dimensions

- Make the color function into a ADT (theoretical)

