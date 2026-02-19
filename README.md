*This project has been created as part of the 42 curriculum by maxcote*

# fdf - README - maxcote

## DESCRIPTION

The fdf project (Fil de Fer, or wireframe) is a **basic computer graphics project** designed to introduce students to the **fundamentals of graphics programming**.

FDF focuses on representing a **3D landscape as a wireframe model**, using points (x, y, z) connected by lines to visualize the structure of the terrain. The program must display the model in **isometric projection**.

By the end of the project, participants will have built a functional 3D wireframe viewer capable of rendering landscapes from .fdf files and interacting with graphical windows in a robust and smooth manner.

The project assumes that the input maps are correctly formatted, since the goal is not to parse them, as the subject clearly states: *"Keep in mind that the goal of this project is not to parse maps! However, this doesn’t mean that your program should crash when run. It means that we assume the map contained in the file is properly formatted."*

## INSTRUCTIONS

### HOW TO RUN THE PROJECT

To run the FDF project, follow these steps:

1. **Set up MiniLibX**

Download minilibx-linux.tgz.
Extract it and place the minilibx folder inside your project directory.

2. **(Optional) Prepare example maps**

Download example .fdf files from the intranet. Place them in your project directory alongside your executable.

3. **Compile the project**

Open a terminal in the project directory and run: 
```
make
```

4. **Run the program**

Execute the program with a map file as argument:

```
./fdf <map_file>.fdf
```

For example, to run the example map 42.fdf:
```
./fdf 42.fdf
```

This will open a window displaying the wireframe representation of the landscape in isometric projection.

5. **Close the window**

Press ESC or click the window's close button to exit the program cleanly.

6. **With the bonus**

On the terminal, run: 

```
make bonus
```
Then, execute the program with a map file as argument:

```
./fdf_bonus <map_file>.fdf
```


### HOW THE PROJECT WAS MADE

To conform to the 42 Norm and to facilitate calculations, I used several structures, most of them tied to a t_app structure.

#### **PARSING**

However the goal of the project was not to parse maps, parsing was still an important part. From the maps, we needed to calculate the width and height, as well as the altitude value of each (x, y) point.

To do this, I used the get_next_line function twice in a row:

The first pass calculates the width and height, allowing us to correctly malloc a map structure to store the wireframe.

The second pass fills the map with the altitude values.

#### **TRACE THE WIREFRAME**

I display the wireframe in **isometric projection**, which gives a pseudo-3D view by showing all three axes (X, Y, Z) at equal angles. I calculate the isometric coordinates of each point using a 30-degree angle to achieve the correct perspective, taking into account the screen scale I chose to ensure the wireframe fits properly within the window. 

I render the wireframe by connecting the points of the map using **Bresenham’s line algorithm**. This algorithm allows me to **efficiently draw straight lines between two points (x, y)**, handling slopes and pixel selection. It produces smooth and accurate lines for the wireframe. 

I also update the color along the line for smooth gradients. To create a color gradient, I make the red, green, and blue components evolve between two points depending on the number of pixels in the line segment, which produces a smooth gradient effect along the wireframe.

To draw each pixel, I wrote a helper function *add_pixel* that directly modifies the image buffer (img->addr).

By doing this, I can render the entire wireframe landscape efficiently, while leveraging MiniLibX for window and image management.

#### **MANAGING EVENTS**

I handle user interactions and window events to ensure the program exits cleanly and manages resources properly.

I set up event hooks using MiniLibX. The setup_hooks function links key presses and window events to my handler functions. For example, pressing ESC or clicking the window’s close button triggers cleanup: I destroy the image, the window, and the display, free the allocated memory for the map and the MiniLibX context, and then exit the program.

This ensures that my application never leaks memory and always closes safely when the user wants to quit.

#### **DISPLAY THE WINDOW**

After I finish tracing the wireframe and preparing the image, I simply display it in the MiniLibX window. At this stage, all the points and lines have been rendered, so showing the image in the window allows the user to see the complete wireframe landscape.

#### **BONUS**

I wanted to push my introduction to graphics a bit further with the bonus features and also make it easier to quickly adjust and optimize the map display according to the screen scale.

I added controls to zoom in and out of the wireframe, and to move the view horizontally and vertically. This allows me to explore different parts of the landscape and adjust the display dynamically without modifying the map itself. By scaling and translating the view, I can better visualize large maps and ensure the wireframe fits nicely within the window.

- T – zoom in (increase the scale)
- W – zoom out (decrease the scale)

Arrow keys – move the view:
- Left / Right – shift the map horizontally
- Up / Down – shift the map vertically

## RESOURCES

During this project I had to do some research to better understand several key concepts:

- MiniLibX – to understand how to create windows, render images, and handle user input

- Bresenham’s line algorithm – to achieve the smoothest possible rendering of the wireframe

- Mathematics – revisiting concepts like isometric projection to correctly calculate point coordinates on the screen

I also benefited a lot from peer support, collaborating with classmates working on FDF, especially when optimizing the program for performance.

Additionally, AI tools were helpful to verify mathematical calculations, access knowledge more quickly and efficiently and improve the clarity and fluency of my README in English.

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

https://gontjarow.github.io/MiniLibX/?source=post_page-----7184cca317fc---------------------------------------

https://elearning.intra.42.fr/notions/fdf/subnotions

https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx

https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events

https://fr.wikipedia.org/wiki/Perspective_isom%C3%A9trique

https://www.youtube.com/watch?v=Frl1cLwfs1U

http://fredericgoset.ovh/mathematiques/courbes/fr/bresenham_line.html


