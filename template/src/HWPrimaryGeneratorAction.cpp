#include "HWPrimaryGeneratorAction.h"

HWPrimaryGeneratorAction::HWPrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(){
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* gamma = particleTable -> FindParticle("gamma");

    G4ParticleMomentum momentumDirection = G4ParticleMomentum(1,0,0);
    G4ThreeVector position = G4ThreeVector(-1*m, 0, 0);

    fParticleGun->SetParticleDefinition(gamma);
    fParticleGun->SetParticleEnergy(7*MeV);
    fParticleGun->SetParticleMomentumDirection(momentumDirection);
    fParticleGun->SetParticlePosition(position);
}

HWPrimaryGeneratorAction::~HWPrimaryGeneratorAction() {delete fParticleGun;}

void HWPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleGun->GeneratePrimaryVertex(anEvent);
}