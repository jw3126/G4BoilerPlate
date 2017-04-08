#ifndef APPNAME_APPPREFIXACTIONINITIALIZATION_H
#define APPNAME_APPPREFIXACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>
#include "APPPREFIXPrimaryGeneratorAction.h"
#include "APPPREFIXEventAction.h"
#include "APPPREFIXSteppingAction.h"

class APPPREFIXActionInitialization: public G4VUserActionInitialization {

public:
    APPPREFIXActionInitialization() ;
    ~APPPREFIXActionInitialization();
    virtual void Build() const;
};


#endif //APPNAME_APPPREFIXACTIONINITIALIZATION_H
