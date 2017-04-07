#ifndef G4HELLOWORLD_HWSTEPPINGACTION_H
#define G4HELLOWORLD_HWSTEPPINGACTION_H

#include <G4UserSteppingAction.hh>
#include <G4ios.hh>
#include "G4Step.hh"
#include "G4StepPoint.hh"


class HWSteppingAction : public G4UserSteppingAction {

public:
    HWSteppingAction();
    ~HWSteppingAction();
    virtual void UserSteppingAction(const G4Step* step);
};


#endif //G4HELLOWORLD_HWSTEPPINGACTION_H
