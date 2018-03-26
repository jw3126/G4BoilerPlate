#include "APPPREFIXTrackInformation.h"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"    

G4ThreadLocal G4Allocator<APPPREFIXTrackInformation> *
                                   aTrackInformationAllocator = 0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
APPPREFIXTrackInformation::APPPREFIXTrackInformation()
  : G4VUserTrackInformation()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
APPPREFIXTrackInformation::APPPREFIXTrackInformation(const G4Track* aTrack)
  : G4VUserTrackInformation()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
APPPREFIXTrackInformation
::APPPREFIXTrackInformation(const APPPREFIXTrackInformation* aTrackInfo)
  : G4VUserTrackInformation()
{

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
APPPREFIXTrackInformation::~APPPREFIXTrackInformation()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
APPPREFIXTrackInformation& APPPREFIXTrackInformation
::operator =(const APPPREFIXTrackInformation& aTrackInfo)
{

    return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void APPPREFIXTrackInformation::Print() const
{

}

