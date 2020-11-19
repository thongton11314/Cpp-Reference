#ifndef _COMMAND_FACTORY_
#define _COMMAND_FACTORY_

#include "command.h"

class CommandFactory {
public:
    static Command * createCommand(ifstream);
};

#endif //!_COMMAND_FACTORY_