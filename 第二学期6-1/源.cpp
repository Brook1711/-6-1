#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void Cij(int i, int j, vector<int> &r, int num, vector<vector<int> > & result)
{
	//排列组合公式Cij  
	//cout << n << ' ' << i << ' ' << j << endl;  
	if (j == 1)
	{
		for (int k = 0; k < i; k++)
		{
			vector<int> temp(num);
			r[num - 1] = k;
			for (int i = 0; i < num; i++)
			{
				temp[i] = r[i];
				//cout << r[i] << ' ';  
			}
			result.push_back(temp);
			//cout << endl;  
		}
	}
	else if (j == 0)
	{
		//do nothing!  
	}
	else
	{
		for (int k = i; k >= j; k--)
		{
			r[j - 2] = k - 1;
			Cij(k - 1, j - 1, r, num, result);
		}
	}
}
int main()
{
	vector<int> market, profit, sprofit, r , sr;
	vector<vector<int>> result, sresult;
	int t = 0;
	int vsize = 0;
	while (cin >> t)
	{		market.push_back(t);
		r.push_back(vsize);
		sr.push_back(vsize);
		vsize++;
	}
	t = 0;



	Cij(vsize,4,r,4,result);

	Cij(vsize,2,sr,2,sresult);

	int solutionsize = result.size();
	int ssolutionsize = sresult.size();
	for (int i = 0; i < solutionsize; i++)
	{
		sort(result[i].begin(), result[i].end());
		int t = market[result[i][1]] - market[result[i][0]] + market[result[i][3]] - market[result[i][2]];
		profit.push_back(t);
	}

	for (int i = 0; i < ssolutionsize; i++)
	{
		sort(sresult[i].begin(), sresult[i].end());
		int t = market[sresult[i][1]] - market[sresult[i][0]];
		sprofit.push_back(t);
	}

	auto maxPosition = max_element(profit.begin(), profit.end());







	auto smaxPosition = max_element(sprofit.begin(), sprofit.end());
	int omax = *smaxPosition > *maxPosition ? *smaxPosition : *maxPosition;
	//cout << profit.size() << " " << sprofit.size() << endl;
	if (omax >= 0)
		cout << omax;
	else
		cout << 0;
	//system("pause");
	return 0;
}