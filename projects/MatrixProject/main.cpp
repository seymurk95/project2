#include <iostream>
#include "matrix.h"
int main()
{
	Matrix<int> m({
		{1,2,3},
		{4,5,6}
	});
	//std::cout<<m.GetRows()<<"\n";
	//std::cout<<m.GetColumns()<<"\n";
	Matrix<int> md(2,3);
	/*int el= m[0][1];
	m[1][1]=11;
	md[0].resize(10);*/
	std::cin>>md;
	m+=md;
	Matrix<int> res(2,3);
	res=m+md;
	std::cout<<res;
}
