#include "APPPREFIXActionInitialization.hh"
#include "APPPREFIXRunAction.hh"
#include "APPPREFIXPrimaryGeneratorAction.hh"


APPPREFIXActionInitialization::APPPREFIXActionInitialization()
        : G4VUserActionInitialization() {}


APPPREFIXActionInitialization::~APPPREFIXActionInitialization() {}


void APPPREFIXActionInitialization::BuildForMaster() const {
    SetUserAction(new APPPREFIXRunAction);
}


void APPPREFIXActionInitialization::Build() const {
    SetUserAction(new APPPREFIXRunAction);
    SetUserAction(new APPPREFIXPrimaryGeneratorAction);
}