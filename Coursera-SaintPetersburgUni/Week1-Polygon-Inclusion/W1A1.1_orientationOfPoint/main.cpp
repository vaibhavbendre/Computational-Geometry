// **********************************************************************************************************
// PURPOSE		:	A template class definition for 3D point                                                *
// LANGUAGE		:		 C++ 17 (GNU GCC 8.4)                                                               *
// ASSUMPTIONS	:	As a convention, we consider the counter clockwise rotation as a left rotation.         *
//                            determinentValue > 0    counter clockwise rotation                            *
//                            determinentValue < 0    clockwise rotation                                    *
//                            determinentValue = 0    collinear points                                      *
//                                                                                                          *
// DATE			:	16 April 2020                                                                           *
// AUTHOR		:	Vaibhav BENDRE (vaibhav.bendre7520@gmail.com) 											*
//																											*
// **********************************************************************************************************

#include <iostream>
#include <algorithm>        // for using std::max and std::min functions

#include "Point.h"

// Template function to check the orientation of 3 ordered points. Make sure points are ordered one.
template<class T>
void displayOrientation(const Point<T>& A, const Point<T>& B, const Point<T>& C) {

    int determinentValue{ A.x * (B.y * C.z - B.z * C.y)  - A.y * (B.x*C.z - B.z*C.x) + A.z *(B.x*C.y -C.x*B.y)};
    if (determinentValue > 0)
        std::cout << "\033[F" << "\tLEFT";
    else if (determinentValue == 0) {
        if (std::min(A.x, B.x) <= C.x <= std::max(A.x, B.x) && std::min(A.y, B.y) <= C.y <= std::max(A.y, B.y))
            std::cout << "\033[F" << "\tON_SEGMENT";
        else
            std::cout << "\033[F" << "\tON_LINE";
        }
    else
        std::cout << "\033[F" << "\tRIGHT";
}


int main()
{
    Point<int> A (-4, 4 );
    Point<int> B (2, -2);

    std::cin >> A.x >> A.y >> B.x >> B.y;
    
    int numInputs{};
    std::cin >> numInputs;

    for (int iCounter{ 1 }; iCounter <= numInputs; ++iCounter) {
        Point<int> testObject;
        std::cin >> testObject.x >> testObject.y;
        displayOrientation<int>(A, B, testObject);
        std::cout << "\n";
    } 
}