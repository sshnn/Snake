#pragma once
#include<sfml/Graphics.hpp>
#include "BasicTypes.hpp"
class Window
{
public:
	Window();
	void create(unsigned int width, unsigned int height, sf::String title);
	void startDrawing();
	void endDrawing();
	bool isOpen();
	void eventControl();
	void draw(sf::Drawable& sekil);
	void addMoveFunc(mouseMoveFunc newFunc); // hareket fonk
	void addMouseClick(mouseClickFunc newFunc); // fare basýlma fonk
	void addMouseRelase(mouseClickFunc newFunc); // fare býrakma
	void addKeyPress(KeyFunc newFunc); // tus basilma

	void close();
private:
	mouseMoveFuncList	m_addMoveFuncList;
	mouseClickFuncList	addMouseClickList;
	mouseClickFuncList	m_addMouseRelaseList;
	KeyFuncList	m_addKeyPressList;
	sf::RenderWindow m_window;
};

