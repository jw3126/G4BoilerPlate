#ifndef G4HELLOWORLD_HWPRIMARYGENERATORACTION_H
#define G4HELLOWORLD_HWPRIMARYGENERATORACTION_H


#include <G4ParticleTable.hh>
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "globals.hh"
#include "G4SystemOfUnits.hh"

class HWPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {

public:
    HWPrimaryGeneratorAction();
    ~HWPrimaryGeneratorAction();
    virtual void GeneratePrimaries(G4Event* );

private:
    G4ParticleGun* fParticleGun;
};


#endif //G4HELLOWORLD_HWPRIMARYGENERATORACTION_H
