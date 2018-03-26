#ifndef APPPREFIXActionInitialization_h
#define APPPREFIXActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class APPPREFIXActionInitialization : public G4VUserActionInitialization {
public:
    APPPREFIXActionInitialization();

    virtual ~APPPREFIXActionInitialization();

    virtual void BuildForMaster() const;

    virtual void Build() const;

};

#endif

    