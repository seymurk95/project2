#ifndef TIME_H
#define TIME_H
#include <iostream>
namespace chron
{
	class Time 
	{
		private:
		int totalSeconds;
		void normalise();
		
		public:
		Time()=default;
		Time(int h,int m,int s);
		Time(int s): Time(0,0,s){}
		int GetHours() const;
		int GetMinutes() const;
		int GetSeconds() const;	
		void AddSeconds(int s);	
		int TotalSeconds()const;
		Time& operator+=(int s);
		Time operator+(int s)const;
    };
   /* Time operator +(const Time t,int s)
    {
		return Time(t.GetHours(),t.GetMinutes(),t.GetSeconds()+s);
	}*/
	
}
int operator-(const chron:: Time& t1,const chron:: Time& t2);
std::ostream& operator<<(std::ostream& out,const chron::Time& t);
std::istream& operator>>(std::istream& in,chron::Time& t);

#endif //TIME_H
