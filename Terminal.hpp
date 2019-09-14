#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <ncurses.h>
#include <curses.h>
class Terminal {
    public:
        Terminal( void );
        Terminal( Terminal const &terminal );
        ~Terminal( void );
        Terminal &		operator=( Terminal const & terminal );
        int		getHeight( void ) const;
        int		getWidth( void ) const;
        void	update( void );
    private:
        int	height;
        int	width;

};


#endif //TERMINAL_HPP