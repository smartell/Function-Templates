/*
	Author Steve Martell
	Example of using function templates instead of overloading functions.
*/



#include <fvar.hpp>
#include <admodel.h>
#include <df1b2fun.h>
#include <adrndeff.h> 

// The following was pointed out by Dave Fournier
// as a better method for dealing with the type problem.
template<typename T>
class AccumulationTraits;
template<>
class AccumulationTraits<dvar_vector> {
	public:
	typedef dvariable AccT;
};
template<>
class AccumulationTraits<df1b2vector> {
	public:
	typedef df1b2variable AccT;
};


  // this is your nll_dnorm function
template <typename T1,typename T2>
typename AccumulationTraits<T2>::AccT nll_dnorm(T1 tO, T2 tP) 
{
	typedef typename AccumulationTraits<T2>::AccT AccT;
	int n  = size_count(tO);
	AccT SS = sum(square(tO-tP));
	AccT nloglike = 0.5 * n * log(SS);
	return(nloglike);
}
  // overloaded this function in case uses puts predicted then observed in the args
template <typename T1,typename T2>
typename AccumulationTraits<T1>::AccT nll_dnorm(T1 tO, T2 tP) 
{
	typedef typename AccumulationTraits<T1>::AccT AccT;
	int n  = size_count(tO);
	AccT SS = sum(square(tO-tP));
	AccT nloglike = 0.5 * n * log(SS);
	return(nloglike);
}

// This works:
// template <typename T1,typename T2>
// dvariable nll_dnorm(T1 tO, T2 tP)
// {
// 	int n  = size_count(tO);
// 	dvariable SS = sum(square(tO-tP));
// 	dvariable nloglike = 0.5 * n * log(SS);
// 	return(nloglike);
// }

// This also works; but must cast the call, eg: nll_dnorm<dvariable>(obs,pre)
// See AccumulationTraits method above.
// template <typename T0,typename T1,typename T2>
// T0 nll_dnorm(T1 tO, T2 tP)
// {
// 	int n  = size_count(tO);
// 	T0 SS = sum(square(tO-tP));
// 	T0 nloglike = 0.5 * n * log(SS);
// 	cout<<"Wort of Frog"<<endl;
// 	return(nloglike);
// }

// This does now work, note that xxx is never used but required to specify type.
template <typename T1,typename T2,typename T3>
T3 nll_dnorm(T1 tO, T2 tP, T3 xxx)
{
	int n  = size_count(tO);
	T3 SS = sum(square(tO-tP));
	T3 nloglike = 0.5 * n * log(SS);
	cout<<"Eye of newt"<<endl;
	return(nloglike);
}

