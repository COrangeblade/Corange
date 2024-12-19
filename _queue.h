#include<vector>
#ifndef _queue_H
#define _queue_H
class _queue{
	private: std::vector<int> que;
	public:
		void push(int v);
		void pop();
		void clear();
		int front();
		int back();
		int size();
		bool empty();
		auto begin();
		auto end();
};
void _queue::push(int v){que.push_back(v);return;}
void _queue::pop(){
	if(que.size()) que.erase(que.begin());
	return;
}
void _queue::clear(){que.clear();return;}
int _queue::front(){if(que.size()) return que[0];}
int _queue::back(){if(que.size()) return que[que.size()-1];}
int _queue::size(){return que.size();}
bool _queue::empty(){return que.size()==0;}
auto _queue::begin(){return que.begin();}
auto _queue::end(){return que.end();}
#endif
