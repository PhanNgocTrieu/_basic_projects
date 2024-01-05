# List commands of conan project
* [profile]: conan profile detect (--force) <br>
    This command would show the profile of operation system

* [install]: conan install . --output-folder=<folder_output> --build=missing [--settings=build_type=Debug]<br> 
    <!-- To build project with cmake and setting build-type to debug  -->
    This command would install conan independent package in folder <folder_ouput> and "--build=missing" would make directory when missing <folder_output>

* [Build]: Follow the instructions <br>
    - cd build <br> 
    - cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release <br>
    - cmake --build .

* [SMFL]: Install package
    [Dependencies]: libxkbfile-dev libxmuu-dev libxres-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-dri3-dev libxcb-cursor-dev
    
    sudo apt-get install libx11-dev libx11-xcb-dev libfontenc-dev libice-dev libsm-dev libxau-dev libxaw7-dev libxcb-util-dev

[Assignment]:
    ---------------------------------------------------------------------------------------------------
    COMP 4300 - Assignment 1
    ---------------------------------------------------------------------------------------------------
    Assignemtn Note:
    ---------------------------------------------------------------------------------------------------

    Note: You will be required to submit main.cpp and NO OTHER FILES for this assigment. Submission will take place on D2L's Assignment 1 Dropbox.
    Only ONE student from each group of two should submit the assignment.

    Working solutions are included with the assigment so that you can see what a correct solution look like. These executables are located in the 'bin'
    directory, and are provided for the lab Linux / Windows.

    VERY IMPORTANT:
        You muse include the following information in a comment at the top of main.cpp
        - Both students's full names, cs usernames, and student numbers
        - If you did not get a specific feature to work (such as text center) please explain what you tried to do to get it to work, and partial marks may be given for effort

    ---------------------------------------------------------------------------------------------------
    Program Specification
    ---------------------------------------------------------------------------------------------------
    In this assignment you will be writing a C++/SFML program which will read descriptions of shapes from a configuration file, and then drawing those shapes to the screen.
    Each shape will have a name, position, speed, color, as well as properties unique to each shape type. For example, a Rectangle will have width and height, and a circle will have a Radius.
    For this assignment, the position of a shape refers to its SFML default of the upper-left corner of the shape.

    You are also required to make these shapes "bounce" off the sides of the window which contains them. This means that if the shapes's life side hit the life side of the window,
    its X speed reverses. If the top of the shape hits the top of the window, its Y speed reverses. Similiarly, if it hits the right side or bottom of the window.
    You can assume that all shapes will always be configured to start entirely within the window, and you don't have to worry about what happens if they start outside the window.
    Each shape's name should be drawn on the xact center of the shape in the given font size and color specified in the file.
    (Note: this may be the trickiest part of the assignment, you will not lose many marks if it's not the exact center)

    Each line of the configuration file specifies one of the config setting of the assignment program, with the first string in each line being the type of setting that the rest 
    of the line specified. Lines in the config file can be one of the following types and lines can appear in any order in the file

    Window W H
        This line declares that the SFML Window must be constructed with width W and height H, each of which will be integers

    Font F S R G B
        This line defines the font which is to be used to draw text for this program. The format of the line is as follows:
        Font File       F       std::string(it will have no spaces)
        Font Size       S       int
        RGB Color       (R,G,B) int, int, int

    Rectangle N X Y SX SY R G B W H
        Defines a RectangleShape with:
        Shape Name          Name        std::string
        Initial Position    (X,Y)       float, float
        Initial Speed       (SX,SY)     float, float
        RGB Color           (R,G,B)     int, int, int
        Size                (W,H)       float, float

    ---------------------------------------------------------------------------------------------------
    Assignment hints
    ---------------------------------------------------------------------------------------------------
    - In order to store an arbitrary number of shapes from the configuration file, you must store them in a container - std::vector is recommended
    - A shape will be 'touch' the side of the window if its bounding box makes contact with it. Each shapes's bounding rectangle can be obtained via:
            shape.getLocalBounds(); // .top, .left, .width,. height
            - gives the LOCAL position of the (top, left) of the rectangle
            - LOCAL pos means it is relative to shape.getPosition(), not the window
            - as well as the (width, height) size of the rectangle
    - Similarly, a sf::Text element's bounding rectangle can also be retrieved via text.getLocalBounds(), which you will need to use to center the text properly within a shape.
    - Please use C++ file reading (std::ifstream makes this easy) rather than C-style FILE reading. You will lose marks for using older C functions!