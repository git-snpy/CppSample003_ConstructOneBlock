#include <kv/allsol.hpp>

namespace ub = boost::numeric::ublas;

struct Func {
	template <class T> ub::vector<T> operator() (const ub::vector<T>& x){
		ub::vector<T> y(3);
                
                double a = .01;
                double c = .5;
                double gam = 0.;
                double del = 5.;
                
              
                
//		y(0) = x(1);
//                y(1) = (1./del) * (c * x(0) - x(1) * (x(1) - a) * (1 - x(1)) + x(2));
//		y(2) = .01 * (1./c) * ( x(1) - gam * x(2));
                
                // fix w = 0.0
                y(0) = x(1);
                y(1) = (1./del) * (c * x(1) - x(0) * (x(0) - a) * (1 - x(0)) + 0.);
		y(2) = .001 * c * (x(0) - gam * 0.);

		return y;
	}
};

//struct Func2 {
//	template <class T> ub::vector<T> operator() (const ub::vector<T>& x){
//		ub::vector<T> y(2);
//
//		y(0) = x(0) * x(0) + x(1) * x(1) - 1;
//		y(1) = 2 * x(0) * x(0) - x(1) - 1;
//
//		return y;
//	}
//};
//
//struct Func3 {
//	template <class T> T operator() (const T& x){
//		return x / 10 + sin(x);
//	}
//};
//
//struct Func4 {
//	template <class T> T operator() (const T& x){
//		return x*x*x - x*x;
//	}
//};


typedef kv::interval<double> itv;

int main()
{
	int i;
	ub::vector<itv> I;

	std::cout.precision(17);

	I.resize(3);
	for (i=0; i<I.size(); i++) I(i) = itv(-100., 100.);

	kv::allsol(Func(), I);

//	kv::allsol(Func2(), I, 1, 1e-8);
//
//	kv::allsol(Func3(), itv(-10, 10));
//
//	kv::allsol(Func4(), itv(-10, 10), 1, 1e-8);
}