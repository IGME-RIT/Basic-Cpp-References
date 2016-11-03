/*
References
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;
#include "../header/refTestFunctions.h"

int main()
{
    // ==== Refernces ====
    
    // Now that you know what a pointer is, and how the const keyword works, references are easier to understand.
    {
        // A reference is much like a constant pointer.
        // You first need a value to point to:
        int x = 1;
        cout << "[int x = 1;]" << endl;

        // Assigning a const pointer:

        //      Const pointers can't be initialized without values.
        // int* const yptr;     // Nope!

        int * const xptr = &x;  // Initializing with a value.
        cout << "[int* xptr = &x;]" << endl;
        cout << "xptr points to: " << *xptr << endl;    // Now we have to dereference the pointer whenever we want the value.


        //      A reference can't be intialized without a value either.
        // int& yref;           // Nope!

        // Assigning a reference:
        int& xref = x;  // The key difference here is that we don't use the address of (&) operator.
                        // References do this automatically when initialized.
        cout << "[int& xref = x;]" << endl;
        cout << "xref: " << xref << endl;     // With a reference, the dereference is also automatic.


        cout << "Press enter to continue..." << endl;
        cin.get();


        // Once a reference has been initialized, you actually touch the pointer at all:
        int y = 99;
        cout << "[int y = 99;]" << endl;
        xref = y;                           // You might think this would change xref to point at y, but it doesn't.
        cout << "[xref = y;]" << endl;      // References are automatically dereferenced whenever used after initialization, this the same as *xptr = y;
        xref++;
        cout << "[xref++;]" << endl;
        cout << "xref: " << xref << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
    cin.get();

    {
        // Minor differences between references and const pointers:
        cout << "References can't be null, but pointers can!" << endl;

        // A const pointer can be initialized to nullptr:
        int * const dumbPointer = nullptr;  // This is a really dumb thing to do though.
                                            // This pointer will be null forever. Why would anyone do this?
        
        // Since references are initialized with an object that already exists, it is impossible for them to be created without a valid memory address.
    }
    cin.get();


    {
        // Using references with functions:
        int x = 0;
        cout << "[int x = 0;]" << endl;

        AddToReference(x);                      // Passing variables into functions that take references instead of base types:
        cout << "[AddToReference(x);]" << endl; // Any change made to the reference internally will be reflected when that function is finished.

        cout << "x: " << x << endl;


        // The most common mistake people make is trying to do it the other way around:
        int& badRef = MakeAReference(); // Functions that return references are not inherently bad, but this one is if you look at the definition.
        cout << badRef << endl;
        //      Extremely Dangerous: the thing badRef points to has been deleted, so trying to access that memory is a bad idea:
        // badRef++;
    }

    cout << "End of program." << endl;
    cin.get();  // Wait for input before closing.
    return 0;   // End Program.
}