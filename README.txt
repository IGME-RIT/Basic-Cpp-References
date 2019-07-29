Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the References Tutorial!
Prerequesites: Pointers

Pointer is a location in memory. Every pointer is exactly 4 bytes large.
If you have an integer
  int x = 21;
  
The variable 'x' has a value of 21, but it also has a location in memory. 
Some computers have 8gb of RAM, in a computer that has 8gb of RAM, there 
are 8 billion different places where this variable might be.

x has a value of 21
&x has a value of the location in memory where 'x' is stored.

In this tutorial, we show where pointers can be useful, and 
why they are important.
