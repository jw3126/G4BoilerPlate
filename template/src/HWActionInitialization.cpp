#include "HWActionInitialization.h"

HWActionInitialization::HWActionInitialization() : G4VUserActionInitialization(){}
HWActionInitialization::~HWActionInitialization() {}

void HWActionInitialization::Build() const
{

    HWPrimaryGeneratorAction* primaryGeneratorAction = new HWPrimaryGeneratorAction();
    SetUserAction(primaryGeneratorAction);

    HWEventAction* eventAction = new HWEventAction();
    SetUserAction(eventAction);

    HWSteppingAction* steppingAction = new HWSteppingAction();
    SetUserAction(steppingAction);

    HWRunAction* runAction = new HWRunAction();
    SetUserAction(runAction);

}