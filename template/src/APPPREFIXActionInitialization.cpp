#include "APPPREFIXActionInitialization.h"

APPPREFIXActionInitialization::APPPREFIXActionInitialization() : G4VUserActionInitialization(){}
APPPREFIXActionInitialization::~APPPREFIXActionInitialization() {}

void APPPREFIXActionInitialization::Build() const
{

    APPPREFIXPrimaryGeneratorAction* primaryGeneratorAction = new APPPREFIXPrimaryGeneratorAction();
    SetUserAction(primaryGeneratorAction);

    APPPREFIXEventAction* eventAction = new APPPREFIXEventAction();
    SetUserAction(eventAction);

    APPPREFIXSteppingAction* steppingAction = new APPPREFIXSteppingAction();
    SetUserAction(steppingAction);

    APPPREFIXRunAction* runAction = new APPPREFIXRunAction();
    SetUserAction(runAction);

}