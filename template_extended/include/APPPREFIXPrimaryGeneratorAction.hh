
#ifndef APPPREFIXPrimaryGeneratorAction_h
#define APPPREFIXPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;

class G4Event;


class APPPREFIXPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    APPPREFIXPrimaryGeneratorAction();

    virtual ~APPPREFIXPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event *anEvent);

    const G4ParticleGun *GetParticleGun() const { return fParticleGun; }

private:
    G4ParticleGun *fParticleGun;
};


#endif