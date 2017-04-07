#include "G4Box.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "HWDetectorConstruction.h"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

G4VPhysicalVolume* HWDetectorConstruction::Construct() {

    // world
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* mediumWorld = nist->FindOrBuildMaterial("G4_AIR");

    // logical
    G4Box* solidWorld = new G4Box("solidWorld", 1*m, 2*m, 3*m);
    G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, mediumWorld, "logicalWorld");

    // physical
    G4RotationMatrix* pRot = nullptr;
    const G4ThreeVector& tlate = G4ThreeVector();
    G4LogicalVolume* pCurrentLogical = logicalWorld;
    const G4String& pName = "physicalWorld";
    G4LogicalVolume* pMotherLogical = nullptr; // the world has no mother volume
    G4bool pMany = false; // boolean solid?
    G4int pCopyNo = 0;  // multiple copies of volume in physical world?
    const G4bool pSurfChk = true;  // check overlaps?

    G4VPhysicalVolume* physicalWorld =
            new G4PVPlacement(pRot,
                              tlate,
                              pCurrentLogical,
                              pName,
                              pMotherLogical,
                              pMany,
                              pCopyNo,
                              pSurfChk);

    // phantom
    G4Material* mediumPhantom = nist->FindOrBuildMaterial("G4_WATER");

    G4Box* solidPhantom = new G4Box("solidPhantom", 0.5*m, 1*m, 1.5*m);
    G4LogicalVolume* logicalPhantom = new G4LogicalVolume(solidPhantom, mediumPhantom, "logicalPhantom");

    pCurrentLogical = logicalPhantom;
    pMotherLogical = logicalWorld;

    new G4PVPlacement(pRot,
                      tlate,
                      pCurrentLogical,
                      "physicalPhantom",
                      pMotherLogical,
                      pMany,
                      pCopyNo,
                      pSurfChk);


    return physicalWorld;
}