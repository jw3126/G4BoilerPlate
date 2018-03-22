
#ifndef APPNAME_APPPREFIXTrackInformation_h
#define APPNAME_APPPREFIXTrackInformation_h 1

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4Track.hh"
#include "G4Allocator.hh"
#include "G4VUserTrackInformation.hh"

class APPPREFIXTrackInformation : public G4VUserTrackInformation 
{
public:
  APPPREFIXTrackInformation();
  APPPREFIXTrackInformation(const G4Track* aTrack);
  APPPREFIXTrackInformation(const APPPREFIXTrackInformation* aTrackInfo);
  virtual ~APPPREFIXTrackInformation();
   
  inline void *operator new(size_t);
  inline void operator delete(void *aTrackInfo);

  APPPREFIXTrackInformation& operator =(const APPPREFIXTrackInformation& right);
  
  virtual void Print() const;

public:

private:

};

extern G4ThreadLocal
 G4Allocator<APPPREFIXTrackInformation> * aTrackInformationAllocator;

inline void* APPPREFIXTrackInformation::operator new(size_t)
{
  if(!aTrackInformationAllocator)
    aTrackInformationAllocator = new G4Allocator<APPPREFIXTrackInformation>;
  return (void*)aTrackInformationAllocator->MallocSingle();
}

inline void APPPREFIXTrackInformation::operator delete(void *aTrackInfo)
{ aTrackInformationAllocator->FreeSingle((APPPREFIXTrackInformation*)aTrackInfo);}

#endif

