#ifndef APPPREFIXDetectorConstruction_h
#define APPPREFIXDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;

class G4LogicalVolume;

class APPPREFIXDetectorConstruction : public G4VUserDetectorConstruction {
public:
    APPPREFIXDetectorConstruction();

    virtual ~APPPREFIXDetectorConstruction();

public:
    virtual G4VPhysicalVolume *Construct();

    virtual void ConstructSDandField();

private:

};

#endif