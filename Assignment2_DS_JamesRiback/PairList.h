#ifndef PAIRLIST_H
#define PAIRLIST_H
#include "LinkedList.h"
#include "Pair.h"
using namespace std;
template<class F , class S>
class PairList : public Pair<F,S>
{
private:
	LinkedList <Pair<F,S>> pList;
public:
	PairList();
};
#endif

template<class F, class S>
PairList<F, S>::PairList()
{

}
