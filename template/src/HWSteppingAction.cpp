#include "HWSteppingAction.h"

HWSteppingAction::HWSteppingAction(): G4UserSteppingAction(){}

HWSteppingAction::~HWSteppingAction(){}

void HWSteppingAction::UserSteppingAction(const G4Step* step){
    step->GetTrack()->GetDynamicParticle()->DumpInfo(1);
}