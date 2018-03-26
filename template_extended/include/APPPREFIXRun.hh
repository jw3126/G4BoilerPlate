#ifndef APPPREFIXRun_h
#define APPPREFIXRun_h 1

#include <G4THitsMap.hh>
#include "G4Run.hh"
#include "globals.hh"


class APPPREFIXRun : public G4Run {
public:
    APPPREFIXRun();

    virtual ~APPPREFIXRun();

    virtual void RecordEvent(const G4Event *);

    virtual void Merge(const G4Run *);

    G4double GetSum(G4THitsMap<G4double> *evtMap);

public:

private:
    G4int fCollIdTank;
public:
    G4double GetScoreScoringVoxel() const {
        return fScoreScoringVoxel;
    }

    G4double GetScoreTank() const {
        return fScoreTank;
    }

private:
    G4int fCollIdScoringVoxel;
    G4double fScoreScoringVoxel;
    G4double fScoreTank;

};


#endif

    