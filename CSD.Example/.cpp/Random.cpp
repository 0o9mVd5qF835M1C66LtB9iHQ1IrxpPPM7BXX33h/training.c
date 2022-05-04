#include <iostream>
#include <set>
#include <stdexcept>

using namespace std;

class Random
{
	const int m_low, m_high;
	std::set<int> mset;
public:
	Random(int l, int h):m_low(1), m_high(h){}
	int operator()();
};

int Random::operator ()()
{
	const int dif=m_high-m_low+1;
	if(mset.size()==dif)
		throw logic_error("no more random numbers in class Random");
	int val;
	while(!mset.insert(val=rand()%dif+m_low).second)
		;
	return val;
}
int main()
{
	Random urand(0, 100);
	for(int k=0;k<101;++k)
		cout<<urand()<<" ";
	return 0;
}
