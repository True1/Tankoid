
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////
/// Function called whenever one of our windows receives a message
///
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \param Instance : Instance of the application
///
/// \return Error code
///
////////////////////////////////////////////////////////////
INT WINAPI WinMain(HINSTANCE Instance, HINSTANCE, LPSTR, INT)
{
   // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Events");

    // Get a reference to the input manager associated to our window, and store it for later use
    const sf::Input& Input = App.GetInput();

    // Start main loop
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

        // Display window on screen
        App.Display();
    }
    return EXIT_SUCCESS;
}
