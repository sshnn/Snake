#pragma once
#include "BasicTypes.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include<vector>

class WidgetPanel : public Widget
{
public:
	WidgetPanel();
	void widgetImg(TexturePtr img);
	void setBackground(TexturePtr img, sf::IntRect rect);
	ButtonPtr addButton(sf::String title, float w = 150, float h = 75);

	virtual void draw(Window& window) override;
	

private:
	sf::Sprite	m_background;
	TexturePtr	m_widgetImg;
	int			m_height;
	int			m_width;

	// Inherited via Arac
	virtual void isMouseOn(bool isMouseOn) override;
};

typedef std::shared_ptr<WidgetPanel> widgetPanel;
typedef std::vector<widgetPanel> widgetPanelList;