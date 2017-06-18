#pragma once
template< class F, class S>
class Pair : public LinkedList<Pair<F,S>>
{
private:
	F key;
	S value;
public:
	//Constructors
	Pair();
	Pair(F pair1, S pair2);
	//Accessors
	F getFirst() const;
	S getSecond() const;
	//Mutator
	void setFirst(F value);
	void setSecond(S value);
};
//Default constructor
template<class F, class S>
Pair<F,S>::Pair()
{}
template<class F, class S>
Pair<F,S>::Pair(F pair1, S pair2)
{
	this->key = pair1;
	this->value = pair2;
}
//======================ACCESSORS======================//
template<class F, class S>
F Pair<F, S>::getFirst() const
{
	return this->key;
}

template<class F, class S>
S Pair<F, S>::getSecond() const
{
	return this->value;
}

//======================MUTATORS======================//
template<class F, class S>
void Pair<F, S>::setFirst(F value)
{
	this->key = value;
}

template<class F, class S>
void Pair<F, S>::setSecond(S value)
{
	this->value = value;
}

