# mndbrt
Repository for the Mandelbrot project.

## Mandelbrot ##
M = {c ∈ ℂ | lim Z_n (n -> ∞) ≠ ∞}

- Z_o = 0 + 0i
- Z_(n+1) = (Z_n)^2 + c

## Getting Started 
This project generates an image of the Mandelbrot set given the viewing coordinates and an image size. The program can be compiled by using cmake and make in the build directory. The program "mndbrt" can be supplied with the image coordinates from the command line. The output is a bitmap of the Mandelbrot set that can be opened and exported by most media software. A sample of what the program can produce is provided below.

<p align="center">
  <img src="https://github.com/lscharck/mndbrt/blob/main/seahorse.heic" width=50% height=50% />
</p>

## Coloring Schemes ##
Currently main uses the [distance algorithm](http://mrob.com/pub/muency/algorithms.html) adapted from the corresponding website and chromatic uses the classic escapce algorithms with a polynomail and a non-linear variant. A brief introduction to the various coloring schemes is presented below.
1. Classic Escape Algorithms
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
    - This algorithm borrowes ideas from this [website](http://mrob.com/pub/muency/algorithms.html)

### TODO ###
#### Make the image array into a ADT ####
The image ADT functional requirements (shall statments):
1. The application (put_pixle) shall have no access to what an image array is
2. The application (put_pixle) shall add pixles with an "add" method; a polymorphic function
3. The application (genset) shall call "new" to create a new instace of the image class ie. an image object
4. The ADT shall represent the image class as a struct so more information can be added such as index no.
5. The ADT shall create only one image and maintain only one, however there should be multilple image objects
6. The ADT shall be able to handle multiple thread calls to "new" ie. the first call makes the image with "fio" subsequent calls forgo "fio"
7. The call to "fio" shall take place in the "constructor" and the "destructor" should undo "fio"
8. The call to "new" shall be variatic and should take the image dimensions

#### Make the color function into a ADT (theoretical) ####
