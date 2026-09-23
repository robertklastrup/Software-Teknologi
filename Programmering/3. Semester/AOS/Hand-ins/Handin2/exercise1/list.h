#pragma once

template <typename Object>
class List {
public:
    virtual ~List() { };
	virtual int size() = 0;
	virtual bool empty() = 0;
	virtual void clear() = 0;

	virtual void push_front(const Object x) = 0;
	virtual void push_back(const Object x) = 0;
	virtual void push_middle(int pos, const Object x) = 0;


	virtual Object pop_front() = 0;
	virtual Object pop_back() = 0;
	virtual Object pop_middle(int pos) = 0;

	virtual Object find(const Object x) = 0;
	virtual void print() = 0;
	virtual void reverse()=0;
};

