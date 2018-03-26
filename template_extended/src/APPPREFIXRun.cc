
#include "APPPREFIXRun.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"

#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4THitsMap.hh"
#include "G4SystemOfUnits.hh"


APPPREFIXRun::APPPREFIXRun()
        : G4Run(),
          fCollIdTank(-1),
          fCollIdScoringVoxel(-1),
          fScoreScoringVoxel(0),
          fScoreTank(0.) {}


APPPREFIXRun::~APPPREFIXRun() {}

G4double APPPREFIXRun::GetSum(G4THitsMap<G4double> *evtMap) {
    G4double ret = 0;
    std::map<G4int, G4double *>::iterator itr;
    for (itr = evtMap->GetMap()->begin(); itr != evtMap->GetMap()->end(); itr++) {
        ret += *(itr->second);
    }
    return ret;
}

void APPPREFIXRun::RecordEvent(const G4Event *event) {
    if (fCollIdTank < 0) {
        fCollIdTank
                = G4SDManager::GetSDMpointer()->GetCollectionID("Tank/edep");
    }

    if (fCollIdScoringVoxel < 0) {
        fCollIdScoringVoxel
                = G4SDManager::GetSDMpointer()->GetCollectionID("ScoringVoxel/dose");
    }

    G4HCofThisEvent *HCE = event->GetHCofThisEvent();
    if (!HCE) return;


    G4THitsMap<G4double> *evtMap =
            static_cast<G4THitsMap<G4double> *>(HCE->GetHC(fCollIdTank));

    fScoreTank += GetSum(evtMap);


    evtMap = static_cast<G4THitsMap<G4double> *>(HCE->GetHC(fCollIdScoringVoxel));
    fScoreScoringVoxel += GetSum(evtMap);


    G4Run::RecordEvent(event);
}


void APPPREFIXRun::Merge(const G4Run *aRun) {
    const APPPREFIXRun *localRun = static_cast<const APPPREFIXRun *>(aRun);
    fScoreTank += localRun->fScoreTank;
    fScoreScoringVoxel += localRun->fScoreScoringVoxel;

    G4Run::Merge(aRun);
} 