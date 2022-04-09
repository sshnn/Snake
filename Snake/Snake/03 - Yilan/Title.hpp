#pragma once
#include "Widget.hpp"

class Title : public Widget
{
public:

	void setTitle(const sf::String& str);
	void setTitleSize(int size);

	virtual void isMouseOn(bool isMouseOn) override;
	virtual void draw(Window& window) override;

private:
	sf::Text m_title;
};

typedef std::shared_ptr<Title> titlePtr; // yaziptr