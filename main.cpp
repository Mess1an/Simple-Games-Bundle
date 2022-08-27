#include "MainMenu.h"
#include "RockPaperScissors.h"

int main() {
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow menuWindow(VideoMode(resolution.x, resolution.y), "Simple Games Bundle");
	MainMenu mainMenu(resolution.x, resolution.y);
	RockPaperScissors rockPaperScissors(resolution.x, resolution.y);

	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	while (menuWindow.isOpen())
	{
		Event event;
		
		while (menuWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				menuWindow.close();
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.moveUp();
					break;
				}

				if (event.key.code == Keyboard::Down)
				{
					mainMenu.moveDown();
					break;
				}

				// select game
				if (event.key.code == Keyboard::Return)
				{
					int x = mainMenu.mainMenuPressed();
					if (x == 0)
					{
						RenderWindow RPS(VideoMode(resolution.x, resolution.y), "Rock Paper Scissors");
						while (RPS.isOpen())
						{
							Event eventRPS;
							while (RPS.pollEvent(eventRPS))
							{
								switch (eventRPS.type)
								{
								case Event::Closed:
									RPS.close();
								case Event::KeyPressed:
									if (eventRPS.key.code == Keyboard::Left)
									{
										rockPaperScissors.moveLeft();
										break;
									}

									if (eventRPS.key.code == Keyboard::Right)
									{
										rockPaperScissors.moveRight();
										break;
									}

									if (eventRPS.key.code == Keyboard::Return)
									{
										rockPaperScissors.RPSPressed(resolution);
										break;
									}

									if (eventRPS.key.code == Keyboard::Escape)
									{
										RPS.close();
									}
								default:
									break;
								}
								RPS.clear();
								rockPaperScissors.draw(RPS);
								RPS.display();
							}
						}
					}

					if (x == 1)
					{
						RenderWindow TTT(VideoMode(resolution.x, resolution.y), "Tic Tac Toe");
						while (TTT.isOpen())
						{
							Event eventTTT;
							while (TTT.pollEvent(eventTTT))
							{
								if (eventTTT.type == Event::Closed)
								{
									TTT.close();
								}

								if (eventTTT.type == Event::KeyPressed)
								{
									if (eventTTT.key.code == Keyboard::Escape)
									{
										TTT.close();
									}
								}
							}
							TTT.clear();
							TTT.display();
						}
					}

					if (x == 2)
					{
						RenderWindow GtN(VideoMode(resolution.x, resolution.y), "Guess the Number");
						while (GtN.isOpen())
						{
							Event eventGtN;
							while (GtN.pollEvent(eventGtN))
							{
								if (eventGtN.type == Event::Closed)
								{
									GtN.close();
								}

								if (eventGtN.type == Event::KeyPressed)
								{
									if (eventGtN.key.code == Keyboard::Escape)
									{
										GtN.close();
									}
								}
							}
							GtN.clear();
							GtN.display();
						}
					}

					if (x == 3)
					{
						menuWindow.close();
					}
				}

				if (event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
				}
			default:
				break;
			}
		}
		menuWindow.clear();
		mainMenu.draw(menuWindow);
		menuWindow.display();
	}
	return 0;
}