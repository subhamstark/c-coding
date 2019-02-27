#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<string>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> > adjList;
	public:
		Graph()
		{
		}
		void addEdge(T u,T v,bool bidir=true)
		{
			adjList[u].push_back(v);
			if(bidir)
			{
				adjList[v].push_back(u);
			}
		}
		void printAdjList(){
			for(auto i:adjList){
				cout<<i.first<<"->";
				
				for(auto entry:i.second){
					cout<<entry<<",";
				}
				cout<<endl;
			}
		}
		void bfs(T src)
		{
			queue<T> q;
			map<T,bool> visited;
			q.push(src);
			visited[src]=true;
			
			while(!q.empty())
			{
				T node = q.front();
				cout<<node<<"  ";
				q.pop();
				
				for(T neighbour:adjList[node])
				{
					if(visited[neighbour]==false)
						{
						q.push(neighbour);
						visited[neighbour]=true;
						}
				}
			}
			
		}
};
int main()
{
	Graph <string>g;
	g.addEdge("Putin","Trump",false);
	
	g.addEdge("Putin","Modi",false);
	
	g.addEdge("Putin","Pope",false);
	
	g.addEdge("Modi","Trump",true);
	
	g.addEdge("Modi","Yogi",true);
	
	g.addEdge("Yogi","Prabhu",false);
	
	g.addEdge("Prabhu","Modi",false);
	g.bfs("Modi");
}