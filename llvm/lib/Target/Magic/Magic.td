include "llvm/Target/Target.td"
include "MagicRegisterInfo.td"
include "MagicInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def MagicInstrInfo : InstrInfo;
def Magic : Target {
  let InstructionSet = MagicInstrInfo;
}