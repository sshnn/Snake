#include "Game.hpp"
#include <iostream>
#include "Frame.hpp"

Frame frame;

Game::Game()
{
	m_fps = 60;
	m_frameTime = sf::seconds(1.0f / m_fps);
	m_isContinue = false;
	
}

Game::~Game()
{
}

void Game::setFps(int fps)
{
}
void Game::addCasing(sf::String fName, bool background)
{
	if (m_casingList.count(fName) == 0)
	{
		TexturePtr newCasing = std::make_shared<sf::Texture>();
		sf::String path = "./imgs/" + fName;
		std::filesystem::path fpath(path);
		
		if (background)
		{
			if (newCasing->loadFromFile(fpath))
			{
				m_casingList[fName] = newCasing;
			}
		}
		else
		{
			sf::Image image;
			if (image.loadFromFile(fpath))
			{
				auto color = image.getPixel(0, 0);
				image.createMaskFromColor(color);
				newCasing->loadFromImage(image);
				m_casingList[fName] = newCasing;
			}
		}

	}

}
void Game::setGame()
{
	frame.set(m_width, 20.0f);
	m_snake = std::make_shared <Snake>(20.0f);
	m_bait = Square::makeSquare(20.0f);
	m_bait->m_shape.setFillColor(sf::Color::Blue);
	

	addCasing("hero.png",false);


	makeBait();
	loadInterfaces();

	bindEvent();

}
void Game::loadInterfaces()
{
	m_font = std::make_shared<sf::Font>();
	if (!m_font->loadFromFile("./font/alev.ttf"))
	{
		std::cout << "font not found...\n";
	}
	addCasing("Button.png");
	addCasing("Windows.png");
	auto newPanel = std::make_shared<WidgetPanel>();
	newPanel->setFont(m_font);
	newPanel->widgetImg(m_casingList["Button.png"]);
	newPanel->setBackground(m_casingList["Windows.png"], sf::IntRect(sf::Vector2i(799, 933), sf::Vector2i(550, 742)));
	

	auto btnNewGame = newPanel->addButton("Start");
	auto btnList = newPanel->addButton("List");
	auto btnExit = newPanel->addButton("Exit");

	btnExit->addClickFunc([&] {
		this->closeGame();
		});

	btnNewGame->addClickFunc([&] {
		m_panelList[0]->visibility(false);
		m_isContinue = true;
		});

	float x = (m_width - newPanel->getSize().x) / 2;
	float y = (m_height - newPanel->getSize().y) / 2;
	newPanel->setPosition(sf::Vector2f(x, y));
	
	m_panelList.push_back(newPanel);
}
void Game::bindEvent()
{
	m_window.addMoveFunc(
		std::bind(&Game::mouseMove, this, std::placeholders::_1, std::placeholders::_2));

	m_window.addMouseClick(
		std::bind(&Game::mouseClick, this,std::placeholders::_1));
	
	m_window.addMouseRelase(
		std::bind(&Game::mouseRelase, this, std::placeholders::_1));

	m_window.addKeyPress(
		std::bind(&Game::keyboardPress, this, std::placeholders::_1));

}
void Game::mouseMove(int x, int y)
{
	for (auto next : m_panelList)
	{
		if(next->isInside(x,y))
			next->mouseMove(x, y);

	}
		
	
}
void Game::mouseClick(sf::Event::MouseButtonEvent event)
{
	int x = event.x;
	int y = event.y;
	for (auto next : m_panelList)
	{
		if (next->isInside(x, y))
			next->mouseClick(event);

	}
}
void Game::mouseRelase(sf::Event::MouseButtonEvent event)
{
	int x = event.x;
	int y = event.y;
	for (auto next : m_panelList)
	{
		next->mouseRelase(event);
	}
}
void Game::keyboardPress(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
	{
		m_snake->changeDirection(DIRECTION::DIRECTION_LEFT);
	}
	if (key == sf::Keyboard::Right)
	{
		m_snake->changeDirection(DIRECTION::DIRECTION_RIGHT);
	}
	if (key == sf::Keyboard::Down)
	{
		m_snake->changeDirection(DIRECTION::DIRECTION_DOWN);
	}
	if (key == sf::Keyboard::Up)
	{
		m_snake->changeDirection(DIRECTION::DIRECTION_UP);
	}if (key == sf::Keyboard::Space)
		m_snake->addToTail();
}

void Game::closeGame()
{
	m_window.close();
}

void Game::makeBait()
{
	auto cizgiSayisi = frame.m_lineNumber;
	m_bait->m_position.x = (rand() % cizgiSayisi) * m_bait->m_size;
	m_bait->m_position.y = (rand() % cizgiSayisi) * m_bait->m_size;

}

bool Game::isBaitExist()
{
	return m_snake->isBeat(m_bait->m_position);
}

void Game::startGame(unsigned int w, unsigned int h)
{
	m_width = w;
	m_height = h;
	m_window.create(w, h, "Snake Game");

	setGame();

	restartTimer();
	while (m_window.isOpen())
	{
		m_window.eventControl();
		
		if (m_timer.getElapsedTime() >= m_frameTime)
		{
			drawingFunc();
			restartTimer();
		}
		else
		{
			sf::sleep(m_frameTime - m_timer.getElapsedTime());
		}

	}
}

void Game::drawingFunc()
{
	m_window.startDrawing();
	

	for (auto next : m_panelList)
	{
		next->draw(m_window);
	}

	if (m_isContinue)
	{

		if (m_snake->collision())
			m_isContinue = false;
		if (isBaitExist())
		{
			m_snake->addToTail();
			makeBait();
		}

		m_snake->move();
		frame.draw(m_window);
		m_bait->draw(m_window);
		m_snake->draw(m_window);

		
	}

	m_window.endDrawing();
}



void Game::restartTimer()
{
	m_timer.restart();
}
