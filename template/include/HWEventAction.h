#ifndef G4HELLOWORLD_HWEVENTACTION_H
#define G4HELLOWORLD_HWEVENTACTION_H


#include <G4UserEventAction.hh>
#include "HWRunAction.h"

class HWEventAction : public G4UserEventAction{

public:
    HWEventAction();
    ~HWEventAction();
    virtual void BeginOfEventAction(const G4Event* );
    virtual void EndOfEventAction(const G4Event* );
};


#endif //G4HELLOWORLD_HWEVENTACTION_H
