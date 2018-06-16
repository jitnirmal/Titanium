#pragma once


class IVisitor
{
public:
	IVisitor();
	virtual ~IVisitor();

	virtual void visit(IVisitable&) = 0;

};

class IVisitable
{
public:
	IVisitable();
	virtual ~IVisitable();

	void onVisitBy(IVisitor& visitor);
};

inline void IVisitable::onVisitBy(IVisitor& visitor)
{
	visitor.visit(*this);
}

