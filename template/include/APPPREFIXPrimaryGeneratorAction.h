#ifndef APPNAME_APPPREFIXPRIMARYGENERATORACTION_H
#define APPNAME_APPPREFIXPRIMARYGENERATORACTION_H


#include <G4ParticleTable.hh>
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "globals.hh"
#include "G4SystemOfUnits.hh"

class APPPREFIXPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {

public:
    APPPREFIXPrimaryGeneratorAction();
    ~APPPREFIXPrimaryGeneratorAction();
    virtual void GeneratePrimaries(G4Event* );

private:
    G4ParticleGun* fParticleGun;
};


#endif //APPNAME_APPPREFIXPRIMARYGENERATORACTION_H
