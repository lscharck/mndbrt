# mndbrt
This repository is aimed at developing an abstract data type for the image. The
requirements for such an ADT are layout below. Additionally, an ADT for a
coloring function is being considered as well.

### TODO ###
#### Make the image array into an ADT ####
The image ADT functional requirements (shall statments):
1. The application (put_pixle) shall have no access to what an image array is
2. The application (put_pixle) shall add pixels with an "add" method; a polymorphic function
3. The application (genset) shall call "new" to create a new instance of the image class ie. an image object
4. The ADT shall represent the image class as a struct so more information can be added such as index no.
5. The ADT shall create only one image and maintain only one, however there should be multiple image objects
6. The ADT shall be able to handle multiple thread calls to "new" ie. the first call makes the image with "fio" subsequent calls forgo "fio"
7. The call to "fio" shall take place in the "constructor" and the "destructor" should undo "fio"
8. The call to "new" shall be variadic and should take the image dimensions

#### Make the color function into a ADT (theoretical) ####
