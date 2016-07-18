# GLFW

[![Build status](https://travis-ci.org/glfw/glfw.svg?branch=master)](https://travis-ci.org/glfw/glfw)
[![Build status](https://ci.appveyor.com/api/projects/status/0kf0ct9831i5l6sp/branch/master?svg=true)](https://ci.appveyor.com/project/elmindreda/glfw)
[![Coverity Scan](https://scan.coverity.com/projects/4884/badge.svg)](https://scan.coverity.com/projects/glfw-glfw)

## Introduction

GLFW is a free, Open Source, multi-platform library for OpenGL, OpenGL ES and
Vulkan application development.  It provides a simple, platform-independent API
for creating windows, contexts and surfaces, reading input, handling events, etc.

The current stable release is version 3.2.  See the
[downloads](http://www.glfw.org/download.html) page for details and files, or
fetch the `latest` branch, which always points to the latest stable release.
Each release starting with 3.0 also has a corresponding annotated tag.

This is version 3.2.1, which is _not yet described_.

If you are new to GLFW, you may find the
[tutorial](http://www.glfw.org/docs/latest/quick.html) for GLFW
3 useful.  If you have used GLFW 2 in the past, there is a
[transition guide](http://www.glfw.org/docs/latest/moving.html) for moving to
the GLFW 3 API.


## Compiling GLFW

GLFW itself needs only the headers and libraries for your window system.  It
does not need the headers for any context creation API (WGL, GLX, EGL, NSGL) or
rendering API (OpenGL, OpenGL ES, Vulkan) to enable support for them.

GLFW supports compilation on Windows with Visual C++ 2010 and later, MinGW and
MinGW-w64, on OS X with Clang and on Linux and other Unix-like systems with GCC
and Clang.  It will likely compile in other environments as well, but this is
not regularly tested.

There are also [pre-compiled Windows
binaries](http://www.glfw.org/download.html) available for all compilers
supported on that platform.

See the [compilation guide](http://www.glfw.org/docs/latest/compile.html) in the
documentation for more information.


## Using GLFW

See the [building application guide](http://www.glfw.org/docs/latest/build.html)
guide in the documentation for more information.


## System requirements

GLFW supports Windows XP and later, OS X 10.7 Lion and later, and Linux and
other Unix-like systems with the X Window System.  Experimental implementations
for the Wayland protocol and the Mir display server are available but not yet
officially supported.

See the [compatibility guide](http://www.glfw.org/docs/latest/compat.html)
in the documentation for more information.


## Dependencies

The examples and test programs depend on a number of tiny libraries.  These are
located in the `deps/` directory.

 - [getopt\_port](https://github.com/kimgr/getopt_port/) for examples
   with command-line options
 - [TinyCThread](https://github.com/tinycthread/tinycthread) for threaded
   examples
 - An OpenGL 3.2 core loader generated by
   [glad](https://github.com/Dav1dde/glad) for examples using modern OpenGL
 - [linmath.h](https://github.com/datenwolf/linmath.h) for linear algebra in
   examples
 - [Vulkan headers](https://www.khronos.org/registry/vulkan/) for Vulkan tests

The Vulkan example additionally requires the Vulkan SDK to be installed, or it
will not be included in the build.

The documentation is generated with [Doxygen](http://doxygen.org/).  If CMake
does not find Doxygen, the documentation will not be generated.


## Reporting bugs

Bugs are reported to our [issue tracker](https://github.com/glfw/glfw/issues).
Please check the [contribution
guide](https://github.com/glfw/glfw/blob/master/.github/CONTRIBUTING.md) for
information on what to include when reporting a bug.


## Changelog

 - [X11] Bugfix: Didn't wait until window was visible before setting focus (#789)
 - Bugfix: Single compilation unit builds failed due to naming conflicts (#783)
 - Bugfix: The range checks for `glfwSetCursorPos` used the wrong minimum (#773)
 - [Win32] Bugfix: `glfwSetClipboardString` created an unnecessary intermediate
                   copy of the string
 - [Win32] Bugfix: Examples failed to build on Visual C++ 2010 due to C99 in
                   `linmath.h` (#785)
 - [Win32] Bugfix: The first shown window ignored the `GLFW_MAXIMIZED` hint
                   when the process was provided a `STARTUPINFO` (#780)
 - [GLX] Bugfix: Dynamically loaded entry points were not verified
 - [EGL] Bugfix: Dynamically loaded entry points were not verified


## Contact

The official website for GLFW is [glfw.org](http://www.glfw.org/).  There you
can find the latest version of GLFW, as well as news, documentation and other
information about the project.

If you have questions related to the use of GLFW, we have a
[support forum](http://discourse.glfw.org/), and the IRC
channel `#glfw` on [Freenode](http://freenode.net/).

If you have a bug to report, a patch to submit or a feature you'd like to
request, please file it in the
[issue tracker](https://github.com/glfw/glfw/issues) on GitHub.

Finally, if you're interested in helping out with the development of GLFW or
porting it to your favorite platform, join us on GitHub or IRC.


## Acknowledgements

GLFW exists because people around the world donated their time and lent their
skills.

 - Bobyshev Alexander
 - artblanc
 - arturo
 - Matt Arsenault
 - Keith Bauer
 - John Bartholomew
 - Niklas Behrens
 - Niklas Bergström
 - Doug Binks
 - blanco
 - Martin Capitanio
 - Chi-kwan Chan
 - Lambert Clara
 - Andrew Corrigan
 - Noel Cower
 - Jarrod Davis
 - Olivier Delannoy
 - Paul R. Deppe
 - Michael Dickens
 - Роман Донченко
 - Mario Dorn
 - Jonathan Dummer
 - Ralph Eastwood
 - Siavash Eliasi
 - Michael Fogleman
 - Gerald Franz
 - GeO4d
 - Marcus Geelnard
 - Eloi Marín Gratacós
 - Stefan Gustavson
 - Sylvain Hellegouarch
 - Matthew Henry
 - heromyth
 - Lucas Hinderberger
 - Paul Holden
 - IntellectualKitty
 - Aaron Jacobs
 - Toni Jovanoski
 - Arseny Kapoulkine
 - Osman Keskin
 - Cameron King
 - Peter Knut
 - Christoph Kubisch
 - Eric Larson
 - Robin Leffmann
 - Glenn Lewis
 - Shane Liesegang
 - Eyal Lotem
 - Дмитри Малышев
 - Martins Mozeiko
 - Tristam MacDonald
 - Hans Mackowiak
 - Zbigniew Mandziejewicz
 - Kyle McDonald
 - David Medlock
 - Bryce Mehring
 - Jonathan Mercier
 - Marcel Metz
 - Jonathan Miller
 - Kenneth Miller
 - Bruce Mitchener
 - Jack Moffitt
 - Jeff Molofee
 - Jon Morton
 - Pierre Moulon
 - Julian Møller
 - Kamil Nowakowski
 - Ozzy
 - Andri Pálsson
 - Peoro
 - Braden Pellett
 - Arturo J. Pérez
 - Orson Peters
 - Emmanuel Gil Peyrot
 - Cyril Pichard
 - Pieroman
 - Jorge Rodriguez
 - Ed Ropple
 - Aleksey Rybalkin
 - Riku Salminen
 - Brandon Schaefer
 - Sebastian Schuberth
 - Matt Sealey
 - SephiRok
 - Steve Sexton
 - Systemcluster
 - Yoshiki Shibukawa
 - Dmitri Shuralyov
 - Daniel Skorupski
 - Bradley Smith
 - Julian Squires
 - Johannes Stein
 - Justin Stoecker
 - Elviss Strazdins
 - Nathan Sweet
 - TTK-Bandit
 - Sergey Tikhomirov
 - Arthur Tombs
 - Ioannis Tsakpinis
 - Samuli Tuomola
 - urraka
 - Jari Vetoniemi
 - Ricardo Vieira
 - Nicholas Vitovitch
 - Simon Voordouw
 - Torsten Walluhn
 - Patrick Walton
 - Xo Wang
 - Jay Weisskopf
 - Frank Wille
 - yuriks
 - Santi Zupancic
 - Jonas Ådahl
 - Lasse Öörni
 - All the unmentioned and anonymous contributors in the GLFW community, for bug
   reports, patches, feedback, testing and encouragement

