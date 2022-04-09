#pragma once
#include "BasicTypes.hpp"
#include "Window.hpp"
#include "WidgetPanel.hpp"
#include "Snake.hpp"
class Game
{
public:
	Game();
	~Game();
	void setFps(int fps);
	void startGame(unsigned int width = 600,unsigned int heihgt = 600);
	void drawingFunc();
	void addCasing(sf::String fName, bool background = true); // kaplama ekle
	void setGame();
	void loadInterfaces();
	void bindEvent(); // olaylar� ba�la
	void mouseMove(int x, int y);
	void mouseClick(sf::Event::MouseButtonEvent event);
	void mouseRelase(sf::Event::MouseButtonEvent event);
	void keyboardPress(sf::Keyboard::Key tus);
	void closeGame();
	void makeBait(); // yem �ret
	bool isBaitExist();

private:

	void restartTimer();

	squarePtr			m_bait;
	snakePtr			m_snake;
	sf::Time			m_time; // ge�en d�re
	sf::Time			m_frameTime; // �erceve s�resi
	sf::Clock			m_timer; // m_saat
	Window				m_window;
	textureMap			m_casingList; // m_aracKaplamaListesi
	int					m_fps;
	widgetPanelList		m_panelList;
	FontPtr				m_font;
	int					m_width;
	int					m_height;
	bool				m_isContinue;
};