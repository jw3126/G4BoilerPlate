#include <G4VModularPhysicsList.hh>
#include <QBBC.hh>

#include <G4VisExecutive.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>

#include "APPPREFIXActionInitialization.hh"
#include "APPPREFIXDetectorConstruction.hh"


#ifdef G4MULTITHREADED

#include "G4MTRunManager.hh"

#else
#include "G4RunManager.hh"

#endif

void visualize(int argc, char **argv) {
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);

    G4VisManager *visManager = new G4VisExecutive;
    visManager->Initialize();
    G4UImanager *uiManager = G4UImanager::GetUIpointer();

    uiManager->ApplyCommand("/control/execute init.mac");

    ui->SessionStart();
    delete ui;
}


int main(int argc, char **argv) {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);

#ifdef G4MULTITHREADED
    G4MTRunManager *runManager = new G4MTRunManager;
    runManager->SetNumberOfThreads(4);
#else
    G4RunManager* runManager = new G4RunManager;
#endif


    APPPREFIXDetectorConstruction *detectorConstruction = new APPPREFIXDetectorConstruction();
    runManager->SetUserInitialization(detectorConstruction);

    G4VModularPhysicsList *physicsList = new QBBC;
    physicsList->SetVerboseLevel(0);
    runManager->SetUserInitialization(physicsList);

    APPPREFIXActionInitialization *actionInitialization = new APPPREFIXActionInitialization();
    runManager->SetUserInitialization(actionInitialization);

    runManager->Initialize();

    bool interactive = false;
    if ((argc == 1) && interactive) {
        visualize(argc, argv);
    } else {
        runManager->BeamOn(10);
    }

    delete runManager;

    return 0;
}