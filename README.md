# Raise the terrain
### Concepts

_For this project, we expect you to look at this concept:_

-   [SDL2 - Installation](https://intranet.hbtn.io/concepts/883)

![](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/graphics_programming/raise_the_terrain/Raise_terrain.gif)

## Background Context

**This project is NOT mandatory**  at all. It is 100% optional. Doing any part of this project will add a project grade of over 100% to your average. Your score won’t get hurt if you don’t do it, but if your current average is greater than your score on this project, your average might go down. Have fun!

Be careful with tutorials/help online: We are using  `SDL2`, and not  `SDL-1.2`!

## Resources

**Read or watch**:

-   Install SDL2 concept page
-   [SDL2 tutorials](https://intranet.hbtn.io/rltoken/Xy_9TAuRTgtkpaHtHeSxzQ "SDL2 tutorials")

## Requirements

### General

-   The OS of your choice
-   A  `README.md`  file, at the root of the folder of the project is mandatory
-   All your functions must be commented and respect the Betty style
-   Your functions should be maximum 60 lines long (one statement per line)
-   Your functions should be maximum 80 column long
-   No more than 5 functions per file
-   There is no forbidden function for this project. You are allowed to use any system call and/or standard library function.
-   You are allowed to use  [all the functions provided by SDL2](https://intranet.hbtn.io/rltoken/fl7bK7hXi0gn33TACJCqJA "all the functions provided by SDL2")

## More Info

### Manual QA Review

**It is your responsibility to request a review for this project from a peer before the project’s deadline. If no peers have been reviewed, you should request a review from a TA or staff member.**

## Tasks

### 0. Basics



### Isometric projection

The following image is the isometric projection of a grid:

![](https://holbertonintranet.s3.amazonaws.com/uploads/medias/2020/9/10a0e33273cfd07850f6d91ead6bce73dfc6b32b.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220825%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220825T054037Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=f913966c7fd3641f290a7fc840192db563f157deabe58ad8aef7730b172c812c)

Given the following altitudes,

```
120 60 40 60 20 -20 -80 -120
40 20 30 30 -10 -40 -90 -110
20 30 10 06 -6 -20 -26 -90
00 -6 10 10 -6 -20 -20 -40
-20 -20 -18 -14 -40 -20 -20 -30
-10 -10 -10 -10 -8 -20 -20 -30
20 10 10 10 10 04 10 -10
30 24 24 22 20 18 14 16

```

the grid should look like this:

![](https://holbertonintranet.s3.amazonaws.com/uploads/medias/2020/9/a7111e7e11bd23c0b66e79f97f32d879e89dcff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220825%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220825T054037Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d3d1d0565cf24051044e9ada38cc38b3297bab53bf74181081ed3812d942f453)

### Maths

To draw a grid using isometric projection, you’ll need to convert 3D coordinates (coordinates in the real world) to 2D coordinates (coordinates on the screen), as follows:

![](https://holbertonintranet.s3.amazonaws.com/uploads/medias/2020/9/e07c3b1a34523b467eec5235b646194617354b42.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220825%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220825T054037Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=ffceab0da3dcf36fe253c28051a87baf4831265e9105f966b9bb206431f6a791)

You can choose to incline your grid as much as you want.

```
WX = inclination * X - inclination * Y;
WY = (1 - inclination) * X + (1 - inclination) * Y - Z;

```

where an  `inclination`  of 70% would have a value of  `0.7`  in this above equation.

### Requirements

-   Usage:  `terrain file`
-   Draw a grid using an isometric projection
-   The grid must be described in a file (see above example)
-   The color used to draw the grid doesn’t matter (same for the background)
-   The grid doesn’t need to be  _exactly_  the same as the one shown above. But make sure you have a coherent isometric projection.
-   Your grid must be centered and takes as much space as possible on the screen. We should be able to see the whole screen.
-   Your program should end when the user is pressing the  `ESC`  key

====================================================
### 1. Rotation
-   Rotate the grid when the user is using left or right arrows
-   Please use the  `M_PI`  macro defined in  `math.h`
-   Link with the gcc  `-m`  flag to be able to use the math library

Here is the formula to apply a rotation to a point in 2D:

-   The 2D point you want to rotate is defined with the coordinates [x, y].
-   The rotation angle  `a`  is calculated as follow:

```
a = Angle * PI / 180

```

`Angle`  being the angle in degrees, and  `a`  the angle in radians.

```
Rx = x * cos(a) - y * sin(a)
Ry = x * sin(a) + y * cos(a)

```

**Repo:**

-   GitHub repository:  `holbertonschool-Raise_the_terrain`

