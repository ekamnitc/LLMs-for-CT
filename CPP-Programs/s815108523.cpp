#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	while (true)
	{
		int count;
		double n[1000] = {};
		double avg = 0;
		double sum = 0;
		double bunsan;
	
		cin >> count;

		if (count == 0)
			return 0;

		for (int i = 0; i < count; i++)
		{
			cin >> n[i];
			avg += n[i];
		}
		avg /= (double)count;

		for (int i = 0; i < count; i++)
		{
			sum += pow(n[i] - avg, 2);
		}

		bunsan = (1.0 / (double)count) * sum;
		cout << (sqrt(bunsan) ? sqrt(bunsan) : 0) << endl;
	}
}
