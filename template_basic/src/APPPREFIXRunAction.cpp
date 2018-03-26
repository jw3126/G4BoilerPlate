#include <G4ios.hh>
#include <G4AccumulableManager.hh>
#include "APPPREFIXRunAction.h"

APPPREFIXRunAction::APPPREFIXRunAction(): G4UserRunAction(){}

APPPREFIXRunAction::~APPPREFIXRunAction(){}

void APPPREFIXRunAction::BeginOfRunAction(const G4Run* ){
}

void APPPREFIXRunAction::EndOfRunAction(const G4Run* ){

    G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
    accumulableManager->Merge();

}