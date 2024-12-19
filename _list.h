#include<vector>
#include<algorithm>
#ifndef list_H
#define list_H
class node{
	public:
		int pre=-1,id,next=-1;
		node(){}
		node(const int&_pre,const int&_id,const int&_next){pre=_pre,id=_id,next=_next;}
};
class _list{
	private: std::vector<node> l;
	public:
		void clear();
		void create();
		void insert(int id,int n);
		void push_front(int id);
		void push_back(int id);
		void erase(int id);
		void pop_front();
		void pop_back();
		int front();
		int back();
		int size();
		bool empty();
		auto begin();
		auto end();
};
void _list::clear(){l.clear();return;}
void _list::create(){l.resize(1);return;}
void _list::insert(int id,int n){
	l.push_back(node(l[id].pre,n,id));
	l[l[id].pre].next=l[id].pre=n;
	return;
}
void _list::push_front(int id){
	sort(l.begin(),l.end(),[](node a,node b){return a.pre<b.pre;});
	l.push_back(node(-1,id,l[0].id));l[0].pre=id;
	return;
}
void _list::push_back(int id){
	sort(l.begin(),l.end(),[](node a,node b){return a.next<b.next;});
	l.push_back(node(l[0].id,id,-1));l[0].next=id;
	return;
}
void _list::erase(int id){
	if(l.empty()) return;
	sort(l.begin(),l.end(),[](node a,node b){return a.id<b.id;});
	int p;
	for(int i=0;i<l.size();i++){
		if(l[i].id==id){
			p=i;break;
		}
	}
	if(l[p].pre!=-1) l[l[p].pre].next=l[p].next;
	if(l[p].next!=-1) l[l[p].next].pre=l[p].pre;
	l.erase(l.begin()+p);
	return;
}
void _list::pop_front(){
	if(l.empty()) return;
	if(l.size()==1){
		l.pop_back();
		return;
	}
	sort(l.begin(),l.end(),[](node a,node b){return a.pre>b.pre;});
	l[l[l.size()-1].pre].pre=-1;l.pop_back();
	return;
}
void _list::pop_back(){
	if(l.empty()) return;
	if(l.size()==1){
		l.pop_back();
		return;
	}
	sort(l.begin(),l.end(),[](node a,node b){return a.next>b.next;});
	l[l[l.size()-1].pre].next=-1;l.pop_back();
	return;
}
int _list::front(){
	if(l.size()){
		sort(l.begin(),l.end(),[](node a,node b){return a.pre<b.pre;});
		return l[0].id;
	}
}
int _list::back(){
	if(l.size()){
		sort(l.begin(),l.end(),[](node a,node b){return a.next<b.next;});
		return l[0].id;
	}
}
int _list::size(){return l.size();}
bool _list::empty(){return l.size()==0;}
auto _list::begin(){
	sort(l.begin(),l.end(),[](node a,node b){return a.pre<b.pre;});
	return l.begin();
}
auto _list::end(){
	sort(l.begin(),l.end(),[](node a,node b){return a.next>b.next;});
	return l.end();
}
#endif
