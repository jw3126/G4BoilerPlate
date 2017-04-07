#include <G4ios.hh>
#include "HWRunAction.h"

HWRunAction::HWRunAction(): G4UserRunAction(){}

HWRunAction::~HWRunAction(){}

void HWRunAction::BeginOfRunAction(const G4Run* ){
    G4cout << "Run begins" << G4endl;
}

void HWRunAction::EndOfRunAction(const G4Run* ){
    G4cout << "Run ends" << G4endl;
}