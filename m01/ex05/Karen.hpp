#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>
# include <map>

class Karen
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	std::map<std::string, Karen::f(void)> m;
public:
	Karen();
	~Karen();
	void complain( std::string level );
};

#endif KAREN_HPP