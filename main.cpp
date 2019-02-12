#include "Shop.h"

using namespace SHOPManagement;

int main()
{
    Shop *pComputer = new Shop("SEZER Inc.", "SEZER Inc. is kind of computer shop for sale of computer components.",
                               new Address("SEZER Inc. Address", "Turkey", "Istanbul", "Taksim"));

    pComputer->run();

    delete pComputer;

    return 0;
}
