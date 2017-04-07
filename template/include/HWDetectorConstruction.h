#ifndef G4HELLOWORLD_HWDETECTORCONSTRUCTION_H
#define G4HELLOWORLD_HWDETECTORCONSTRUCTION_H


#include <G4VUserDetectorConstruction.hh>

class HWDetectorConstruction: public G4VUserDetectorConstruction {

public:
    HWDetectorConstruction(): G4VUserDetectorConstruction() {};
    ~HWDetectorConstruction(){};
    virtual G4VPhysicalVolume* Construct();
};


#endif //G4HELLOWORLD_HWDETECTORCONSTRUCTION_H
