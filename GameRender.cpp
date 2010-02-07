#include "GameRender.h"
#include <iostream>

GameRender::GameRender(int width, int height) : 
	worldMap(width, height, width * 4, height * 4), 
	mainView(width, height, width, height)
{
	std::cout << "Creating window...";

	gameWindow.Create(sf::VideoMode(width, height), "Tankoid");
	mainView.setGlobalMap(&worldMap);

	std::cout << "success" << std::endl;

	if(worldMap.setLandscapeImage()) std::cout << "loaded background" << std::endl;
};

GameRender::~GameRender()
{
	std::cout << "Destroying window...";
	gameWindow.Close();
	std::cout << "success" << std::endl;
};

void GameRender::mainLooP()
{
	std::cout << "Getting input...";
	   // Get a reference to the input manager associated to our window, and store it for later use
    const sf::Input& Input = gameWindow.GetInput();
	std::cout << "success" << std::endl;
	gameWindow.SetFramerateLimit(60);


    // Start main loop
	std::cout << "starting main loop..." << std::endl;
    while (gameWindow.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (gameWindow.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                gameWindow.Close();

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                gameWindow.Close();
        }

        // Move the view using arrow keys
        float Offset = 200.f * gameWindow.GetFrameTime();
        if (Input.IsKeyDown(sf::Key::Up))    mainView.move( 0,      -Offset);
        if (Input.IsKeyDown(sf::Key::Down))  mainView.move( 0,       Offset);
        if (Input.IsKeyDown(sf::Key::Left))  mainView.move(-Offset,  0);
        if (Input.IsKeyDown(sf::Key::Right)) mainView.move( Offset,  0);

		
		mainView.setWindow(gameWindow);
		gameWindow.Clear();

		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				sf::Sprite& reg = mainView.getRegionSprite(i, j);
				gameWindow.Draw(reg);
			}
		}


        // Display window on screen
        gameWindow.Display();
    }
}