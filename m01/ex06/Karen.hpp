#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>

enum DebugLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

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
	DebugLevel debugLevel;
public:
	Karen();
	~Karen();
	void setDebugLevel(std::string level);
	void complain( std::string level );
};

#endif