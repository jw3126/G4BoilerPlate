#include "APPPREFIXSteppingAction.h"

APPPREFIXSteppingAction::APPPREFIXSteppingAction(): G4UserSteppingAction(){}

APPPREFIXSteppingAction::~APPPREFIXSteppingAction(){}

void APPPREFIXSteppingAction::UserSteppingAction(const G4Step* step){
    step->GetTrack()->GetDynamicParticle()->DumpInfo(1);
}