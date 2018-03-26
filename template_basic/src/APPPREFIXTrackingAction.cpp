#include "APPPREFIXTrackingAction.h"
#include "APPPREFIXTrajectory.hh"
#include "APPPREFIXTrackInformation.h"

#include "G4TrackingManager.hh"
#include "G4Track.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
APPPREFIXTrackingAction::APPPREFIXTrackingAction()
:G4UserTrackingAction()
{;}

void APPPREFIXTrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 
void APPPREFIXTrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
  if(secondaries)
  {
    APPPREFIXTrackInformation* info = 
      (APPPREFIXTrackInformation*)(aTrack->GetUserInformation());
    size_t nSeco = secondaries->size();
    if(nSeco>0)
    {
      for(size_t i=0;i<nSeco;i++)
      { 
        APPPREFIXTrackInformation* infoNew = new APPPREFIXTrackInformation(info);
        (*secondaries)[i]->SetUserInformation(infoNew);
      }
    }
  }
}


