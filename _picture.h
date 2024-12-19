#include<vector>
#include<algorithm>
#include"_queue.h"
#ifndef _picture_H
#define _picture_H
class edge{
	public:
		int from,to,cost;
		edge(){}
		edge(const int &u,const int &v,const int &w=1){this->from=u,this->to=v,this->cost=w;}
};
class _picture{
	private: 
		std::vector<edge> pic;
		std::vector<int> vec,in;
		_queue q;int cnt=0,u;
	public:
		void clear();
		void create(int n);
		void add(int u,int v,int w=1);
		void del(int u,int v);
		void change(int u,int old_v,int new_v);
		bool find(int u,int v);
		std::vector<int> Tsort();
};
void _picture::clear(){pic.clear();return;}
void _picture::create(int n){in.clear();in.resize(n);return;}
void _picture::add(int u,int v,int w){pic.push_back(edge(u,v,w)),++in[v];return;}
void _picture::del(int u,int v){
	if(pic.empty()) return;
	for(int i=0;i<pic.size();i++) if(pic[i].from==u&&pic[i].to==v) pic.erase(pic.begin()+i);
	return;
}
void _picture::change(int u,int old_v,int new_v){
	if(pic.empty()) return;
	for(int i=0;i<pic.size();i++) if(pic[i].from==u&&pic[i].to==old_v) pic[i].to=new_v;
	return;
}
bool _picture::find(int u,int v){
	if(pic.empty()) return false;
	for(int i=0;i<pic.size();i++) if(pic[i].from==u&&pic[i].to==v) return true;
	return false;
}
std::vector<int> _picture::Tsort(){
	vec.resize(0);q.clear();cnt=0;
	for(int i=0;i<in.size();i++) if(!in[i]) q.push(i);
	while(q.size()){
		u=q.front();q.pop();++cnt;vec.push_back(u);
		for(int i=0;i<pic.size();i++){
			if(pic[i].from==u&&(!(--in[pic[i].to]))) q.push(pic[i].to);
		}
	}
	return vec;
}
#endif
