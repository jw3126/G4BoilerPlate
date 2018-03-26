
#include "APPPREFIXRunAction.hh"
#include "APPPREFIXRun.hh"
#include "APPPREFIXPrimaryGeneratorAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


APPPREFIXRunAction::APPPREFIXRunAction()
        : G4UserRunAction() {
    const G4double milligray = 1.e-3 * gray;
    const G4double microgray = 1.e-6 * gray;
    const G4double nanogray = 1.e-9 * gray;
    const G4double picogray = 1.e-12 * gray;

    new G4UnitDefinition("milligray", "milliGy", "Dose", milligray);
    new G4UnitDefinition("microgray", "microGy", "Dose", microgray);
    new G4UnitDefinition("nanogray", "nanoGy", "Dose", nanogray);
    new G4UnitDefinition("picogray", "picoGy", "Dose", picogray);
}


APPPREFIXRunAction::~APPPREFIXRunAction() {}


G4Run *APPPREFIXRunAction::GenerateRun() { return new APPPREFIXRun; }


void APPPREFIXRunAction::BeginOfRunAction(const G4Run *run) {
    G4cout << "### Run " << run->GetRunID() << " start." << G4endl;

    G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}


void APPPREFIXRunAction::EndOfRunAction(const G4Run *g4run) {
    G4int nofEvents = g4run->GetNumberOfEvent();
    if (nofEvents == 0) return;

    const APPPREFIXPrimaryGeneratorAction *generatorAction
            = static_cast<const APPPREFIXPrimaryGeneratorAction *>(
                    G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
    G4String partName;
    if (generatorAction) {
        G4ParticleDefinition *particle
                = generatorAction->GetParticleGun()->GetParticleDefinition();
        partName = particle->GetParticleName();
    }

    const APPPREFIXRun *run = static_cast<const APPPREFIXRun *>(g4run);

    if (IsMaster()) {
        G4cout
                << G4endl
                << "Master:"
                << G4endl
                << "  Tank: " << run->GetScoreTank() << G4endl
                << "  ScoringVoxel: " << run->GetScoreScoringVoxel() << G4endl;
    } else {
        G4cout
                << G4endl
                << "Worker:"
                << G4endl
                << "  Tank: " << run->GetScoreTank() << G4endl
                << "  ScoringVoxel: " << run->GetScoreScoringVoxel() << G4endl;
    }
}