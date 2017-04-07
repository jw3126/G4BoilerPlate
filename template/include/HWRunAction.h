#ifndef G4HELLOWORLD_HWRUNACTION_H
#define G4HELLOWORLD_HWRUNACTION_H


#include <G4UserRunAction.hh>
#include <G4ios.hh>

class HWRunAction : public G4UserRunAction{

public:
    HWRunAction();
    ~HWRunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};


#endif //G4HELLOWORLD_HWRUNACTION_H
