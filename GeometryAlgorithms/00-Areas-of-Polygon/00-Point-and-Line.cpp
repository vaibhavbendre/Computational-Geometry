// **********************************************************************************************************
// PURPOSE		:	A template class definition for identifying the position of 2D and 3D point resp.       *
//                  Compute area of triangle                                                                *
// LANGUAGE		:		 C++ 17 (GNU GCC 8.4)                                                               *
// ASSUMPTIONS	:	For the sake of easy access all attributes are defined as public.                       *
// DATE			:	14 July 2020                                                                            *
// AUTHOR		:	Vaibhav BENDRE (vaibhav.bendre7520@gmail.com) 											*
//																											*
// **********************************************************************************************************
#include <iostream>
#include <vector>

template<typename T>
struct Point2D
{
	T x{};
	T y{};

	Point2D<T>(const T& xval = 0, const T& yval = 0)
		: x{ xval }, y{ yval }{}
};

// Best practice is to use scoped enums
enum pointStatus
{
	Left,
	Right,
	On
};

// pointOn(): test if a point is Left|Right or on the line segment. 
//            Orientation of 3 ordered points set.
//    Input:  three points P0, P1, and P2
//    Return: Enum specifying status of point and line
//    Condition: > 0 for P2 left of the line through P0 to P1 (Counter clockwise)
//               = 0 for P2 on the line (Degenerate case)
//               < 0 for P2 right of the line (Clockwise)
template<typename T>
constexpr pointStatus pointOn(const Point2D<T>& P0, const Point2D<T>& P1, const Point2D<T>& P2) {
	auto detVal = ((P1.x - P0.x) * (P2.y - P0.y)
		- (P2.x - P0.x) * (P1.y - P0.y));
	return ((detVal != 0) ? (detVal > 0 ? pointStatus::Left : pointStatus::Right) : pointStatus::On);
}

//-----------------------------------------------------------------------------------------------------

//  Note: DRY is not being followed but in this case idea was to seperate out 2 different cases.
//  Above function can be slightly modified and used to compute area of triangle
//  Input:  three vertex points V0, V1, V2
//  Return: area of triangle as double. 
 
template<typename T>
constexpr double area_2DTriangle(const Point2D<T>& V0, const Point2D<T>& V1, const Point2D<T>& V2)
{
	auto detVal = ((V1.x - V0.x) * (V2.y - V0.y)
		- (V2.x - V0.x) * (V1.y - V0.y));
	return (static_cast<double>(detVal / 2.0));
}

//--------------------------------------------------------------------------------------------------------

int main()
{
	Point2D<int> X{ 0,0 }, Y{ 5,5 }, Z{ 5,0 };

	auto status = pointOn(X, Y, Z);

	switch (status)
	{
	case Left: {
		std::cout << "The point is on Left\n" << std::flush;
		break;
	}
	case Right: {
		std::cout << "The point is on Right\n" << std::flush;
		break;
	}
	case On: {
		std::cout << "The point is on the line\n" << std::flush;
		break;
	}
	default:
		break;
	}

	auto area = area_2DTriangle(X, Y, Z);
	std::cout << "Area is : " << fabs(area) << "\n" << std::flush;

}