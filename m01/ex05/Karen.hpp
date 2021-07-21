#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>

class Karen;
typedef void (Karen::*KarenFunct)(void);

class Karen
{
private:
	KarenFunct kFunctArray[5];
	std::string levels[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void undefined( void );
public:
	Karen();
	~Karen();
	void complain( std::string level );
};

#endif