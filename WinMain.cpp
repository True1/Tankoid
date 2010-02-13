////////////////////////////////////////////////////////////
//Lib Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////
//My Headers
////////////////////////////////////////////////////////////
#include "LocalView.h"

////////////////////////////////////////////////////////////
/// Entry point of application
/// \return Error code
////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{	

	MapNet myMap(1);
	LocalView myView(&myMap);

    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "Tankoid Views");
	App.SetFramerateLimit(60);
	App.UseVerticalSync(true);

	 // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }

        // Move the view using arrow keys
        float Offset = 200.f * App.GetFrameTime();
        if (App.GetInput().IsKeyDown(sf::Key::Up))    myView.move( 0,      -Offset);
        if (App.GetInput().IsKeyDown(sf::Key::Down))  myView.move( 0,       Offset);
        if (App.GetInput().IsKeyDown(sf::Key::Left))  myView.move(-Offset,  0);
        if (App.GetInput().IsKeyDown(sf::Key::Right)) myView.move( Offset,  0);

        // Set the view
        App.SetView(myView.originalView);

        // Clear screen
        App.Clear();



		myView.draw(App);



        // Finally, display rendered frame on screen
        App.Display();
    }



    return EXIT_SUCCESS;
}
