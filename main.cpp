#include "Engine.hpp"
#include <ctime>

int main(void) {
    srand(clock());
    Engine engine = Engine();
    engine.Base();
    return (0);
}
