#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

	struct nod{ int index; int dist;};
	struct muchie{ nod st; nod dr;};

	bool myfunction (nod i,nod j) { return (i.dist<j.dist); }


int main()

{

        ios_base::sync_with_stdio(false);
	int i, N, cnt = 0;
	int v[100001];
	muchie rez[100001];
	nod vec[100001], min;

	ifstream fin( "p1.in" );
	ofstream fout( "p1.out" );

	fin >> N;

	for(i = 1; i <= N; i++)
		fin >> v[i];

	for(i = 1; i <= N; i++)
	{
		vec[i].index = i;
		vec[i].dist = v[i];
	}

    	sort(vec + 1, vec + N + 1, myfunction);

		if(vec[2].dist == 0)
        {
			fout << -1;
			return 0;
        }
		else
		{
			min = vec[1];

			for(i = 2; i <= N; i++)
			{
				if((vec[i].dist - vec[i-1].dist) > 1)
				{
					fout << -1;
					return 0;
				}

			        if((vec[i].dist - min.dist) == 1)
				{
					cnt++;
					rez[cnt].st = min;
					rez[cnt].dr = vec[i];
				}

				if((vec[i].dist - min.dist) == 2)
				{
					min = vec[i-1];
					cnt++;
					rez[cnt].st = min;
					rez[cnt].dr = vec[i];
				}
			}
		  }

		  fout << cnt << endl;
		  for(i = 1; i <= cnt; i++)
			fout << rez[i].st.index << " " << rez[i].dr.index << endl;

		  fin.close();
		  fout.close();

	return 0;
}






































