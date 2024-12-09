#pragma once
#include<string>

class Production
{
private:
	std::string m_leftSide;
	std::string m_rightSide;
public:
	Production();
	Production(const std::string& leftSide,const std::string& rightSide);
	std::string GetLeftSide();
	std::string GetRightSide();
};

