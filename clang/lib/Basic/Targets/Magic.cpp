#include "Magic.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

static constexpr Builtin::Info BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS)                                               \
  {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#include "clang/Basic/BuiltinsMagic.def"
};

void MagicTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__magic__");
}

ArrayRef<Builtin::Info> MagicTargetInfo::getTargetBuiltins() const {
      return llvm::ArrayRef(BuiltinInfo,
                        clang::Magic::LastTSBuiltin - Builtin::FirstTSBuiltin);
}