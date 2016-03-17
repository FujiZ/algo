#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
	Edge(int s,int e,int w):start(s),end(e),weight(w){}
	int start;
	int end;
	int weight;
};

int cmp(const Edge* a,const Edge* b){
	return a->weight<=b->weight;
}

int getEnd(int* vends,int i){
	while(vends[i]>=0)
		i=vends[i];
	return i;
}

void kruskal(int n,vector<Edge*>& edges,vector<Edge*>& result){
	int *vends=new int[n];	//用于保存最小生成树节点的终点
	for(int i=0;i<n;++i)
		vends[i]=-1;
	//先对edges进行排序
	sort(edges.begin(),edges.end(),cmp);
	int count=0;
	for(vector<Edge*>::iterator iter=edges.begin();iter!=edges.end();++iter){
		int start=getEnd(vends,(*iter)->start);	//找到start的终点
		int end=getEnd(vends,(*iter)->end);		//找到end的终点
		if(start!=end){
			vends[start]=end;
			result.push_back(*iter);
			if(++count==n-1)
				break;
		}
	}
}

void print(vector<Edge*>& result){
	for(vector<Edge*>::iterator iter=result.begin();iter!=result.end();++iter){
		Edge* e=*iter;
		cout<<e->start<<','<<e->end<<':'<<e->weight<<endl;
	}
}

int main(void){
	int n,m;
	cin>>n>>m;
	vector<Edge*> edges;
	for(int i=0;i<m;++i){
		int a,b,w;
		cin>>a>>b>>w;
		edges.push_back(new Edge(a,b,w));
	}
	vector<Edge*> result;
	kruskal(n,edges,result);
	print(result);
	return 0;
}
