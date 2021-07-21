#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>
# include <map>

class Karen;
typedef void (Karen::*KarenFunct)(void);

enum DebugLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Karen
{
private:
	std::map<std::string,  KarenFunct> kFunctArray;
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	DebugLevel debugLevel;
public:
	Karen();
	~Karen();
	void complain( std::string level );
	void setDebugLevel( std::string level );
};

#endif