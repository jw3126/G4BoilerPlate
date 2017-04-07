#include "APPPREFIXEventAction.h"

APPPREFIXEventAction::APPPREFIXEventAction():G4UserEventAction() {}
APPPREFIXEventAction::~APPPREFIXEventAction() {}

void APPPREFIXEventAction::BeginOfEventAction(const G4Event* ){
    G4cout << "begin of event" << G4endl;
}

void APPPREFIXEventAction::EndOfEventAction(const G4Event* ) {
    G4cout << "end of event" << G4endl;
}