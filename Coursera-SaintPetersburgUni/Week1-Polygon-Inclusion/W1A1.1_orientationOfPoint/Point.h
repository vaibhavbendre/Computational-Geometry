// **********************************************************************************************************
// PURPOSE		:	A template class definition for 3D point                                                *
// LANGUAGE		:		 C++ 17 (GNU GCC 8.4)                                                               *
// ASSUMPTIONS	:	For the sake of easy access all attributes are defined as private.                      *
// DATE			:	16 April 2020                                                                           *
// AUTHOR		:	Vaibhav BENDRE (vaibhav.bendre7520@gmail.com) 											*
//																											*
// **********************************************************************************************************

#pragma once

template<class T>
class Point{
    public:
        T x, y, z;

        Point()
            : x{0}, y{0}, z{1} {}

        Point(const T& xVal, const T& yVal)
            : x{xVal}, y{yVal} {}

        Point(const T& xVal, const T& yVal, const T& zVal)
            : x{xVal}, y{yVal}, z{zVal} {}

};
