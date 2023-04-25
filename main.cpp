#include "Shop.h"

int main()
{
    std::unique_ptr<SHOPManagement::Shop> pComputer(new SHOPManagement::Shop("Sezer Inc.", "Sezer Inc. is kind of computer shop for sale of computer components.",
                                                                             std::make_shared<SHOPManagement::Address>("Sezer Inc. Address", "Turkey", "Istanbul", "Taksim")));

    pComputer->run();

    return 0;
}
