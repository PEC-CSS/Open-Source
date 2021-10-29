#include <iostream>
#include <cmath>
using namespace std;
 
// Function to check if the triangle
void checkTriangle(int x, int y, int z)
{
	// sorthing x, y and z.
    if (x > z){
    	x = x + z;
		z = x - z;
		x = x - z;
    }

	if (x > y){
		x = x + y;
		y = x - y;
		x = x - y;
	}
	//Now the smallest element is the 1st one. Just check the 2nd and 3rd
	if (y > z){
		y = y + z;
		z = y - z;
		y = y - z;
	}

	// Check for triangle valid or not.
	if (x + y <= z) {
        cout << "Triangle not possible";
    	return;
    }

    // Check for equilateral triangle
    else if (x == y && y == z)
        cout << "Equilateral";
 
    // Check for isosceles triangle
    else if (x == y || y == z || z == x)
        cout << "Isosceles";
 
    // Otherwise scalene triangle
    else {
        cout << "Scalen" << ", ";

        // Check for Right angled triangle
	    if (pow(z,2) == pow(x, 2) + pow(y, 2))
	        cout << "Right-angled";

	    // Check for Obtuse angle triangle
	    else if(pow(z,2) > pow(x, 2) + pow(y, 2))
	        cout << "Obtuse-angled";
	    
	    else
	        cout << "Acute-angled";
	}
}

// Driver Code
int main()
{    
    // Given sides of triangle
    int x , y , z;
    cout << "Enter length of side of triangle : ";
    cin >> x >> y >> z;
     
    // Function call
    checkTriangle(x, y, z);
    cout << endl;
}
