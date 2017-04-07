#include <G4ios.hh>
#include "APPPREFIXRunAction.h"

APPPREFIXRunAction::APPPREFIXRunAction(): G4UserRunAction(){}

APPPREFIXRunAction::~APPPREFIXRunAction(){}

void APPPREFIXRunAction::BeginOfRunAction(const G4Run* ){
    G4cout << "Run begins" << G4endl;
}

void APPPREFIXRunAction::EndOfRunAction(const G4Run* ){
    G4cout << "Run ends" << G4endl;
}