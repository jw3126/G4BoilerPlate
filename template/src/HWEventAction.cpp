#include "HWEventAction.h"

HWEventAction::HWEventAction():G4UserEventAction() {}
HWEventAction::~HWEventAction() {}

void HWEventAction::BeginOfEventAction(const G4Event* ){
    G4cout << "begin of event" << G4endl;
}

void HWEventAction::EndOfEventAction(const G4Event* ) {
    G4cout << "end of event" << G4endl;
}