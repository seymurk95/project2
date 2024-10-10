#include <iostream>
#include "time.h"
bool IsAfternoonTime(const chron::Time& time)
{
	return time.GetHours()>=12;
}
int main()
{
	/*chron::Time t(1300,-30,0);
	std::cout<<t.GetHours()<<"\n";
	std::cout<<t.GetMinutes()<<"\n";
	std::cout<<t.GetSeconds()<<"\n";*/
	
	/*if(IsAfternoonTime(t))
	{
		std::cout<<t.GetHours()-12<<"PM\n";
	}*/
	
	chron::Time t1(10,18,-5);
	chron::Time t2;
	chron::Time t3(3600);
	chron::Time t4;
	std::cin>>t4;
	std::cout<<t4<<"\n";
	t2.AddSeconds(3600);
	/*std::cout<<t1.GetHours()<<" ";
	std::cout<<t1.GetMinutes()<<" ";
	std::cout<<t1.GetSeconds()<<"\n";*/
	
	/*std::cout<<t2<<"\n";
	std::cout<<t2.GetHours()<<" ";
	std::cout<<t2.GetMinutes()<<" ";
	std::cout<<t2.GetSeconds()<<"\n";
	std::cout<<t2.TotalSeconds()<<"\n";
	std::cout<<t2-t3<<"\n";*/
	
	/*std::cout<<t3.GetHours()<<" ";
	std::cout<<t3.GetMinutes()<<" ";
	std::cout<<t3.GetSeconds()<<"\n";*/
	
	
}
