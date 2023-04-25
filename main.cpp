#include "Shop.h"

int main()
{
    std::shared_ptr<SHOPManagement::Shop> pComputer(new SHOPManagement::Shop("SEZER Inc.", "SEZER Inc. is kind of computer shop for sale of computer components.",
                                                                             new SHOPManagement::Address("SEZER Inc. Address", "Turkey", "Istanbul", "Taksim")));

    pComputer->run();

    return 0;
}
