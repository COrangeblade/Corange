#include<vector>
#include<cstdio>
#include<algorithm>
#include"_queue.h"
#ifndef _tree_H
#define _tree_H
#define max(a, b) a>=b? a:b
class node{
	public:
		int id,fa=-1;
		std::vector<int> ch;
		node(){}
		node(const int&_id,const int&_fa,const std::vector<int>&_ch){id=_id,fa=_fa,ch=_ch;}
};
class _tree{
	private: 
		std::vector<node> tr;
		std::vector<int> d;
	public:
		void create();
		void clear();
		void destroy();
		int depth(int id=0);
		void add(int id,int fa=0);
		void dfs_print(int id=0);
		void bfs_print(int id=0);
		void cut(int id);
		void graft(_tree t,int id=0);
};
void _tree::create(){tr.resize(1);}
void _tree::clear(){tr.clear();return;}
void _tree::destroy(){tr.clear();return;}
int _tree::depth(int id){
	if(tr[id].ch.empty()) return 0;
	d.resize(tr.size());d[0]=0;
	for(auto i:tr[id].ch){d[i]=depth(i);}
	for(auto i:tr[id].ch){d[id]=max(d[id],d[i]);}
	sort(d.begin(),d.end());
	return *(d.end()-1)+1;
}
void _tree::add(int fa,int id){
	node N=node(id,fa,std::vector<int>{});
	tr.push_back(N);tr[fa].ch.push_back(id);
	return;
}
void _tree::dfs_print(int id){
	printf("%d ",id);
	for(auto it:tr[id].ch) dfs_print(tr[it].id);
	return;
}
void _tree::bfs_print(int id){
	_queue q;q.push(id);
	while(!q.empty()){
		printf("%d ",q.front());
		for(auto it:tr[q.front()].ch) q.push(it);
		q.pop();
	}
	return;
}
void _tree::cut(int id){
	sort(tr[tr[id].fa].ch.begin(),tr[tr[id].fa].ch.end());
	tr[tr[id].fa].ch.erase(lower_bound(tr[tr[id].fa].ch.begin(),tr[tr[id].fa].ch.end(),id));
	tr[id].fa=-1;
	return;
}
void _tree::graft(_tree t,int id){
	const int l=tr.size();
	std::vector<node> dtr=(t.tr);
	for(int i=0;i<t.tr.size();i++) tr.push_back(dtr[i]);
	for(int i=l;i<tr.size();i++){
		tr[i].id+=l;
		if(tr[i].fa==-1) tr[i].fa=id;
		else tr[i].fa+=l;
		for(int j=0;j<tr[i].ch.size();j++) tr[i].ch[j]+=l;
	}
	tr[l].id=l;tr[id].ch.push_back(l);
	return;
}
#endif
