#include <iostream>
#include "Board.h"
#include "Solution.h"


int main(int argc, char **argv)
{
    World world(Board("806547231").getHash());
    if (!world.solved)
        world.start();

    Board g(BoardSpace::goalBoard);
    Board b("806547231");

//    std::cout << b.getManhattan() << std::endl;
    return 0;
}

