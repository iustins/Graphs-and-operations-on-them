#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct coordinates{int x; int y;};

int main()
{

	int N, M, K, i, j, k, l, c[101][101], min, max, aria, ariamax, ok, ok2;
	int visited[101][101];
	coordinates index, newindex, fr;
	queue <coordinates> q;

	ifstream fi( "p2.in" );
	ofstream fo( "p2.out" );

	fi >> N >> M >> K;

	for(i = 1; i <= N; i++)
		for(j = 1; j <= M; j++)
			fi >> c[i][j];

	ariamax = 0;

        for(i = 1; i <= N; i++)
		for(j = 1; j <= M; j++)
     	  	{
			min = max = c[i][j];
			index.x = i;
			index.y = j;
			q.push(index);
			visited[i][j] = 1;
			aria = 1;

			while(!(q.empty()))
			{
				fr = q.front();
				k = fr.x;
			        l = fr.y;

				if(k > 1)
				{
					newindex = fr;
					newindex.x = k - 1;
					ok = 1;
					ok2 = 0;

					if( visited[newindex.x][newindex.y] )
                            			ok = 0;

					if(ok)
 					{

                        		 	if(  c[newindex.x][newindex.y] <= max  && c[newindex.x][newindex.y] >= min )
                           				   ok2 = 1;
 
 						else if( c[newindex.x][newindex.y] < min )
							   if((max - c[newindex.x][newindex.y]) <= K )
							   {	
								min = c[newindex.x][newindex.y];
								ok2  = 1;
							   }

					        else if( c[newindex.x][newindex.y] > max )
							   if( (c[newindex.x][newindex.y] - min ) <= K )
							   {	
								max = c[newindex.x][newindex.y];
								ok2 = 1;
							   }

						if(ok2)
						{
							q.push(newindex);
							visited[newindex.x][newindex.y] = 1;
							aria++;
						}
					}
				}

				if(l > 1)
				{
					newindex = fr;
					newindex.y = l - 1;
					ok = 1;
					ok2 = 0;

					if( visited[newindex.x][newindex.y] )
                            			ok = 0;

					if(ok)
 					{

                        			if(  c[newindex.x][newindex.y] <=max  && c[newindex.x][newindex.y] >= min )
                            				ok2 = 1;

 						else if( c[newindex.x][newindex.y] < min )
							   if((max - c[newindex.x][newindex.y]) <= K )
							   {	
								min = c[newindex.x][newindex.y];
								ok2  = 1;
							   }

					 	else if( c[newindex.x][newindex.y] > max )
							   if( (c[newindex.x][newindex.y] - min ) <= K )
							   {	
								max = c[newindex.x][newindex.y];
								ok2 = 1;
							   }
						if(ok2)
						{
							visited[newindex.x][newindex.y]=1;
							q.push(newindex);
							aria++;
						}
					}
				}

				if(l < M)
				{
					newindex = fr;
					newindex.y = l + 1;
					ok = 1;
					ok2 = 0;

					if( visited[newindex.x][newindex.y] )
						ok = 0;

					if(ok)
 					{
						if(  c[newindex.x][newindex.y] <=max  && c[newindex.x][newindex.y] >= min )
                           				 ok2 = 1;

 					        else if( c[newindex.x][newindex.y] < min )
							   if((max - c[newindex.x][newindex.y]) <= K )
							   {	
								min = c[newindex.x][newindex.y];
								ok2  = 1;
							   }

					 	else if( c[newindex.x][newindex.y] > max )
							   if( (c[newindex.x][newindex.y] - min ) <= K )
							   {	
								max = c[newindex.x][newindex.y];
								ok2 = 1;
							   }
						if(ok2)
						{

							visited[newindex.x][newindex.y] = 1;
							q.push(newindex);
							aria++;
						}
					}
				}

				if(k < N)
				{
					newindex = fr;
					newindex.x = k + 1;
					ok = 1;
					ok2 = 0;

					if( visited[newindex.x][newindex.y])
						ok = 0;

					if(ok)
 					{
						 if(  c[newindex.x][newindex.y] <=max  && c[newindex.x][newindex.y] >= min )
                        				    ok2 = 1;

 						 else if( c[newindex.x][newindex.y] < min )
							   if((max - c[newindex.x][newindex.y]) <= K )
							   {	
								min = c[newindex.x][newindex.y];
								ok2  = 1;
							   }

					 	 else if( c[newindex.x][newindex.y] > max )
							   if( (c[newindex.x][newindex.y] - min ) <= K )
							   {
							       	max = c[newindex.x][newindex.y];
								ok2 = 1;
							   }
						if(ok2)
						{
							q.push(newindex);
							visited[newindex.x][newindex.y] = 1;
							aria++;
						}
					}
				}
				 q.pop();
			}


       		 for(k = 1; k <= N; k++)
           		 for(l = 1; l <= M; l++) 
				visited[k][l]= 0;

		 if(aria > ariamax)
			ariamax = aria;
        	 }

		fo << ariamax;

		fi.close();
		fo.close();


	return 0;
}















