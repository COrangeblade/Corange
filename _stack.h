#include<vector>
#ifndef _stack_H
#define _stack_H
class _stack{
	private: std::vector<int> sta;
	public:
		void clear();
		void pop();
		void push(int v);
		int top();
		int size();
		bool empty();
		auto begin();
		auto end();
};
void _stack::clear(){sta.clear();return;}
void _stack::pop(){
	if(sta.size()) sta.pop_back();
	return;
}
void _stack::push(int v){sta.push_back(v);return;}
int _stack::top(){if(sta.size()) return sta[sta.size()-1];}
int _stack::size(){return sta.size();}
bool _stack::empty(){return sta.size()==0;}
auto _stack::begin(){return sta.begin();}
auto _stack::end(){return sta.end();}
#endif
