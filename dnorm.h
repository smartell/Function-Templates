/*
	Author Steve Martell
	Example of using function templates instead of overloading functions.
*/



#include <fvar.hpp>
#include <admodel.h>
#include <df1b2fun.h>
#include <adrndeff.h> 

// This works:
template <typename T1,typename T2>
dvariable nll_dnorm(T1 tO, T2 tP)
{
	int n  = size_count(tO);
	dvariable SS = sum(square(tO-tP));
	dvariable nloglike = 0.5 * n * log(SS);
	return(nloglike);
}

// This does now works, note that xxx is never used but required to specify type.
template <typename T1,typename T2,typename T3>
T3 nll_dnorm(T1 tO, T2 tP, T3 xxx)
{
	int n  = size_count(tO);
	T3 SS = sum(square(tO-tP));
	T3 nloglike = 0.5 * n * log(SS);
	cout<<"Eye of newt"<<endl;
	return(nloglike);
}

