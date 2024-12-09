#include "Production.h"

Production::Production()
{
	/*empty*/
}

Production::Production(const std::string& leftSide,const std::string& rightSide):m_leftSide(leftSide),m_rightSide(rightSide)
{
	/*empty*/
}

std::string Production::GetLeftSide()
{
	return m_leftSide;
}

std::string Production::GetRightSide()
{
	return m_rightSide;
}
