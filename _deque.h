#include<vector>
#ifndef _deque_H
#define _deque_H
class _deque{ 
	private: std::vector<int> deq;
	public:
		void clear();
		void push_back(int v);
		void push_front(int v);
		void pop_back();
		void pop_front();
		int front();
		int back();
		int size();
		bool empty();
		auto begin();
		auto end();
};
void _deque::clear(){deq.clear();return;}
void _deque::push_back(int v){deq.push_back(v);return;}
void _deque::push_front(int v){deq.resize(deq.size()+1);for(int i=deq.size()-1;i>0;i--)deq[i]=deq[i-1]; deq[0]=v;return;}
void _deque::pop_back(){
	if(deq.size()) deq.pop_back();
	return;
}
void _deque::pop_front(){
	if(deq.size()) deq.erase(deq.begin());
	return;
}
int _deque::front(){if(deq.size()) return deq[0];}
int _deque::back(){if(deq.size()) return deq[deq.size()-1];}
int _deque::size(){return deq.size();}
bool _deque::empty(){return deq.size()==0;}
auto _deque::begin(){return deq.begin();}
auto _deque::end(){return deq.end();}
#endif
