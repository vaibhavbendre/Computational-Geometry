// **********************************************************************************************************
// PURPOSE		:	A template code for Computing 3D triangle area                                          *
// LANGUAGE		:		 C++ 17 (GNU GCC 8.4)                                                               *
// ASSUMPTIONS	:	Compute 2 Vectors and take cross product of those 2 vectors.                            *
//                  It will give us twice the area of triangle.                                             *
//                                                                                                          *
// DATE			:	14 July 2020                                                                            *
// AUTHOR		:	Vaibhav BENDRE (vaibhav.bendre7520@gmail.com) 											*
//																											*
// **********************************************************************************************************

#include<iostream>
#include<vector>

template<typename T>
struct Point3D {
	T x{};
	T y{};
	T z{};

	Point3D<T>(const T& xval = 0, const T& yval=0 , const T& zval = 0)
		: x{ xval }, y{ yval }, z{ zval }{}

	Point3D<T> operator-(const Point3D<T>& rhs){
		Point3D<T> ans;
		ans.x = x - rhs.x;
		ans.y = y - rhs.y;
		ans.z = z - rhs.z;
		return ans;
	}

	typedef std::vector<Point3D<T>> Triangle;

};



// area3D()  : Generic function to calculate both 3D and 2D areas of traingle. 
//    Input  : Three points P0, P1, and P2
//    Return : Area of a triangle irrespective of its coordinate plane.
//           : Magnitude of cross product of 2 vectors gives us the area of parallelogram
template <typename T>
double area3D(Point3D<T> V0, const Point3D<T>& V1,const Point3D<T>& V2){
	auto u = V0 - V1;
	auto v = V0 - V2;
	Point3D<T> cross;
	cross.x = (u.y * v.z - u.z * v.y);
	cross.y = (u.x * v.z - u.z * v.x);
	cross.z = (u.x * v.y - u.y * v.x);
	auto area = std::sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z) / 2.0;
	return area;
}


// Test Implementation
//template <typename T>
//double area3D(std::vector<Point3D<T>> tst ) {
//	auto u = tst.at(0) - tst.at(1);
//	auto v = tst.at(0) - tst.at(2);
//	Point3D<T> cross;
//	cross.x = (u.y * v.z - u.z * v.y);
//	cross.y = (u.x * v.z - u.z * v.x);
//	cross.z = (u.x * v.y - u.y * v.x);
//	auto area = std::sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z) / 2.0;
//	return area;
//}



int main(){

	Point3D<int> X{ 0,0,0 };
	Point3D<int> Y{ 0,3,0 };
	Point3D<int> Z{ 3,0,0 };

	//Sample implementation
	//Point3D<int>::Triangle Temp(3);
	//Temp.at(0) = X;
	//Temp.at(1) = Y;
	//Temp.at(2) = Z;


	std::cout << "Area of triangle is : " << area3D(X, Y, Z) << "\n" << std::flush;
	//std::cout << "Area of triangle is : " << area3D(Temp) << "\n" << std::flush;

}