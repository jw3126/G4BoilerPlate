#ifndef APPPREFIXRunAction_h
#define APPPREFIXRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;


class APPPREFIXRunAction : public G4UserRunAction {
public:
    APPPREFIXRunAction();

    virtual ~APPPREFIXRunAction();

    virtual G4Run *GenerateRun();

    virtual void BeginOfRunAction(const G4Run *);

    virtual void EndOfRunAction(const G4Run *);
};


#endif