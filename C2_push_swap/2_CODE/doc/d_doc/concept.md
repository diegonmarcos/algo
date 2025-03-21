

# PUT PIXEL:
<details>

The formula: `(Y * WINX * 4) + (X * 4)`, is used to convert 2D coordinates `(X, Y)` into a 1D memory offset in the image buffer. Let me break down exactly how it works:

## The Formula Explained
Where:
- `Y` is the vertical coordinate (row)
- `X` is the horizontal coordinate (column)
- `WINX` is the width of the window/image in pixels
- `4` represents the number of bytes per pixel

## How Memory is Organized
In a graphics buffer, even though we think of pixels in a 2D grid, the actual memory is organized as a single, continuous array of bytes:

Each pixel typically requires 4 bytes (32 bits) to store:
- 1 byte for Red component
- 1 byte for Green component
- 1 byte for Blue component
- 1 byte for Alpha (transparency)

## Breaking Down the Calculation
- `Y * WINX` gives us the number of pixels from the top of the image to the start of row `Y`
- `Y * WINX * 4` converts this to bytes (since each pixel is 4 bytes)
- `X * 4` gives us the byte offset from the start of the row to the specific pixel's `X` position
- Adding these together: `(Y * WINX * 4) + (X * 4)` gives us the exact byte offset where the pixel data should be stored

## Example
Let's say:
- `WINX = 800` (image is 800 pixels wide)
- We want to access the pixel at coordinates `(10, 5)`

The calculation would be:
```markdown
Offset = (5 * 800 * 4) + (10 * 4)
	= 16000 + 40
	= 16040
```
So the pixel data starts at byte `16,040` in the buffer.

</details>
<br><br><br><br><br><br>


# TRANFORMATION AND RENDERING PIPELINES:
<details>

## 3D TO 2D TRANSFORMATION

PROJECTION TRANSFORMATIONS:
- Orthogonal Projection
Projects 3D points onto a 2D plane using orthographic projection. This transformation preserves parallel lines and relative sizes regardless of distance, making it ideal for technical visualizations.

- Characteristics:
	- Objects maintain the same size regardless of distance
	- Parallel lines remain parallel in the projection
	- No foreshortening effect
	- Preserves measurements and proportions
	- Less realistic but more precise for technical applications

- Perspective Projection
Perspective projection mimics how human eyes and cameras see the world. Objects appear smaller as they get farther away, and parallel lines converge at vanishing points, creating a realistic sense of depth and distance.

- Characteristics:
	- Objects appear smaller as they get farther away
	- Parallel lines converge at vanishing points
	- Creates realistic depth perception
	- The perspective effect is controlled by field of view (FOV)
	- More realistic and immersive visual experience

VIEWING TRANSFORMATIONS
- Rotatations(x, y, z)
Applies 3D rotation matrices to rotate all points around the X, Y, and Z axes. This allows viewing the terrain from different angles by applying standard 3D rotation transformations.

- Scale
Multiplies all coordinates by a scale factor to resize the projection. This allows zooming in and out of the visualized terrain.

- Traslate
Moves the entire projection by adding offset values to each point. This centers the visualization in the display window or allows panning across the terrain.

- z_division
This transformation adjusts the height scale of the terrain by dividing all Z-coordinates by a constant factor. This allows controlling how pronounced the elevation features appear in the visualization.



FROM CARTESIAN TO POLAR COORDINATES TRANSFORMATIONS
- Spherize
Transforms a flat terrain map into a spherical or globe-like shape. It calculates the distance of each point from the center, then converts planar XYZ coordinates to spherical coordinates. Points closer to the center "rise up" while points farther away "curve down," creating a rounded surface

- Bending
Applies additional curvature to the terrain based on a specified range parameter. This creates wave-like deformations or controlled bending of the surface in specified directions.



- Shadow
Computes lighting effects based on surface normals and a simulated light direction. This enhances the 3D perception by adding shading that emphasizes the terrain's topography.

## RENDERING
### Wireframe 2 lines per point
The standard grid-based wireframe rendering approach that draws two lines from each point: one horizontally to the next point in the same row, and one vertically to the point below in the grid. This creates a regular grid pattern that efficiently represents terrain surfaces.

Advantages:
- Computationally efficient (fewer lines to draw)
- Clean, uncluttered visualization
- Sufficient for most terrain visualization needs

``` sh
A---B---C
|   |   |
D---E---F
|   |   |
G---H---I

    B      
   / \     
  /   \    
 A     C   
/|    /|   
D-+---F |  
| |   | |  
| G---+-I  
|/    |/   
H------    

    B      
   / \     
  /   \    
 A-----C   
 |\   /|   
 | \ / |   
 |  E  |   
 | / \ |   
 |/   \|   
 D-----F   
 |\   /|   
 | \ / |   
 |  H  |   
 | / \ |   
 |/   \|   
 G-----I   

 ```

### Wireframe 3 lines per point
An enhanced wireframe rendering approach that adds diagonal lines to create triangular faces. This approach draws three lines from each point: one horizontally, one vertically, and one diagonally to the point below and to the right.

Advantages:
- Creates triangular faces for better surface representation
- Enhances visual perception of terrain features
- Provides more complete representation of the underlying geometry
- Better visual result after 3D transformations like rotation

Disadvantages:
- Increased computational cost (50% more lines to draw)
- Can create visual clutter in complex terrains
- May obscure some features due to line density

</details>
<br><br><br><br><br><br>




# A) GRAPHICS RENDER ALGOS, FRAMEWORKS AND APIs: 
> From Vector-Based Wireframing to Polygon Filled to Textures|Light|Camera Controls

> from Ortoghonal Projection to a Perspective Projection

## Rendering Algorithms
<details>

### Ray Tracing
- Simulates light rays as they interact with objects
- Creates highly realistic images with accurate shadows, reflections, and refractions
- Computationally expensive but produces photorealistic results
- Used in offline rendering and increasingly in real-time with hardware acceleration

### Rasterization
- Converts 3D geometry into 2D pixels (fragments)
- Much faster than ray tracing but less physically accurate
- The primary method for real-time rendering in games and interactive applications
- Requires techniques like shadow mapping and screen space reflections to simulate effects

<details>
Subtypes and techniques within the Rasterization rendering category:

### Rasterization Subtypes and Techniques

#### Vector-Based Wireframe Algorithm
- Represents 3D objects using only their edges (vectors/lines)
- Focuses on geometric structure rather than solid surfaces
- Efficiently displays objects with minimal computational resources
- Often used as a visualization mode in CAD software, modeling applications, and during the development process

#### Polygon/Triangle Rasterization
- Converts polygons (usually triangles) into pixels
- The foundation of most real-time 3D graphics
- Uses scan-line or half-space algorithms to determine which pixels a polygon covers

#### Texture Mapping
- Applies 2D images onto 3D geometry
- Includes various filtering methods (bilinear, trilinear, anisotropic)
- UV mapping determines how textures wrap around objects

#### Z-Buffer (Depth Buffer) Rendering
- Uses a depth buffer to determine which objects are visible at each pixel
- Solves the hidden surface problem efficiently
- Standard in almost all real-time graphics pipelines

#### Deferred Rendering
- Splits rendering into multiple passes (geometry, lighting, composition)
- Allows for many light sources with better performance
- Stores intermediate results in G-buffers (geometry buffers)

#### Forward Rendering
- Traditional approach where lighting is computed during polygon rendering
- More direct but less efficient for many light sources
- Still used for transparent objects and some specific cases

#### Tile-Based Rendering
- Divides screen into tiles and processes them separately
- Improves cache coherence and memory bandwidth usage
- Common in mobile GPUs and some console architectures

#### Order-Independent Transparency
- Techniques to correctly render transparent objects without pre-sorting
- Examples include depth peeling and weighted-blended OIT
- Addresses a challenging problem in rasterization pipelines

#### Screen Space Effects
- Techniques that operate on the already rasterized image
- Includes SSAO (Screen Space Ambient Occlusion), SSR (Screen Space Reflections)
- Approximates complex lighting effects without ray tracing

#### Voxel-Based Rendering
- Uses 3D grid cells (voxels) instead of polygons
- Can be rasterized using specialized algorithms
- Used for volumetric data and some specialized rendering engines

#### Point-Based Rendering
- Represents surfaces with points instead of polygons
- Includes techniques like splatting to create continuous surfaces
- Useful for very complex geometry like particle systems

#### Cel/Toon Shading
- Non-photorealistic rendering technique with discrete shading bands
- Creates cartoon-like or illustrated appearance
- Uses edge detection and color quantization

Each of these techniques can be combined in various ways within a rasterization pipeline to achieve different visual results and performance characteristics depending on the application's requirements.
</details>

### Path Tracing
- An unbiased rendering technique that extends ray tracing
- Simulates light paths more completely for greater realism
- Used extensively in film production and architectural visualization
- Slow for real-time applications but produces very high quality results

### Radiosity
- Calculates diffuse light transfer between surfaces
- Good for architectural visualization and environments with indirect lighting
- Often combined with ray tracing for complete global illumination
</details>

## Graphics Frameworks and APIs
<details>

### Low-level APIs
- DirectX (Windows platforms)
- Vulkan (cross-platform)
- Metal (Apple platforms)
- OpenGL (cross-platform, older)
- WebGL (browser-based)

### Game Engines
- Unreal Engine
- Unity
- Godot
- CryEngine

### Production Rendering Systems
- Arnold
- RenderMan
- V-Ray
- Redshift
- Octane Render

### Scientific Visualization
- OpenGL Visualization Toolkit
- ParaView
- POV-Ray

</details>
<br><br><br><br><br><br>

## Vector-Based Wireframe vs. Polyg Rasterization
<details><summary>Expand for details</summary>

### Vector-Based Wireframe Rendering
Vector-based wireframe rendering focuses on displaying the edges (lines) that define the structure of a 3D model.

Characteristics:
Only renders the edges/outlines of objects
Computationally efficient - only processes vertices and edges
Creates a skeletal representation that shows structure clearly
Doesn't require textures or complex shading
Useful for technical visualizations, debugging, and design
Implementation:

### Polygon Rasterization
Polygon rasterization fills in the surfaces defined by the vertices, creating solid objects.

Characteristics:
Renders filled surfaces rather than just outlines
Computationally more intensive - processes every pixel within polygons
Creates a more realistic visual representation
Supports textures, lighting, and shading
Essential for creating visually rich 3D environments
</details>

## Perspective vs. Orthographic Projection
<details>

> Perspective and orthographic projections are two fundamentally different ways of projecting 3D objects onto a 2D surface (like your screen). They are not the same thing, and they create distinctly different visual results.

### Perspective Projection
Perspective projection mimics how human eyes and cameras see the world:
- Objects appear smaller as they get farther away
- Parallel lines converge at vanishing points
- Creates a sense of depth and distance
- Closer objects appear larger than distant objects of the same size
- In the transformation matrix, perspective projection includes a division by distance (the "perspective divide"), which creates the effect of size diminishing with distance.

#### Use Perspective When:

- Aiming for realistic visual representation
- Creating immersive 3D environments
- Simulating what a camera would see
- Wanting to emphasize depth and distance in a scene

### Orthographic Projection
Orthographic (or orthogonal) projection shows objects with their true relative sizes, regardless of distance:

Objects remain the same size regardless of distance
Parallel lines remain parallel (no convergence)
No sense of depth from perspective
Often used in engineering, architecture, and 2D games
Sometimes called "isometric" in game contexts (though true isometric is a specific type of orthographic)
In the transformation matrix, orthographic projection has no division by distance - it's a simple linear mapping.

#### Common Variations:
- Cabinet Projection: 3/4 view where depth is shown at 45° but half-scaled
- Isometric Projection: Equal foreshortening of all three axes (30° angles)
- Dimetric Projection: Two axes have equal foreshortening, third is different
- Military Projection: Top-down view with full-scale depth at 45°

> The key difference is that orthographic projection simply scales the coordinates, while perspective projection divides by the Z coordinate (depth) to create the illusion of depth.

Use Orthographic When:
- You need to preserve measurements and proportions
- Working with technical drawings or diagrams
- Creating isometric games or UI elements
- Showing multiple views of an object simultaneously


</details>
<br><br><br><br><br><br>


# THE CHOSEN METHOD
## Rasterization Category with Orthogonal Projection
### Vector-Based Wireframe Algorithm
- Represents 3D objects using only their edges (vectors/lines)
- Focuses on geometric structure rather than solid surfaces
- Efficiently displays objects with minimal computational resources
- Often used as a visualization mode in CAD software, modeling applications, and during the development process

Vector-based wireframe rendering is characterized by:

1. **Geometric Representation**: Objects are defined by their vertices and the connecting edges, ignoring faces and solid volumes
   
2. **Line Drawing Algorithms**: Uses algorithms like Bresenham's line algorithm or DDA (Digital Differential Analyzer) to efficiently draw straight lines between vertices

3. **Culling and Clipping**: Determines which lines are visible and which fall outside the viewport

4. **Projection**: Applies perspective or orthographic projection to convert 3D coordinates to 2D screen space

5. **Hidden Line Removal**: More advanced wireframe renderers may implement algorithms to hide edges that would be occluded by faces in a solid model

Wireframe rendering is particularly important in:
- Computer-Aided Design (CAD) software
- 3D modeling applications
- Engineering visualization
- Early stages of game and application development
- Limited computing environments where full rendering is too resource-intensive

It's worth noting that wireframe rendering represents an earlier, more fundamental approach to computer graphics that predates more sophisticated techniques like filled polygon rendering, texture mapping, and lighting models. However, it remains useful as both a visualization option and as an initial step in more complex rendering pipelines.
Scanning and rasterization are related concepts in computer graphics but aren't exactly the same thing:

<br><br><br>

**Rasterization** is the broader process of converting vector graphics (shapes defined by mathematical descriptions) into raster graphics (a grid of pixels). This complete process typically involves:

1. Processing geometric primitives (like triangles)
2. Determining which pixels these primitives cover
3. Calculating the color and other properties for each affected pixel
4. Writing these values to a frame buffer

**Scan conversion** (often just called "scanning") is specifically the part of rasterization that determines which pixels are covered by a primitive. It's a subset of the rasterization process.

Common scan conversion techniques include:
- Scan-line algorithms: Process primitives one horizontal line of pixels at a time
- Edge-walking algorithms: Follow the edges of primitives to determine their boundaries
- Half-space functions: Test whether points lie inside or outside a triangle
<br><br><br><br><br><br>







# B) GRAPHIC LIBRARIES IN UNIX
<details>

## Wayland
- Modern replacement for X11 in many Linux distributions
- More secure and efficient design
- Direct rendering model rather than X11's client-server architecture
- Would require using the Wayland client libraries

## SDL (Simple DirectMedia Layer)
- Cross-platform development library designed for games and multimedia
- Abstracts graphics, input, and audio across multiple platforms
- Would provide better performance and more features than X11
- Already designed to be simple and accessible for beginners

## GTK or Qt
- Complete UI toolkit libraries that handle graphics and window management
- Would provide more sophisticated widget and windowing capabilities
- Include their own rendering engines
- Might be considered too complex for educational purposes

## Direct Framebuffer
- Low-level access to the framebuffer device on Linux
- Bypasses window managers entirely
- Very simple but limited in features
- No window management or composition

## OpenGL/EGL
- Hardware-accelerated graphics API
- Could be used without X11 using EGL for context creation
- Would provide much better performance for 3D applications
- Higher learning curve but more transferable skills

## Vulkan
- Modern, low-level graphics and compute API
- Maximum performance and control
- Significantly more complex than X11
- Would be overkill for the educational purposes of MiniLibX

## X11 (X Window System)
X11 is the standard windowing system used on Linux and Unix-like operating systems. Originally developed at MIT, it provides the basic framework for building graphical user interfaces.

Key characteristics of X11:
- Uses a client-server architecture where the X server manages display hardware, input devices, and screen drawing
- Client applications communicate with the X server to request graphical operations
- Provides low-level primitives for drawing shapes, managing windows, and handling input
- Designed with network transparency in mind (clients can run on different machines)
- Has a complex API with many functions and data structures
- Includes the Xlib library, which is the traditional C-language binding to X11
</details>
<br><br><br><br><br><br>






# THE CHOSEN GRAPHIC LIBRARY IN UNIX
The choice is MiniLibX that is on top of X11:
1. It was ubiquitous on Linux systems when MiniLibX was created
2. It provides a reasonable balance of simplicity and capability
3. It doesn't require additional dependencies beyond what's standard on Linux
4. The educational focus was on basic graphics algorithms rather than leveraging advanced graphics APIs

SDL would probably have been the most suitable alternative, as it's designed to be relatively simple while providing better performance and cross-platform support than direct X11 programming.
## X11 (X Window System)
X11 is the standard windowing system used on Linux and Unix-like operating systems. Originally developed at MIT, it provides the basic framework for building graphical user interfaces.

Key characteristics of X11:
- Uses a client-server architecture where the X server manages display hardware, input devices, and screen drawing
- Client applications communicate with the X server to request graphical operations
- Provides low-level primitives for drawing shapes, managing windows, and handling input
- Designed with network transparency in mind (clients can run on different machines)
- Has a complex API with many functions and data structures
- Includes the Xlib library, which is the traditional C-language binding to X11

## MiniLibX (42 School)
MiniLibX is a simplified graphics library created specifically for students at 42 School. It serves as an abstraction layer over more complex systems like X11 or macOS's Cocoa.

Key characteristics of MiniLibX:
- Minimalist API with just a handful of functions
- Designed for educational purposes rather than production use
- Provides basic functions for creating windows, drawing pixels, and handling events
- Abstracts away many of the complexities of the underlying graphics systems
- Platform independent (works on both Linux with X11 and macOS)
- Focused on pixel manipulation rather than high-level graphics primitives
<details>

### a) MiniLibX's Graphic Rendering Approach

MiniLibX uses a relatively straightforward approach to graphics rendering, implementing a basic software rendering pipeline rather than leveraging hardware acceleration. Here's how it handles the rendering process:

#### Core Rendering Mechanism

1. **Image Buffers**
   - MiniLibX creates in-memory image buffers using `mlx_new_image()`
   - These buffers are essentially arrays of pixels stored in the application's memory
   - Each pixel is typically represented as an integer with RGBA or BGRA color information

2. **Direct Pixel Manipulation**
   - The core of MiniLibX rendering is direct pixel manipulation
   - Functions like `mlx_get_data_addr()` provide access to the raw memory of the image buffer
   - Developers write directly to this memory to set individual pixels

3. **Software Rasterization**
   - Any line drawing, shape filling, or other geometric operations must be implemented by the programmer
   - MiniLibX doesn't provide built-in primitives for triangles, circles, etc.
   - All rasterization (converting shapes to pixels) happens in software code written by the user

4. **Memory-to-Screen Transfer**
   - After manipulating the image buffer, `mlx_put_image_to_window()` transfers the entire buffer to the window
   - This operation is essentially a memory copy from the application's buffer to the X server's buffer
   - It's a relatively expensive operation, so efficient applications minimize these transfers

#### Example Rendering Flow

A typical rendering loop in MiniLibX might look like:

1. Create an image buffer with `mlx_new_image()`
2. Get the memory address with `mlx_get_data_addr()`
3. Perform calculations to determine what to draw
4. Write pixel data directly to the memory buffer
5. Call `mlx_put_image_to_window()` to display the result
6. Repeat steps 3-5 for animation

### b) Performance Considerations

MiniLibX's rendering approach is:
- Simple to understand and implement
- Independent of graphics hardware capabilities
- Relatively slow compared to hardware-accelerated approaches
- Suitable for educational projects but not high-performance applications

This software-based rendering approach is fundamentally different from modern graphics libraries like OpenGL or Vulkan, which leverage GPU hardware acceleration and provide sophisticated rasterization pipelines.

### c) How MiniLibX Interacts with X11 (on Linux)
On Linux systems, MiniLibX essentially acts as a thin wrapper around X11's Xlib, simplifying its interface:

1. **Window Creation**: MiniLibX's `mlx_init()` and `mlx_new_window()` functions use Xlib's `XOpenDisplay()`, `XCreateSimpleWindow()`, and related functions to establish a connection to the X server and create a window.

2. **Pixel Drawing**: MiniLibX creates an XImage in memory using `XCreateImage()`. When you call `mlx_pixel_put()` or work with MiniLibX images, you're modifying this in-memory buffer rather than drawing directly to the screen.

3. **Image Display**: MiniLibX's `mlx_put_image_to_window()` uses X11's `XPutImage()` to transfer the memory buffer to the visible window.

4. **Event Handling**: MiniLibX provides simplified event hooks like `mlx_key_hook()` and `mlx_loop()` that internally use X11's event system and `XNextEvent()`.

5. **Color Management**: MiniLibX handles the translation between simple RGB values that students provide and the color representations needed by X11.


### d) Abstractions in minilibx
The primary benefit of MiniLibX is that it reduces the learning curve by providing a much smaller API surface while still giving students access to fundamental graphics programming concepts. However, this simplification comes at the cost of performance and flexibility compared to working directly with X11 or modern alternatives like Vulkan or OpenGL.
MiniLibX doesn't implement its own complete graphics rendering system. Instead, it:

Uses X11/Xlib for:

- Window creation and management
- Transferring images to the screen
- Event handling (keyboard/mouse input)
- Color management
- The actual display functionality


Provides a simplified memory buffer management system for:

- Creating and manipulating in-memory image buffers
- Basic pixel manipulation

</details>
<br><br><br><br><br><br>



## Cartesian vs. Polar Coordinates in FDF

Converting maps coordinates from Cartesian to polar coordinates provides several advantages for certain visualization and manipulation needs.

<details>

### Cartesian Coordinates
Points represented as (x, y, z)
Based on perpendicular axes
Good for representing grid-based data
Simple to understand and manipulate for linear transformations

### Polar Coordinates
Points represented as (r, θ, z) where:
r = distance from origin
θ = angle in the x-y plane
z = height (unchanged from Cartesian)
Based on distance from a central point and angles
Better for radial operations and circular patterns
Benefits of Polar Coordinates in FDF
Rotation Simplification:

### Diferences
Radial Operations:
- In polar coordinates, rotating around the z-axis is just adding a value to θ
Much simpler than the matrix multiplication required in Cartesian coordinates
- Operations like scaling from the center become trivial (just multiply r)
- Creating circular or spiral patterns becomes more intuitive

Distance Calculation:
- The distance from the center is immediately available as the r value
Useful for effects that depend on distance from a focal point

Visual Effects: 
- Simplifies creating radial gradients or color transitions
Makes it easier to implement wave-like deformations

</details>
<br><br><br><br><br><br>

# C) THE PROJECT
## (i) Code Organization for a Graphic Project

This fdf project demonstrates an example of structured code organization for a graphics project. Here's the breakdown of how it's organized:

1. **Modular Architecture**:
   - Files are organized with a clear numbering system (1___, 3___, etc.) that indicates module relationships
   - Each file has a specific role in the rendering pipeline
   - Functions are grouped by their purpose (loading, drawing, parsing)

2. **Data Structures**:
   - The project uses a central `t_meta` structure that contains all necessary information
   - `t_map` structure to store the map data
   - `t_point` structure to store individual points with their coordinates and color

3. **Processing Pipeline**:
   - **Map Loading**: Files starting with `1___` handle reading the input file and parsing it
   - **Map Parsing**: Files starting with `3_2__` handle transformations of the points
   - **Map Drawing**: Files starting with `3_3__` handle the actual rendering

4. **Separation of Concerns**:
   - Initialization logic is separated (`system_init`, `map_ini`)
   - Transformation logic is separated (matrix operations in separate files)
   - Rendering logic is separated (background, lines, points)
   - Memory management is handled consistently

This organization follows good software engineering principles, making the code maintainable and extensible. The pipeline structure (load → transform → render) is particularly suitable for graphics projects as it follows the natural flow of data processing.

## (ii) Manipulating MiniLibX
In the case of line drawing in the MiniLibX and X11 ecosystem, the implementation varies depending on where the line drawing occurs:

### Line Drawing 
#### in X11
X11's Xlib provides the `XDrawLine()` function which uses the Bresenham line algorithm internally for drawing lines. This is a highly efficient integer-based algorithm for rasterizing lines that:
- Uses only integer addition, subtraction, and bit shifting
- Avoids floating-point calculations
- Determines which pixels should be illuminated to form a close approximation to a straight line

#### Line Drawing in MiniLibX
MiniLibX itself doesn't provide a built-in line drawing function in its core API. This is why students using MiniLibX typically need to implement their own line drawing algorithm. The most common approaches implemented by students are:

1. **Bresenham's Line Algorithm**
   - Same algorithm used by X11 internally
   - Efficient and uses only integer arithmetic
   - Commonly taught in graphics programming courses

2. **DDA (Digital Differential Analyzer)**
   - Uses floating-point calculations
   - Conceptually simpler than Bresenham's algorithm
   - Less efficient but easier to understand for beginners

3. **Wu's Line Algorithm**
   - An anti-aliased line drawing algorithm
   - More complex but produces smoother lines
   - Less commonly implemented in student projects

To draw lines, one of these algorithms will draw into the image buffer before displaying it with `mlx_put_image_to_window()`.

### Usage
The project shows several ways of interacting with the miniLibX library:

1. **Window and Image Management**:
   - Creating a window with `mlx_new_window` (implied in `system_init`)
   - Creating an image buffer with `mlx_new_image` (implied in `system_init`)
   - Pushing the image to the window with `mlx_put_image_to_window`
   
2. **Pixel Manipulation**:
   - Direct memory access to the image buffer (`meta->bitmap.buffer`)
   - Color handling with `mlx_get_color_value` for different bit depths
   - Setting pixel colors with the `set_color` function
   
3. **Event Handling**:
   - Setting up key hooks via `system_init_keys`
   - Likely uses `mlx_hook` and `mlx_key_hook` to capture user input
   
4. **Performance Optimization**:
   - Using an in-memory buffer to render the entire scene before displaying it
   - Measuring rendering performance with `clock()`
   - Double-buffering technique (preparing the image before showing it)

The project uses a clever approach of rendering to an off-screen buffer first, then displaying the completed image, which reduces flickering and improves performance - a common technique in graphics programming.

## (iii) Math Concepts in Vector-Based Wireframe Algorithm

This is where the project really shines, implementing several key mathematical concepts:

1. **Matrix Transformations**:
   - 3D rotation matrices for X, Y, and Z axes (`rotate_x`, `rotate_y`, `rotate_z` in `3_2_2_parse_matrix.c`)
   - Matrix multiplication for applying transformations (`matrix3_multp`)
   - Orthographic projection to convert 3D to 2D (`ortogonal_projection`)

2. **Coordinate Systems**:
   - Cartesian coordinates (X, Y, Z axes)
   - Spherical/polar coordinates (`go_polar` function, using latitude and longitude)
   - Conversion between coordinate systems

3. **Scan Conversion Algorithm**:
   - The project have both uses Bresenham's line algorithm or Digital Differential Analyzer (DDA) for line drawing
   - This was implemented in the `wired` function (referenced in `drawing`)

4. **Additional Mathematical Operations**:
   - Scaling of points to fit the display (`scale` function)
   - Translation of points to position them correctly (`traslate` function)
   - Z-divisor to control the height effect (`z_division` function)
   - Bending for curvature effects (`bending` function)
   - Color gradients based on height (`gradient` function)

5. **Spherical Projection**:
   - Conversion from Cartesian to spherical coordinates in `go_polar`
   - Allows for globe-like rendering with `spherize` function

The scan method in this project's wireframe algorithm appears to be implemented through the combination of the orthogonal projection and then drawing lines between adjacent points in the transformed coordinate space. The mathematical pipeline goes:

1. Load points from file (original Cartesian coordinates)
2. Apply z-scaling and other adjustments
3. Apply rotations through matrix multiplication
4. Project to 2D using orthographic projection
5. Scale and translate to position in the window
6. Connect points with lines to form the wireframe

The project combine the concepts of: 
	- linear algebra, 
	- coordinate geometry, and 
	- computer graphics principles, 
	- combined into a cohesive rendering pipeline.

This type of wireframe rendering is foundational to more complex graphics algorithms and provides an excellent learning platform for understanding how 3D rendering works at a mathematical level.
