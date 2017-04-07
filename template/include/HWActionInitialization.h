#ifndef G4HELLOWORLD_HWACTIONINITIALIZATION_H
#define G4HELLOWORLD_HWACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>
#include "HWPrimaryGeneratorAction.h"
#include "HWEventAction.h"
#include "HWSteppingAction.h"

class HWActionInitialization: public G4VUserActionInitialization {

public:
    HWActionInitialization() ;
    virtual ~HWActionInitialization();
    virtual void Build() const;
};


#endif //G4HELLOWORLD_HWACTIONINITIALIZATION_H
