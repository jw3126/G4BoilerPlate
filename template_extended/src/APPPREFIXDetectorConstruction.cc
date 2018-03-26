
#include <G4GDMLParser.hh>
#include "APPPREFIXDetectorConstruction.hh"

#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSDoseDeposit.hh"

APPPREFIXDetectorConstruction::APPPREFIXDetectorConstruction()
        : G4VUserDetectorConstruction() {}

G4VPhysicalVolume *APPPREFIXDetectorConstruction::Construct() {

    G4String geometryPath = "geometry.gdml";
    G4GDMLParser parser;
    parser.Read(geometryPath, false);
    G4VPhysicalVolume *physicalWorld = parser.GetWorldVolume();
    G4bool hasOverlaps = physicalWorld->CheckOverlaps();
    assert(!hasOverlaps);
    assert(physicalWorld != nullptr);
    return physicalWorld;
}

APPPREFIXDetectorConstruction::~APPPREFIXDetectorConstruction() {}


void APPPREFIXDetectorConstruction::ConstructSDandField() {
    G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

    G4MultiFunctionalDetector *tank = new G4MultiFunctionalDetector("Tank");
    G4SDManager::GetSDMpointer()->AddNewDetector(tank);
    G4VPrimitiveScorer *primitiv1 = new G4PSEnergyDeposit("edep");
    tank->RegisterPrimitive(primitiv1);
    SetSensitiveDetector("Tank", tank);

    G4MultiFunctionalDetector *scoringVoxel = new G4MultiFunctionalDetector("ScoringVoxel");
    G4SDManager::GetSDMpointer()->AddNewDetector(scoringVoxel);
    G4VPrimitiveScorer *primitiv2 = new G4PSDoseDeposit("dose");
    scoringVoxel->RegisterPrimitive(primitiv2);
    SetSensitiveDetector("ScoringVoxel", scoringVoxel);
}