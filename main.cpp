#include <iostream>
#include "Board.h"
#include "Solution.h"


int main(int argc, char **argv)
{
    Solution world(Board("806547231").calculateHash());
    world.start();

    return 0;
}

